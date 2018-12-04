//
//  Controller.cpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#include "Controller.hpp"
#include "Model.hpp"
#include "View.hpp"

Controller::Controller(Model *model, View *view) {
    _model = model;
    _view = view;
}

void Controller::runGame() {
    _view->showStart();
    while (!getStart()) {
        _view->showError("Enclosure must be > 2");
        _view->showStart();
    }
    
    while (!_model->isEveryAnimalsDead()) {
        _view->showCurrentZoo(_model->enclosures, _model->enclosureCount);
        if (!getStep()) {
            exit(0);
        }
    }
}

bool Controller::getStart() {
    int enclosure;
    
    cin >> enclosure;
    if (enclosure < 3) return false;
    
    _model->setEnclosure(enclosure);
    return true;
}

bool Controller::getStep() {
    char step[256];
    
    scanf("%s", step);
    
    if (strcmp(step, "move") == 0) {
        int foodNumber;
        char foodName[256];
        int enclosureNumber;
        
        if (scanf("%d %s to %d", &foodNumber, foodName, &enclosureNumber) != 0) {
            if (!_model->addFoodToEnclosure(foodNumber, foodName, enclosureNumber)) {
                _view->showError("Wrong command");
            }
        } else {
            _view->showError("Wrong command");
        }
        //end move
        
    } else if (strcmp(step, "next") == 0) {
        string move = _model->calculations();
        _view->showMove(move);
        //end next
        
    } else if (strcmp(step, "exit") == 0) {
        return false;
        //end exit
        
    } else {
        _view->showError("Wrong command");
    }
    
    cin.getline(step, 256);
    return true;
}
