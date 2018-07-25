/*********************************************************************
** Program name:
** Author:
** Date:
** Description: Implementation for Langston Board.
*********************************************************************/

#include "Board.h"
#include "Ant.h"
#include "Space.h"

#include <iostream>

void Board::printBoard() {
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            std::cout << spaces[i][j]->getSymbol();
        }
        std::cout << std::endl;
    }
}

void Board::setBoard(int r, int c, int start_r, int start_c, Direction d) {
    rows = r;
    columns = c;
    spaces = new Space **[rows];

    for (int i = 0; i<rows; i++){
        spaces[i] = new Space *[columns];
        for (int j = 0; j<columns; j++){
            spaces[i][j] = new Space;
            spaces[i][j]->setSpace(j,i);
        }
    }

    //Set to zero base
    start_r = start_r - 1;
    start_c = start_c - 1;


    //Initialize all Critters
}

Board::~Board() {
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            delete spaces[i][j];
        }
        delete [] spaces[i];
    }
    delete [] spaces;
    delete ant;
}

void Board::runBoard() {

    //Prints out the results of the Board.
    printBoard();
}



