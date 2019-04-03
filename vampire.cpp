#include "vampire.h"
using namespace std;

Vampire::Vampire() {
	type = 'V';
	hasCompass = false;
	moveable = true;
}

int Vampire::dropGold() const {
	return 1;
}

void Vampire::setHostile(bool isHostile) {
	this->isHostile = isHostile;
}

bool Vampire::getHostile() const{
	return this->isHostile;
}

Vampire::~Vampire() {}