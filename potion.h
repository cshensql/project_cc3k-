#ifndef _POTION_H
#define _POTION_H

#include <string>
#include "item.h"

class Potion: public Item {
        std::string type;
        bool isUsed;
        bool permanentEffect;
    public:
        Potion();
        std::string getType();
        ~Potion();
}

#endif //_POTION_H
