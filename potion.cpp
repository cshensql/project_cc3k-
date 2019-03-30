#include "potion.h"

using namespace std;

Potion::Potion(std::string potion_type): type{potion_type} {}

string Potion::getType() const {
    return this->type;
}

void potionDrunk() {
    this->isUsed = true;
}

Potion::~Potion() {}

