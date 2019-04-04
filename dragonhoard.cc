#include "dragonhoard.h"

DragonHoard::DragonHoard(): Treasure("dragon hoard") {
    setValue(6);
    setPickable(false);
}

DragonHoard::~DragonHoard() {}
