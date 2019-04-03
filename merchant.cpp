#include "merchant.h"
#include "merchanthoard.h"
using namespace std;

Merchant::Merchant() {
	type = 'M';
	hasCompass = false;
	moveable = true;
	isHostile = false;
}

int Merchant::dropGold() {
	MerchantHoard merchant_hoard;
	Cell *current_cell = GetCell();
	current_cell->deleteConcrete();
	current_cell->SetConcreteCell(merchant_hoard);
	return 4;
}

Merchant::~Merchant() {}