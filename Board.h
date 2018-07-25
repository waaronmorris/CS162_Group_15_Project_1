/*********************************************************************
** Program name: Langston Ants
** Author:
** Date:
** Description: A space for keeping track of all the items on a Langston board
 * (i.e. an Ant and Spaces).
*********************************************************************/

#ifndef PROJECT_1_BOARD_H
#define PROJECT_1_BOARD_H


#include "Space.h"
#include "Ant.h"

class Board {
private:
    int rows;
    int columns;
    int critterCount;

    Space ***spaces;
    Critter **critters;

public:
    void setBoard(int r, int c);
    Space *getSpace(int r, int c);
    void ~Board();
    void printBoard();
    void runBoard();

};


#endif //PROJECT_1_BOARD_H
