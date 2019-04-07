#include "human.h"
using namespace std;

Human::Human() {
    setHp(140);
    setAtk(20);
    setDef(20);
    setRace("Human");
    setMaxHp(140);
}

void Human::setDefaultAtkDef() {
    setAtk(20);
    setDef(20);
}

Human::~Human() {}

