#include "barriersuit.h"

char BarrierSuit::GetType() const override {
    return 'B';
}

BarrierSuit::BarrierSuit():pickable {false} {}

BarrierSuit::~BarrierSuit() {}
