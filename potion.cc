#include "potion.h"
#include <iostream>
using namespace std;

Potion::Potion(){
    setPickable(true);
}

Potion::Potion(string potion_type): type{potion_type}{
    setPickable(true);
    if(type == "RH" || type == "PH") {
        permanentEffect = true;
    }
}

char Potion::GetType() const {
    return 'P';
}

string Potion::getType() const {
    return this->type;
}

bool Potion::getIsUsed() const {
    return isUsed;
}

void Potion::setUsed() {
    this->isUsed = true;
}

bool Potion::getPermanentEffect() const {
    return permanentEffect;
}

Potion::~Potion() {}

