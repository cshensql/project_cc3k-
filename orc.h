#ifndef _ORC_H
#define _ORC_H

#include "hero.h"
#include "enemy.h"

class Orc final: public Hero {
    public:
        Orc();
        void attack(Enemy *enemy) override;
        void attackedByEnemy(Enemy *enemy) override;
        ~Orc();
};

#endif //_ORC_H
