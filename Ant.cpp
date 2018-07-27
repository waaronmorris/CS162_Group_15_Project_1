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

Space *Ant::getNewSpace(int direction, bool &validSpace){
    validSpace = false;
    if (space != NULL) {
        Position location = space->getPosition();
        int x_size = space->getBoard()->getRows();
        int y_size = space->getBoard()->getColumns();

        int x_move=0;
        int y_move=0;

        if (direction < 1){
            y_move++;
        }else if (direction < 2){
            x_move++;
        }else if (direction < 3){
            y_move--;
        }else if (direction < 4){
            x_move--;
        }

        if (((location.x + x_move) < 0) || ((location.y + y_move) < 0)){
            //Move Off board left or up
            return nullptr;
        } else if (((location.x + x_move) >= x_size ) || ((location.y + y_move) >= y_size)){
            //Move Off board right or bottom
            return nullptr;
        } else {
            Space *new_space = space->getBoard()->getSpace((location.x + x_move), (location.y + y_move));
            if (new_space->isOccupied()){
                //Space is occupied
                return nullptr;
            } else {
                validSpace = true;
                return new_space;
            }
        }
    } else {
        return nullptr;
    }

}

void Ant::move() {
    bool validSpace = false;
    int direction = (rand() % 4);

    Space *newSpace = getNewSpace(direction, validSpace);
    if (validSpace){
        setSpace(newSpace);
    }
}

void Ant::breed() {
    //Use the board generate method to creat a new Critter.
    Space *newSpace;
    bool validSpace = false;
    int direction = 0;

    do{
        newSpace = getNewSpace(direction, validSpace);
        direction++;
    } while (!validSpace);

    space->getBoard()->createCritter("Ant", newSpace->getPosition().x, newSpace->getPosition().y);
}

Ant::~Ant() {}
