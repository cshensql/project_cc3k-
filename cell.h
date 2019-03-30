#ifndef _CELL_H
#define _CELL_H


//class Character;
//class Item;
#include "BasicCell.h"
class ConcreteCell;

class Cell: public BasicCell{
protected:
    char type;
    ConcreteCell* Concretecell;
public:
    Cell();
    Cell(char type, int x, int y);
    ~Cell();
    bool isOccupied();
    bool canMove();
    bool isStair();
    void setCell(char type);
    char getCellType();

    ConcreteCell* GetConcreteCell();

    void SetConcreteCell(ConcreteCell* cCell);

};
#endif //_CELL_H
