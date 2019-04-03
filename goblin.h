#ifndef _GOBLIN_H
#define _GOBLIN_H

#include "enemy.h"
#include "hero.h"

class Goblin final: public Enemy {
    public:
        Goblin();
        const int dropGold() override;
        ~Goblin();
};

#endif //_GOBLIN_H
