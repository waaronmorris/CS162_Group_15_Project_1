/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#include <iostream>
#include "Board.h"

int main() {
    Board *gameBoard = new Board();
    gameBoard->setBoard(20, 20);
    //Create Ant
    for (int i = 0; i < 5; i++){
        gameBoard->createCritter("Ant", i, i);
    }

    gameBoard->runBoard();
    delete gameBoard;
    return 0;
}