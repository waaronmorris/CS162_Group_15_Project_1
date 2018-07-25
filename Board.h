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

    Space ***spaces;
    Critter *critters;

public:
    void setBoard(int r, int c, int start_r, int start_c, Direction d);
    void ~Board();
    void printBoard();
    void runBoard();

};


#endif //PROJECT_1_BOARD_H
