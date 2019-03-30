#include "ConcreteCell.h"

/*
class ConcreteCell: public BasicCell{
protected:
    char Type;  // Used to hold the character to represent everything on the map
    // @ for Hero, P for the Potions and etc..
    Cell* c;
public:
    ConcreteCell();
    ~ConcreteCell();
    void SetCell(Cell* cell);
    Cell* GetCell();
    virtual char GetType();
};
 */

ConcreteCell::ConcreteCell() = default;

ConcreteCell::~ConcreteCell() {
    this->c = nullptr;
}

void ConcreteCell::SetCell(Cell *cell) {
    this->c = cell;
}

char ConcreteCell::GetType() {
    return this->Type;
}

Cell* ConcreteCell::GetCell() {
    return this->c;
}