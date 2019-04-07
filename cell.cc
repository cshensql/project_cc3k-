#include <iostream>
#include "cell.h"
#include "ConcreteCell.h"
using namespace std;

Cell::Cell() {}

Cell::Cell(char type, int x, int y): type{type}, BasicCell(x, y) {}

Cell::~Cell() {}

bool Cell::isOccupied() {
    return this->type != '.' || this->GetConcreteCell() != nullptr;
}

bool Cell::canMove() {
    ConcreteCell *conc = this->GetConcreteCell();
    return ((type == '.') || (type == '+') || (type == '#') || (type == '\\')) &&
           (conc == nullptr || conc->GetType() == 'G' || conc->GetType() == 'B' || conc->GetType() == 'C');
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

