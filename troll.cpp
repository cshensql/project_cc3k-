#include "troll.h"
using namespace std;

Troll::Troll() {
	type = 'T';
	hasCompass = false;
	moveable = true;
}

int Troll::dropGold() {
	return 1;
}

Troll::~Troll() {}