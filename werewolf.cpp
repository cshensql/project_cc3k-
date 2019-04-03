#include "werewolf.h"
using namespace std;

Werewolf::Werewolf() {
	type = 'W';
	hasCompass = false;
	moveable = true;
}

int Werewolf::dropGold() const {
	return 1;
}

void Werewolf::setHostile(bool isHostile) {
	this->isHostile = isHostile;
}

bool Werewolf::getHostile() const{
	return this->isHostile;
}

Werewolf::~Werewolf() {}