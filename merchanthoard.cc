#include "merchanthoard.h"

MerchantHoard::MerchantHoard(): Treasure("merchant hoard") {
    setValue(4);
    setPickable(true);
}

MerchantHoard::~MerchantHoard() {}
