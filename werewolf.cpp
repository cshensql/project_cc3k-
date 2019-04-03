#include "werewolf.h"
using namespace std;

Werewolf::Werewolf() {
	type = 'W';
	hasCompass = false;
	moveable = true;
}

int Werewolf::dropGold() {
	return 1;
}

Werewolf::~Werewolf() {}