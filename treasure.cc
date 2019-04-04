#include <iostream>
#include "treasure.h"

using namespace std;

Treasure::Treasure(string type): type{type}, picked{false} {}

string Treasure::getType() const {
    return type;
}

char Treasure::GetType() const {
    return 'G';
}

void Treasure::setType (std::string type) {
    this->type = type;
}

double Treasure::getValue() const{
    return value;
}

void Treasure::setValue (double amount) {
    this->value = amount;
}

bool Treasure::getState() const {
    return picked;
}

void Treasure::setState (bool picked) {
    this->picked = picked;
}

Treasure::~Treasure() {}
