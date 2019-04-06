#include <iostream>
#include "cell.h"
using namespace std;

Cell::Cell() {}

Cell::Cell(char type, int x, int y): type{type}, BasicCell(x, y) {}

Cell::~Cell() {}

bool Cell::isOccupied() {
    return this->type != '.' || this->GetConcreteCell() != nullptr;
}

bool Cell::canMove() {
    return (type == '.') || (type == '+') || (type == '#') || (type == '\\');
}

bool Cell::isStair() {
    return type == '\\';
}


void Cell::setCell(char type) {
    this->type = type;
}


char Cell::getCellType() {
    return this->type;
}

void Cell::deleteConcrete() {
    this->Concretecell = nullptr;
}

void Cell::SetConcreteCell(ConcreteCell *cCell) {
    this->Concretecell = cCell;
}

ConcreteCell* Cell::GetConcreteCell() {
    return this->Concretecell;
}
