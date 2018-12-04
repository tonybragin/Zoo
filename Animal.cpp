//
//  Animal.cpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#include "Animal.hpp"
#include "Food.hpp"

Animal *Animal::createAnimal(Animals id, Food *eat, int min_food) {
    Animal *p;
    
    switch (id) {
        case lion:
            p = new Lion();
            p->name = "Lion";
            break;
            
        case cow:
            p = new Cow();
            p->name = "Cow";
            break;
        
        case monkey:
            p = new Monkey();
            p->name = "Monkey";
            break;
            
        default:
            exit(0);
    }
    
    p->eat = eat;
    p->min_food = min_food;
    
    return p;
}

bool Lion::isAnimalEatThat(Food *food) {
    return food->getName().compare("meat") == 0 ? true : false;
}

bool Cow::isAnimalEatThat(Food *food) {
    return food->getName().compare("hay") == 0 ? true : false;
}

bool Monkey::isAnimalEatThat(Food *food) {
    return food->getName().compare("fruit") == 0 ? true : false;
}
