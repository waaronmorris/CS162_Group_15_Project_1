/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#ifndef PROJECT_CRITTER_H
#define PROJECT_CRITTER_H

#include <string>
#include "Space.h"


class Critter {
private:
    std::string symbol=0;
public:
    const std::string getSymbol();
    virtual void move()=0;
    virtual void breed()=0;
};


#endif //PROJECT_CRITTER_H
