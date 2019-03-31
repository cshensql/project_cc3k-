#ifndef _ITEM_H
#define _ITEM_H

#include "item.h"
#include "ConcreteCell.h"
#include "Floor.h"

class Item: public ConcreteCell {    
     public:
        virtual ~Item() = 0;
};

#endif //_ITEM_H
