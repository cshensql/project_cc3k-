#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "character.h"
#include "ConcreteCell.h"

class Character: public ConcreteCell {
protected:
    int hp;
    int atk;
    int def;
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
