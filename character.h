#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "cell.h"

class Character: public Cell {
protected:
    int hp;
    int atk;
    int def;
public:
    int getHp();
    int getMaxHp();
    int getAtk();
    int getDef();
    void setHp();
    void setAtk();
    void setDef();
    bool isAlive();
};

#endif //_CHARACTER_H
