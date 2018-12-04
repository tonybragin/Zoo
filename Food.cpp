//
//  Food.cpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#include "Food.hpp"

Food *Food::createFood(string foodName) {
    Food *p;
    
    if (foodName.compare("meat") == 0) {
        p = new Meat();
    } else if (foodName.compare("hay") == 0) {
        p = new Hay();
    } else if (foodName.compare("fruit") == 0) {
        p = new Fruit();
    } else {
        p = NULL;
    }
    
    return p;
}

string Meat::getName() {
    return "meat";
}

string Hay::getName() {
    return "hay";
}

string Fruit::getName() {
    return "fruit";
}
