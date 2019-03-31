#include "treasure.h"

std::string Treasure::getType const(){
    return type;
}

void Treasure::setType (std::string typename) {
    type = typename;
}

int Treasure::getValue const() {
    return value;
}

void Treasure::setValue (int amount) {
    value = amount;
}

bool Treasure::getState () {
    return picked;
}

void Treasure::setState (bool picked) {
    this.picked = picked;
}

virtual Treasure::~Treasure() {}
