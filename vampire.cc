#include <iostream>
#include "vampire.h"
using namespace std;

Vampire::Vampire() {
    type = 'V';
    hasCompass = false;
    moveable = true;
    setHp(50);
    setAtk(25);
    setDef(25);
}

double Vampire::dropGold() const {
    return 1;
}

/*void Vampire::setHostile(bool isHostile) {
    Vampire::isHostile = isHostile;
}

bool Vampire::getHostile() const{
    return this->isHostile;
}*/

char Vampire::GetType() const {
    return 'V';
}

Vampire::~Vampire() {}

