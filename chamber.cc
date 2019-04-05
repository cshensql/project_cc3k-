#include <iostream>
#include "chamber.h"
using namespace std;

Chamber::Chamber() = default;

Chamber::~Chamber() {}

vector<Cell> Chamber::getCells() {
    return this->cells;
}

int Chamber::getSize() {
    return this->cells.size();
}

void Chamber::addToChamber(Cell c) {
    this->cells.push_back(c);
}