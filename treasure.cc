#include "treasure.h"

std::string Treasure::getType() const{
    return type;
}

char Treasure::GetType() const override{
    return 'G';
}

void Treasure::setType (std::string typename) {
    type = typename;
}

int Treasure::getValue() const{
    return value;
}

void Treasure::setValue (int amount) {
    value = amount;
}

bool Treasure::getState() const {
    return picked;
}

void Treasure::setState (bool picked) {
    this->picked = picked;
}

virtual Treasure::~Treasure() {}
