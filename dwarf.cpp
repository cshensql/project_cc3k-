#include "dwarf.h"

using namespace std;

Dwarf::Dwarf() {
    setHp(100);
    setAtk(20);
    setDef(30);
    setRace("Dwarf");
    setMaxHp(100);
}

void Dwarf::setDefaultAtkDef() {
    setAtk(20);
    setDef(30);
}

Dwarf::~Dwarf() {}
