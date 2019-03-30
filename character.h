#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "cell.h"

class Character: {
protected:
    int hp;
    int atk;
    int def;
    Cell *cell = nullptr;
public:
    virtual ~Character() = 0;
    int getHp() const;
    int getAtk() const;
    int getDef() const;
    void setHp(int Hp);
    void setAtk(int Atk);
    void setDef(int Def);
    bool isAlive() const;
};

#endif //_CHARACTER_H
