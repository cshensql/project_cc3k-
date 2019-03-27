#ifndef _BARRIERSUIT_H
#define _BARRIERSUIT_H

#include "item.h"

class BarrierSuit: public Item {
        bool pickable;
    public:
        BarrierSuit();
        ~BarrierSuit();
}

#endif //_BARRIERSUIT_H
