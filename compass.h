#ifndef _COMPASS_H
#define _COMPASS_H

#include "item.h"
#include "enemy.h"

class Compass: public Item {
        Enemy *holder;
    public:
        Compass();
        void setHolder(Enemy *enemy_holder);
        ~Compass();
};

#endif //_COMPASS_H
