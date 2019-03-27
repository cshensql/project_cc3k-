#ifndef _DWARF_H
#define _DWARF_H

#include "hero.h"
#include "enemy.h"

class Dwarf final: public Hero {
    public:
        Dwarf();
        void attack(Enemy *enemy) override;
        void attackedByEnemy(Enemy *enemy) override;
        ~Dwarf();
}

#endif //_DWARF_H
