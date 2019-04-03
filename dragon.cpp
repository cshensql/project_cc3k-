# include "dragon.h"
using namespace std;

Dragon::Dragon() {}

int dropGold() const {
	return 6;
}

void Dragon::setDragonHoard(DragonHoard *dragon_hoard) {
	dragonH = dragon_hoard;
}

void Dragon::setBarrierSuit(BarrierSuit *barrier_suit) {
	barrierS = barrier_suit;
}

Dragon::~Dragon() {
	delete dragonH;
	delete barrierS;
}

