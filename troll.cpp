#include "troll.h"
using namespace std;

Troll::Troll() {
	type = 'T';
	hasCompass = false;
	moveable = true;
}

int Troll::dropGold() const {
	return 1;
}

void Troll::setHostile(bool isHostile) {
	this->isHostile = isHostile;
}

bool Troll::getHostile() const {
	return this->isHostile;
}

Troll::~Troll() {}