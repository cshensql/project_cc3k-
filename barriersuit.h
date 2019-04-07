#ifndef _BARRIERSUIT_H
#define _BARRIERSUIT_H

#include "item.h"

class BarrierSuit: public Item {
//        bool pickable;
    public:
        char GetType() const override;
        BarrierSuit();
        ~BarrierSuit();
};

#endif //_BARRIERSUIT_H

