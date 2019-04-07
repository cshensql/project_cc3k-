#ifndef CONCRETECELL_H
#define CONCRETECELL_H

#include "BasicCell.h"
class Cell;

class ConcreteCell: public BasicCell{
protected:
    char Type;  // Used to hold the character to represent everything on the map
    // @ for Hero, P for the Potions and etc..
    Cell* c;
public:
    ConcreteCell();
    ~ConcreteCell();
    void SetCell(Cell* cell);
    Cell* GetCell() const;
    virtual char GetType() const;
};

#endif

