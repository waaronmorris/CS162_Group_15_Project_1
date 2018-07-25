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
    for (int i = 0; i < 5; i++){
        gameBoard->createCritter("Ant", i, i);
    }
    gameBoard->printBoard();
    delete gameBoard;
    return 0;
}