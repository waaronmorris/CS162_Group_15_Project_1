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

Position* Board::GetEmptySpaces(int& count)
{
	Position* temp = new Position[rows * columns];
	
	// Adds empty positions to "temp"
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			if (!spaces[i][j]->isOccupied())
			{
				Position p;
				p.x = i;
				p.y = j;
				
				temp[count] = p;
                count++;
			}
		}
	
	// Removes extra elements from temp
	Position* empty = new Position[count];
	std::cout << "\n\ncount: " << count << "\n\n";
	for (int i = 0; i < count; i++)
		empty[i] = temp[i];
	
	delete [] temp;
	return empty;
}

void Board::setBoard(int r, int c, int ants, int doodlebugs) {
    critterCount["Ant"] = 0; // ERROR: Set to "ants"??? - Ibrahim
    critterCount["Doodlebug"] = 0; // ERROR: Set to "doodlebugs"??? - Ibrahim
	
    rows = r;
    columns = c;
    spaces = new Space **[rows];

    for (int i = 0; i < rows; i++){
        spaces[i] = new Space *[columns];
		
        for (int j = 0; j < columns; j++){
            spaces[i][j] = new Space();
            spaces[i][j]->setSpace(j, i, this);
        }
    }
	
    // Initialize all Critters at Random Locations
	// Ants
	for (int i = 0; i < ants; i++)
	{
		int count = 0;
		Position* empty = GetEmptySpaces(count);
		
		int randPos = rand() % count;
		
		createCritter("Ant", empty[randPos].x, empty[randPos].y);
		
		delete [] empty;/**/
	}
	// Doodlebugs - ERROR: doodlebugs don't seem to get added to the board
	for (int i = 0; i < doodlebugs; i++)
	{
		int count = 0;
		Position* empty = GetEmptySpaces(count);
		
		int randPos = rand() % count;
		
		//spaces[empty[randPos].x][empty[randPos].y]->getBoard()->createCritter("Ant", empty[randPos].x, empty[randPos].y); // I don't get the structure very well - Ibrahim
		createCritter("Doodlebug", empty[randPos].x, empty[randPos].y); // Which one is right??? - Ibrahim
		
		delete [] empty;
	}
	
    // Incorporate map members??? I don't know how to use them - Ibrahim
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
    }

    //Starve Doodlebugs
    for (int i = 0; i < critterCount["Doodlebug"]; i++){
        critters["Doodlebug"][i]->starve();
    }

    //Breed DoodleBugs


    //Breed Ants
    for (int i = 0; i < critterCount["Ant"]; i++){
        critters["Ant"][i]->breed();
    }

    std::cout << "********\nTime Step Complete\n********" << std::endl;
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






