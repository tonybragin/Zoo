//
//  Food.hpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#ifndef Food_hpp
#define Food_hpp

#include "Header.h"

class Food {
public:
    static Food *createFood(string foodName);
    virtual string getName() = 0;
    
    virtual ~Food(){}
};

class Meat: public Food {
    string getName();
};

class Hay: public Food {
    string getName();
};

class Fruit: public Food {
    string getName();
};

#endif /* Food_hpp */
