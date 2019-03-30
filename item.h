#ifndef _ITEM_H
#define _ITEM_H

#include "cell.h"
#include "floor.h"

class Item: public Cell {
    Floor *floor = nullptr;
    public:
        void setFloor(Floor *floor);
        ~Item();
};

#endif //_ITEM_H
