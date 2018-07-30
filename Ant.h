/*********************************************************************
** Program name: Ant Class
** Author: Group 15
** Date:
** Description: A class for Ants
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
