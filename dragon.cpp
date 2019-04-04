#include <iostream>
# include "dragon.h"
using namespace std;

Dragon::Dragon() {}

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

void Dragon::setHostile(bool isHostile) {
	this->isHostile = isHostile;
}

bool Dragon::getHostile() const{
	return this->isHostile;
}

char Dragon::GetType() const {
	return 'D';
}

Dragon::~Dragon() {
	delete dragonH;
	delete barrierS;
}

