#include <iostream>
#include "item.h"

using namespace std;

bool Item::isPickable() const {
    return this->pickable;
}

void Item::setPickable(bool pickable) {
    this->pickable = pickable;
}
