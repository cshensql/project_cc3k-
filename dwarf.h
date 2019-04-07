#ifndef _DWARF_H
#define _DWARF_H

#include "hero.h"

class Dwarf final: public Hero {
    public:
        Dwarf();
        void setDefaultAtkDef() override;
        ~Dwarf();
};

#endif //_DWARF_H

