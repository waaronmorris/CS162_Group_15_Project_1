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
    setSpace(s);
}

void Ant::move() {
    Position location = space->getPosition();
    int x_size = space->getBoard()->getRows();
    int y_size = space->getBoard()->getColumns();

    int x_move=0;
    int y_move=0;
    int dir = (rand() % 4);

    if (dir < 1){
        y_move++;
    }else if (dir < 2){
        x_move++;
    }else if (dir < 3){
        y_move--;
    }else if (dir < 4){
        x_move--;
    }

    if (((location.x + x_move) < 0) || ((location.y + y_move) < 0)){
        //Move Off board left or up
        std::cout << "Move off Board: Ant did not move" << std::endl;
    } else if (((location.x + x_move) >= x_size ) || ((location.y + y_move) >= y_size)){
        //Move Off board right or bottom
        std::cout << "Move off Board: Ant did not move" << std::endl;
    } else {
        Space *new_space = space->getBoard()->getSpace((location.x + x_move), (location.y + y_move));
        if (new_space->isOccupied()){
            //Move Off board right or bottom
            std::cout << "Space is occupied" << std::endl;
        } else {
            setSpace(space);
        }
    }
}
