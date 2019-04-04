#include <iostream>
#include "potion.h"

using namespace std;

Potion::Potion() {
    setPickable(true);
}

Potion::Potion(string potion_type): type{potion_type} {
    setPickable(true);
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

