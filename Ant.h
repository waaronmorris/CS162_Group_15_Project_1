/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#ifndef PROJECT_ANT_H
#define PROJECT_ANT_H

#include "Critter.h"


class Ant: public Critter {
public:
    Ant(Space* s);
    void move();
    void breed();
    ~Ant();
};

#endif //PROJECT_ANT_H
