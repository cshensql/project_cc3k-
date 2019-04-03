#include "vampire.h"
using namespace std;

Vampire::Vampire() {
	type = 'V';
	hasCompass = false;
	moveable = true;
}

int Vampire::dropGold() {
	return 1;
}

Vampire::~Vampire() {}