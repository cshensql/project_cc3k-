#include "orc.h"

using namespace std;

Orc::Orc() {
    setHp(180);
    setAtk(30);
    setDef(25);
    setRace("Orc");
    setMaxHp(180);
}

void Orc::setDefaultAtkDef() {
    setAtk(30);
    setDef(25);
}

Orc::~Orc() {}
