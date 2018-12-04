//
//  Model.hpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include "Header.h"
#include "Animal.hpp"
#include "Enclosure.hpp"
#include "Food.hpp"

class Model {
public:
    friend Controller;
    Model();
    
private:
    const int animalCount = 3;
    const int foodCount = 3;
    int enclosureCount;
    Animal **animals;
    Food **foods;
    Enclosure *enclosures;
    
    void setEnclosure(int enclosure);
    bool isEveryAnimalsDead();
    bool addFoodToEnclosure(int foodNumber, string foodName, int enclosureNumber);
    string calculations();
};

#endif /* Model_hpp */
