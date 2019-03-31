#include "compass.h"

Compass::Compass():holder{nullptr} {}

void Compass::setHolder (Enemy *enemy_holder) {
    holder = enemy_holder;
}

char Compass::GetType() const override {
    return 'C';
}

Compass::~Compass() {
    delete holder;
}
