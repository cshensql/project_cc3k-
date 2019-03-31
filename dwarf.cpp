#include "dwarf.h"

using namespace std;

Dwarf::Dwarf() {
    hp = 100;
    atk = 20;
    def = 30;
    maxHp = 100;
    race = "Dwarf";
    goldNum = 0;
    hasBarrier = false;
}

Dwarf::~Dwarf() {}
