#ifndef _ITEM_H
#define _ITEM_H

#include "ConcreteCell.h"

class Item: public ConcreteCell {
protected:
        bool pickable;
    public:
        bool isPickable() const;
        void setPickable(bool pickable);
        Item();
        ~Item();
};

#endif //_ITEM_H
