#include <iostream>
#include "cell.h"
using namespace std;

Cell::Cell() {}

Cell::Cell(char type, int x, int y): type{type}, x{x}, y{y} {}

Cell::~Cell() {}

bool Cell::isOccupied() {
    return this->type != '.';
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

void Cell::setIndex(int x, int y) {
    this->x = x;
    this->y = y;
}

char Cell::getCellType() {
    return this->type;
}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}