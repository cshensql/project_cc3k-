#ifndef _DRAGONHOARD_H
#define _DRAGONHOARD_H

#include "treasure.h"

class DragonHoard: public Treasure {
        bool pickable;
    public:
        DragonHoard();
        ~DragonHoard();
}

#endif //_DRAGONHOARD_H
