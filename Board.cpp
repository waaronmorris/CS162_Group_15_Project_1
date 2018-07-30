/*********************************************************************
** Program name:
** Author:
** Date:
** Description: 
*********************************************************************/

#include <iostream>
#include <string>
#include "Board.h"
#include "Ant.h"
#include "DoodleBug.h"
#include "Space.h"

void Board::printBoard() {
    for (int i = 0; i<rows; i++){
        for (int j = 0; j<columns; j++){
            std::cout << spaces[i][j]->getSymbol();
        }
        std::cout << std::endl;
    }
}

void Board::UpdateEmptySpaces() {
    int empties=0;
    Position **temp = new Position *[rows * columns];


    if (emptyCount > 0){
        for (int j = 0; j< emptyCount;j++){
            delete empty[j];
        }
    }

    // Adds empty positions to "temp"
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            if (!spaces[i][j]->isOccupied()) {
                temp[empties] = new Position();
                temp[empties]->x = i;
                temp[empties]->y = j;
                empties++;
            }
        }


    // Removes extra elements from temp
    for (int i = 0; i < emptyCount; i++){
        empty[i] = temp[i];
    }

    delete[] empty;
    empty = temp;
    emptyCount = empties;
}

void Board::setBoard(int r, int c, int ants, int doodlebugs) {
    critterCount["Ant"] = 0;
    critterCount["Doodlebug"] = 0;
	
    rows = r;
    columns = c;

    empty = new Position *[rows * columns];
    spaces = new Space **[rows];

    for (int i = 0; i < rows; i++){
        spaces[i] = new Space *[columns];
		
        for (int j = 0; j < columns; j++){
            spaces[i][j] = new Space();
            spaces[i][j]->setSpace(j, i, this);
        }
    }

    UpdateEmptySpaces();

	for (int i = 0; i < ants; i++)
	{
		int randPos = (rand() % (emptyCount));
		createCritter("Ant", empty[randPos]->x, empty[randPos]->y);

	}

	for (int i = 0; i < doodlebugs; i++)
	{
		int randPos = (rand() % (emptyCount));
		createCritter("Doodlebug", empty[randPos]->x, empty[randPos]->y);

	}
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


    for (int j = 0; j< emptyCount; j++){
        delete empty[j];
    }
    delete []empty;
}

void Board::runBoard() {
    //Move Doodlebugs
    for (int i = 0; i < critterCount["Doodlebug"]; i++){
        critters["Doodlebug"][i]->move();
    }

    //Move Ants
    for (int i = 0; i < critterCount["Ant"]; i++){
        critters["Ant"][i]->move();
    }

    //Starve Doodlebugs
    for (int i = 0; i < critterCount["Doodlebug"]; i++){
        critters["Doodlebug"][i]->starve();
    }

    //Breed DoodleBugs
    int db_count = critterCount["Doodlebug"];
    for (int i = 0; i < db_count; i++){
        critters["Doodlebug"][i]->breed();
    }

    //Breed Ants
    int ant_count = critterCount["Ant"];
    for (int i = 0; i < ant_count; i++){
        critters["Ant"][i]->breed();
    }

    std::cout << "********\nTime Step Complete\n********" << std::endl;
    printBoard();
}

Space *Board::getSpace(int r, int c) {
    if(r >= 0 && r<rows && c >= 0 && c<columns){
        if (spaces[r][c] != NULL){
            return spaces[r][c];
        }
    }
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
        critters[type][critterCount[type]] = new DoodleBug(spaces[x_start][y_start]);
    }

    critterCount[type]++;
    UpdateEmptySpaces();
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
    critterSlots[type] = slotSize;
}

void Board::removeCritter(std::string type, Critter *critter) {
    int critterLoc = 0;
    for(int i = 0; i < critterCount[type]; i++) {
        if (critter == critters[type][i]){
            critterLoc = i;
        }
    }
    delete critters[type][critterLoc];
    resetCritterSlots(type, critterLoc);
    critterCount[type]--;
}

void Board::resetCritterSlots(std::string type, int loc) {
    int tot=0;
    for(int i = loc; i < critterCount[type]; i++) {
        critters[type][i] =  critters[type][i+1];
        tot=i;
    }
    critters[type][tot] = NULL;


}






