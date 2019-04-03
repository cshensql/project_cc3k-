#ifndef _WEREWOLF_H
#define _WEREWOLF_H

#include "enemy.h"
#include "hero.h"

class Werewolf final: public Enemy {
    public:
        Werewolf();
        const int dropGold() override;
        ~Werewolf();
};

#endif //_WEREWOLF_H
