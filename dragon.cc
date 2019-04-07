#include "dragon.h"
#include "dragonhoard.h"
#include "barriersuit.h"

using namespace std;

Dragon::Dragon() {
	type = 'D';
	hasCompass = false;
	moveable = false;
	setHp(150);
	setAtk(20);
	setDef(20);
}

double Dragon::dropGold() const {
	return 6;
}

void Dragon::setDragonHoard(DragonHoard *dragon_hoard) {
	dragonH = dragon_hoard;
}

void Dragon::setBarrierSuit(BarrierSuit *barrier_suit) {
	barrierS = barrier_suit;
}

DragonHoard *Dragon::getDragonHoard() const {
    return this->dragonH;   
}

BarrierSuit *Dragon::getBarrierSuit() const {
    return this->barrierS;
}

char Dragon::GetType() const {
	return 'D';
}

/*void Dragon::setHostile(bool isHostile) {
	Dragon::isHostile = isHostile;
}

bool Dragon::getHostile() const{
	return this->isHostile;
}*/

Dragon::~Dragon() {
//	delete dragonH;
//	delete barrierS;
}

