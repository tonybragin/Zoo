//
//  Enclosure.cpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#include "Enclosure.hpp"
#include "Food.hpp"

void Enclosure::initEnclosure(int number, Animal *animal, int quantity, Food **food, int foodCount) {
    this->number = number;
    this->animal = animal;
    this->quantity = quantity;
    
    for (int i = 0; i < foodCount; i++) {
        foodsInEnclosure.insert(pair<Food*, int>(food[i], 0));
    }
}

void Enclosure::foodIsGone() {
    for (map<Food*, int>::iterator it = foodsInEnclosure.begin(); it != foodsInEnclosure.end(); it++) {
        it->second = 0;
    }
}

string Enclosure::getInfoString() {
    ostringstream info;
    
    if (this->quantity > 0) {
        info << "Enclosure " << this->number << ": " << this->animal->name << ". Quantity: " << this->quantity << ". Eat: " << this->animal->eat->getName() << ". Food: ";
        info << this->getFoodLine();
        info << ".\n";
    }
    
    return info.str();
}

string Enclosure::getFoodLine() {
    ostringstream line;
    
    int f = 0;
    for (map<Food*, int>::iterator it = foodsInEnclosure.begin(); it != foodsInEnclosure.end(); it++) {
        if (it->second > 0) {
            if (f == 1) {
                line << ", ";
            }
            line << it->second << " " << it->first->getName();
            f = 1;
        }
    }
    if (f == 0) {
        line << "no";
    }
    
    return line.str();
}

bool Enclosure::isOversupply(map<Food*, int>::iterator indexOfRightFood) {
    return indexOfRightFood->second > this->animal->min_food * this->quantity ? true : false;
}

string Enclosure::calculationsInEnclosure(map<Food*, int>::iterator indexOfRightFood) {
    ostringstream move;
    
    if (!this->isOversupply(indexOfRightFood)) {
        
        int animalsAte = indexOfRightFood->second / this->animal->min_food;
        if (this->quantity != animalsAte) {
            int animalsDied = this->quantity - animalsAte;
            this->quantity -= animalsDied;
            move << animalsDied << " " << this->animal->name << " starved to death.\n";
        }
        
    } else {
        int leftovers = indexOfRightFood->second - this->animal->min_food * this->quantity;
        
        int numberOfAnimalsThatCanGiveBirth = leftovers / (this->animal->min_food * 2);
        
        int numberOfBirths = 0;
        for (int b = 0; b < numberOfAnimalsThatCanGiveBirth; b++) {
            if ((rand() % 100) >= 70) {
                numberOfBirths++;
            }
        }
        
        if (numberOfBirths > 0) {
            this->quantity += numberOfBirths;
            move << numberOfBirths << " " << this->animal->name << " spawned in Enclosure " << this->number << ".\n";
        }
    }
    
    return move.str();
}

string Enclosure::everyAnimalsIsDeadInEnclosure() {
    ostringstream move;
    
    if (this->quantity > 0) {
        move << this->quantity << " " << this->animal->name << " starved to death.\n";
        this->quantity = 0;
    }
    
    return move.str();
}
