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
        char GetType() const override;
        std::string getType() const;
        bool getIsUsed() const;
        void setUsed();
        bool getPermanentEffect() const;
        ~Potion();
};

#endif //_POTION_H
