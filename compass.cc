#include "compass.h"

Compass::Compass():holder{nullptr} {}

void Compass::setHolder (Enemy *enemy_holder) {
    holder = enemy_holder;
}

Compass::~Compass() {
    delete holder;
}
