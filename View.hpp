//
//  View.hpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include "Header.h"
#include "Enclosure.hpp"
#include "Food.hpp"

class View {
public:
    friend Controller;
    
private:
    void showStart();
    void showError(string message);
    void showCurrentZoo(Enclosure *enclosures, int enclosureCount);
    void showMove(string message);
};

#endif /* View_hpp */
