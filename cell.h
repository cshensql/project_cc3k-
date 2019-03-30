#ifndef _CELL_H
#define _CELL_H

class Character;
class Item;

class Cell {
protected:
    Character *character = nullptr;
    Item *item = nullptr;
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
    void setCharacter(Character *character);
    void setItem(Item *item);
    void setCell(char type);
    void setIndex(int x, int y);
    char getCellType();
    int getX();
    int getY();
};
#endif //_CELL_H
