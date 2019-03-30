#ifndef _CELL_H
#define _CELL_H

class Character;
class Item;

class Cell {
protected:
    char type;
    int x;
    int y;
public:
    Cell();
    Cell(char type, int x, int y);
    ~Cell();
    bool isOccupied();
    bool canMove();
    bool isStair(); 
    void setCell(char type);
    void setIndex(int x, int y);
    char getCellType();
    int getX();
    int getY();
};
#endif //_CELL_H
