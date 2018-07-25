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

void Board::setBoard(int r, int c) {
    rows = r;
    columns = c;
    spaces = new Space **[rows];

    for (int i = 0; i<rows; i++){
        spaces[i] = new Space *[columns];
        for (int j = 0; j<columns; j++){
            spaces[i][j] = new Space;
            spaces[i][j]->setSpace(j, i, this);
        }
    }

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

    //Relying on spaces to delete all Critters; only need to delete the array.
    /*
    for (int i = 0; i<critterCount; i++){
        delete critters[i];
    }
    delete [] critters;
    */
    delete [] critters;
}

void Board::runBoard() {
    //Prints out the results of the Board.
    printBoard();
}

Space *Board::getSpace(int r, int c) {
    return spaces[r][c];
}

int Board::getRows() const {
    return rows;
}

int Board::getColumns() const {
    return columns;
}





