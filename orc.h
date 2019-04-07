#ifndef _ORC_H
#define _ORC_H

#include "hero.h"

class Orc final: public Hero {
    public:
        Orc();
        void setDefaultAtkDef() override;
        ~Orc();
};

#endif //_ORC_H

