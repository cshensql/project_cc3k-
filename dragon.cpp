# include "dragon.h"
using namespace std;

Dragon::Dragon() {}

int Dragon::dropGold() const {
	return 6;
}

void Dragon::setDragonHoard(DragonHoard *dragon_hoard) {
	dragonH = dragon_hoard;
}

void Dragon::setBarrierSuit(BarrierSuit *barrier_suit) {
	barrierS = barrier_suit;
}

void Dragon::setHostile(bool isHostile) {
	this->isHostile = isHostile;
}

bool Dragon::getHostile() const{
	return this->isHostile;
}

Dragon::~Dragon() {
	delete dragonH;
	delete barrierS;
}

