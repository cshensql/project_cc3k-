#include "merchant.h"
#include "merchanthoard.h"
#include "cell.h"
using namespace std;

Merchant::Merchant() {
	type = 'M';
	hasCompass = false;
	moveable = true;
	isHostile = false;
}

double Merchant::dropGold() const {
	MerchantHoard *merchant_hoard {};
	Cell *current_cell = GetCell();
	current_cell->deleteConcrete();
	current_cell->SetConcreteCell(merchant_hoard);
	return 4;
}

void Merchant::setHostile(bool isHostile) {
	this->isHostile = isHostile;
}

bool Merchant::getHostile() const{
	return this->isHostile;
}

char Merchant::GetType() const {
	return 'M';
}

Merchant::~Merchant() {}
