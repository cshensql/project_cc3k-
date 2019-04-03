#include <iostream>
#include "treasure.h"
#include "normal.h"
#include "small.h"
#include "merchanthoard.h"
#include "dragonhoard.h"
using namespace std;

Treasure::Treasure(string type): type{type}, picked{false} {}

string Treasure::getType() const{
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
