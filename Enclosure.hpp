//
//  Enclosure.hpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#ifndef Enclosure_hpp
#define Enclosure_hpp

#include "Header.h"
#include "Animal.hpp"
#include "Food.hpp"

class Enclosure {
public:
    int number;
    Animal *animal;
    int quantity;
    map<Food*, int> foodsInEnclosure;
    
    void initEnclosure(int number, Animal *animal, int quantity, Food **food, int foodCount);
    string getInfoString();
    string getFoodLine();
    void foodIsGone();
    bool isOversupply(map<Food*, int>::iterator indexOfRightFood);
    string calculationsInEnclosure(map<Food*, int>::iterator indexOfRightFood);
    string everyAnimalsIsDeadInEnclosure();
};

#endif /* Enclosure_hpp */
