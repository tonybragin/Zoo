//
//  View.cpp
//  Zoo
//
//  Created by TONY on 21/11/2018.
//  Copyright © 2018 TONY COMPANY. All rights reserved.
//

#include "View.hpp"

void View::showStart() {
    cout << "Write count of enclosure (must be > 2): " << endl;
}

void View::showError(string message) {
    cout << "\n!!Error: " << message << "!!\n" << endl;
}

void View::showCurrentZoo(Enclosure *enclosures, int enclosureCount) {
    for (int i = 0; i < enclosureCount; i++) {
        cout << enclosures[i].getInfoString();
    }
}

void View::showMove(string message) {
    cout << message << endl;
}
