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
    critterCount["Ant"]=0;
    critterCount["Doodlebug"]=0;

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
    //Delete Spaces
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            delete spaces[i][j];
        }
        delete [] spaces[i];
    }
    delete [] spaces;

    //Delete Critters
    for (auto x : critters){
        for (int j = 0; j<critterCount[x.first]; j++){
            delete critters[x.first][j];
        }
        delete [] critters[x.first];
    }

}

void Board::runBoard() {
    //Move Doodlebugs
    for (int i = 0; i < critterCount["Doodlebug"]; i++){
        critters["Doodlebug"][i]->move();
    }

    //Move Ants
    for (int i = 0; i < critterCount["Ant"]; i++){
        critters["Ant"][i]->move();
        //std::cout << "********\nANT MOVE\n********" << std::endl;
        //printBoard();
    }

    /*
    //Starve Doodlebugs
    for (int i = 0; i < critterCount["Doodlebug"]; i++){
        critters["Doodlebug"][i]->starve();
    }

    //Breed DoodleBugs


    //Breed Ants
    for (int i = 0; i < critterCount["Ant"]; i++){
        critters["Ant"][i]->breed();
    }

     */
    //Prints out the results of the Board.
    printBoard();
    std::cout << "********\nTime Step Complete\n********" << std::endl;
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
    extendCritterSlots(type);
    if(type == "Ant"){
        critters[type][critterCount[type]] = new Ant(spaces[x_start][y_start]);
    } else if ( type == "Doodlebug"){
        //critters[type][critterCount[type]] = new DoodleBug(spaces[x_start][y_start]);
    }

    critterCount[type]++;
}

void Board::extendCritterSlots(std::string type){
    int slotSize;
    slotSize = critterCount[type] + 1;
    Critter **newSlots =  new Critter *[slotSize];
    for(int i = 0; i < critterCount[type]; i++) {
        newSlots[i] =  critters[type][i];
    }

    delete [] critters[type]; // Free the array.

    critters[type] = newSlots;
}






