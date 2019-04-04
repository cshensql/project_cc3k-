#ifndef _HUMAN_H
#define _HUMAN_H

#include "hero.h"

class Human final: public Hero {
    public:
        Human();
        void setDefaultAtkDef() override;
        ~Human();
};

#endif //_HUMAN_H
