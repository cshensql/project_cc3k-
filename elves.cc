#include "elves.h"

using namespace std;

Elves::Elves() {
    setHp(140);
    setAtk(30);
    setDef(10);
    setRace("Elves");
    setMaxHp(140);
}

void Elves::setDefaultAtkDef() {
    setAtk(30);
    setDef(10);
}

Elves::~Elves() {}

