#include "barriersuit.h"

char BarrierSuit::GetType() const {
    return 'B';
}

BarrierSuit::BarrierSuit() {
    setPickable(false);
}

BarrierSuit::~BarrierSuit() {}
