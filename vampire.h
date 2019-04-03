#ifndef _VAMPIRE_H
#define _VAMPIRE_H

#include "enemy.h"
#include "hero.h"

class Vampire final: public Enemy {
    public:
        Vampire();
        int dropGold() const override;
        ~Vampire();
};

#endif //_VAMPIRE_H
