//
//  Animal.hpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp

#include "Header.h"
#include "Food.hpp"

enum Animals { lion = 0, cow, monkey };

class Animal {
public:
    string name;
    Food *eat;
    int min_food;
    
    static Animal *createAnimal(Animals id, Food *eat, int min_food);
    virtual bool isAnimalEatThat(Food *food) = 0;
    
    virtual ~Animal(){}
};

class Lion: public Animal {
    bool isAnimalEatThat(Food *food);
};

class Cow: public Animal {
    bool isAnimalEatThat(Food *food);
};

class Monkey: public Animal {
    bool isAnimalEatThat(Food *food);
};


#endif /* Animal_hpp */
