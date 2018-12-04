//
//  main.cpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#include "Header.h"
#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"

int main(int argc, const char * argv[]) {
    
    random_device rand;
    Model zModel;
    View zView;
    Controller zController(&zModel, &zView);
    
    zController.runGame();
    
    return 0;
}
