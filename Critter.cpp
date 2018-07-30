/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#include <iostream>
#include <string>
#include "Critter.h"

Critter::~Critter(){}

const std::string Critter::getSymbol() {
    return symbol;
}

void Critter::starve(){}

Space *Critter::getSpace() const {
    return space;
}

void Critter::setSpace(Space *s) {
    space->removeCritter();
    space = s;
    space->setCritter(this);
}

void Critter::removeCritter(){
    if (space != NULL){
        space->removeCritter();
    }
    space = NULL;
}

Space *Critter::getNewSpace(int direction){
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
            return NULL;
        } else if (((location.x + x_move) >= x_size ) || ((location.y + y_move) >= y_size)){
            //Move Off board right or bottom
            return NULL;
        } else {
            Space *newSpace = space->getBoard()->getSpace((location.x + x_move), (location.y + y_move));
            return newSpace;
        }
    } else {
        return NULL;
    }
}
