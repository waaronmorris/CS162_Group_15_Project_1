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
protected:
    std::string symbol=0;
    Space *space;
public:
    //required functions
    virtual void move()=0;
    virtual void breed()=0;

    //Function to assist Space and Board
    const std::string getSymbol();
    Space *getSpace() const;
    void setSpace(Space *space);
};


#endif //PROJECT_CRITTER_H
