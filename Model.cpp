//
//  Model.cpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#include "Model.hpp"

Model::Model() {
    
    foods[0] = Food::createFood("meat");
    foods[1] = Food::createFood("hay");
    foods[2] = Food::createFood("fruit");
    
    animals[0] = Animal::createAnimal(lion, foods[0], 4);
    animals[1] = Animal::createAnimal(cow, foods[1], 4);
    animals[2] = Animal::createAnimal(monkey, foods[2], 3);
}


void Model::setEnclosure(int enclosure) {
    enclosureCount = enclosure;
    
    this->enclosures = new Enclosure[this->enclosureCount];
    for (int i = 0; i < enclosure; i++) {
        this->enclosures[i].initEnclosure(i, animals[rand() % animalCount], (rand() % 13) + 1, foods, foodCount);
    }
}

bool Model::isEveryAnimalsDead() {
    int f = 0;
    for (int i = 0; i < enclosureCount; i++) {
        if (enclosures[i].quantity > 0) {
            f = 1;
        }
    }
    
    if (f == 0) {
        return true;
    } else {
        return  false;
    }
}

bool Model::addFoodToEnclosure(int foodNumber, string foodName, int enclosureNumber) {
    if (enclosureNumber < this->enclosureCount && enclosureNumber >= 0) {
        for (map<Food*,int>::iterator it = enclosures[enclosureNumber].foodsInEnclosure.begin(); it != enclosures[enclosureNumber].foodsInEnclosure.end(); it++) {
            if (it->first->getName().compare(foodName) == 0) {
                it->second += foodNumber;
                return true;
            }
        }
    }
    return false;
}

string Model::calculations() {
    ostringstream move;
    
    for (int i = 0; i < enclosureCount; i++) {
        for (map<Food*, int>::iterator it = enclosures[i].foodsInEnclosure.begin(); it != enclosures[i].foodsInEnclosure.end(); it++) {
            if (enclosures[i].animal->isAnimalEatThat(it->first)) {
                move << enclosures[i].calculationsInEnclosure(it);
            }
        }
    }
    
    for (int i = 0; i < enclosureCount; i++) {
        enclosures[i].foodIsGone();
    }
    
    return move.str();
}
