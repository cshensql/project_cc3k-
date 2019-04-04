#include "barriersuit.h"

char BarrierSuit::GetType() const {
    return 'B';
}

BarrierSuit::BarrierSuit():pickable {false} {}

BarrierSuit::~BarrierSuit() {}
