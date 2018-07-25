/*********************************************************************
** Program name:
** Author:
** Date:
** Description: Implementation for Langston Board.
*********************************************************************/

#include "Board.h"
#include "Ant.h"
#include "DoodleBug.h"
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
    //Initialize all Critters at Random Locations
    int x_rand = rand() % rows;
    int y_rand = rand() % columns;
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
    for (int j = 0; j<critterCount; j++){
        delete critters[j];
    }
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

void Board::createCritter(std::string type, int x_start, int y_start) {
    extendCritterSlots();
    if(type == "Ant"){
        critters[critterCount] = new Ant(spaces[x_start][y_start]);
    } else if ( type == "Doodlebug"){
        //critters[critterCount] = new DoodleBug();
    }

    critterCount++;

}

void Board::extendCritterSlots(){
    int slotSize;
    slotSize = critterCount + 1;
    Critter **newSlots =  new Critter *[slotSize];
    for(int i = 0; i < critterCount; i++) {
        newSlots[i] =  critters[i];
    }

    delete [] critters; // Free the array.


    critters = newSlots;
}





