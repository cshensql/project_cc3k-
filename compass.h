#ifndef _COMPASS_H
#define _COMPASS_H

#include "item.h"
//#include "enemy.h"

class Enemy;

class Compass: public Item {
        Enemy *holder;
    public:
        char GetType() const override;
        Compass();
        void setHolder(Enemy *enemy_holder);
        ~Compass();
};

#endif //_COMPASS_H

