#ifndef _ITEM_H
#define _ITEM_H

#include "ConcreteCell.h"

class Item: public ConcreteCell {    
    public:
        virtual ~Item() = 0;
};

#endif //_ITEM_H
