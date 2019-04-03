#include "dragonhoard.h"

DragonHoard::DragonHoard(): Treasure("dragon hoard") {
    pickable = false;
    setValue(6);
}

DragonHoard::~DragonHoard() {}
