/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#include "Ant.h"
#include "Space.h"
#include <iostream>

Ant::Ant(Space* s){
    symbol = "O";
    space = s;
    s->setCritter(this);
}

void Ant::move() {
    int direction = (rand() % 4);

    Space *newSpace = getNewSpace(direction);
    if (newSpace != NULL){
        if (!newSpace->isOccupied()){
            setSpace(newSpace);
        }
    }
}

void Ant::breed() {
    //Use the board generate method to creat a new Critter.
    Space *newSpace;
    bool validSpace = false;
    int direction = 0;

    do{
        newSpace = getNewSpace(direction);
        direction++;
        if (newSpace != nullptr || direction >= 3){
            validSpace = true;
        }
    } while (!validSpace);

    if (newSpace != nullptr){
        space->getBoard()->createCritter("Ant", newSpace->getPosition().x, newSpace->getPosition().y);
    }
}

Ant::~Ant() {}
