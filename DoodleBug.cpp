/*********************************************************************
** Program name: Doodlebug Clasee
** Author: Group 15
** Date:
** Description: A class for doodblebug
*********************************************************************/

#include <iostream>
#include "DoodleBug.h"

DoodleBug::DoodleBug(Space *s) {
    daysNotEaten = 0;
	symbol = "X";
	space = s;
	s->setCritter(this);
}

void DoodleBug::move() {
    int x_size = space->getBoard()->getRows();
    int y_size = space->getBoard()->getColumns();

	if (space != NULL) {
        int x_move=0;
        int y_move=0;
        int dir=0;

		Position location = space->getPosition();

		for (int h =0; h<4; h++ ){
            x_move=0;
            y_move=0;

            if (h < 1){
                y_move++;
            }else if (h < 2){
                x_move++;
            }else if (h < 3){
                y_move--;
            }else if (h < 4){
                x_move--;
            }

            Space *newSpace = NULL;

            if (((location.x + x_move) < 0) || ((location.y + y_move) < 0)){
                //Move Off board left or up
                //std::cout << "Move off Board: Ant did not move" << std::endl;
            } else if (((location.x + x_move) >= x_size ) || ((location.y + y_move) >= y_size)){
                //Move Off board right or bottom
                //std::cout << "Move off Board: Ant did not move" << std::endl;
            } else {
                newSpace = space->getBoard()->getSpace((location.x + x_move), (location.y + y_move));

                if (newSpace != NULL){
                    if (newSpace->getSymbol() == "O") {
                        Critter *eatenAnt = newSpace->getCritter();
                        eatenAnt->removeCritter();
                        setSpace(newSpace);
                        daysNotEaten = 0;
                        //std::cout << "***********ANT EATEN************" << std::endl;
                        return;
                    }
                }
            }
        }

		int direction = (rand() % 4);
		Space *newSpace = getNewSpace(direction);
		if (newSpace != NULL) {
		    if (!newSpace->isOccupied()) {
		        setSpace(newSpace);
		        daysNotEaten++;
		    }
		}
	}
}

void DoodleBug::breed() {
	//Use the board generate method to creat a new Critter.
	Space *newSpace;

	bool validSpace = false;
	int direction = 0;

	do {
		newSpace = getNewSpace(direction);
		direction++;
		if (newSpace != NULL || direction >= 3) {
			validSpace = true;
		}
	} while (!validSpace);

	if (newSpace != NULL) {
		space->getBoard()->createCritter("Doodlebug", newSpace->getPosition().x, newSpace->getPosition().y);
	}
}

void DoodleBug::starve() {
    if (daysNotEaten >=3){
        removeCritter();
    }
}


DoodleBug::~DoodleBug() {}
