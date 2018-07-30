/*********************************************************************
** Program name: Doodlebug Class
** Author: Group 15
** Date: 7/29/18
** Description: A class for Doodlebug
*********************************************************************/
#ifndef PROJECT_DOODLEBUG_H
#define PROJECT_DOODLEBUG_H

#include "Critter.h"
#include "Ant.h"

class DoodleBug: public Critter{
private:
    int daysNotEaten;
public:
    DoodleBug(Space* s);
    void move();
    void breed();
    void starve();
    void eatAnt(Ant *eatenAnt);

    virtual ~DoodleBug();

};


#endif //PROJECT_DOODLEBUG_H
