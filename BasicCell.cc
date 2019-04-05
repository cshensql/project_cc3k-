#include "BasicCell.h"

int BasicCell::getX() {
    return this->x;
}

int BasicCell::getY() {
    return this->y;
}

void BasicCell::setX(int x) {
    this->x = x;
}

void BasicCell::setY(int y) {
    this->y = y;
}

BasicCell::BasicCell() = default;

BasicCell::~BasicCell() = default;

BasicCell::BasicCell(int x, int y):x{x}, y{y} {}
