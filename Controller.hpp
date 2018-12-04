//
//  Controller.hpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "Header.h"

class Controller {
public:
    
    Controller(Model *, View *);
    void runGame();
    
private:
    bool getStart();
    bool getStep();
    
    Model *_model;
    View *_view;
};

#endif /* Controller_hpp */
