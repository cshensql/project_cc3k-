#ifndef _POTION_H
#define _POTION_H

#include <string>
#include "item.h"

class Potion: public Item {
        std::string type;
        bool isUsed = false;
        bool permanentEffect = false;
    public:
        Potion();
        std::string getType() const;
        void potionDrunk();
        ~Potion();
};

#endif //_POTION_H
