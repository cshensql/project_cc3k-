#ifndef _ELVES_H
#define _ELVES_H

#include "hero.h"
#include "enemy.h"

class Elves final: public Hero {
    public:
        Elves();
        void setDefaultAtkDef() override;
        ~Elves();
};

#endif //_ELVES_H
