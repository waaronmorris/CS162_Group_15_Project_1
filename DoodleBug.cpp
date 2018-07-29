/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#include "DoodleBug.h"
#include "Ant.h"
#include <iostream>

DoodleBug::DoodleBug(Space *s) {
	symbol = "X";
	space = s;
	s->setCritter(this);
}

void DoodleBug::move() {
	if (space != NULL) {
		Position location = space->getPosition();

		int dir = (rand() % 4);
		Space *checkDown = space->getBoard()->getSpace((location.x), (location.y - 1));
		Space *checkRight = space->getBoard()->getSpace((location.x + 1), (location.y));
		Space *checkUp = space->getBoard()->getSpace((location.x), (location.y + 1));
		Space *checkLeft = space->getBoard()->getSpace((location.x - 1), (location.y));
		if (checkUp->getSymbol() == "O") {
			std::cout << "***********ANT EATEN(ABOVE)************" << std::endl;
			dir = 0;
			Space *newSpace = getNewSpace(dir);
			Critter *eatenAnt = newSpace->getCritter();
			eatenAnt->removeCritter();
			setSpace(newSpace);
		}
		else if (checkRight->getSymbol() == "O") {
			dir = 1;
			Space *newSpace = getNewSpace(dir);
			Critter *eatenAnt = newSpace->getCritter();
			eatenAnt->removeCritter();
			setSpace(newSpace);
			std::cout << "***********ANT EATEN(RIGHT)************" << std::endl;
		}
		else if (checkDown->getSymbol() == "O") {
			dir = 2;
			Space *newSpace = getNewSpace(dir);
			Critter *eatenAnt = newSpace->getCritter();
			eatenAnt->removeCritter();
			setSpace(newSpace);
			std::cout << "***********ANT EATEN(BELOW)************" << std::endl;
		}
		else if (checkLeft->getSymbol() == "O") {
			dir = 3;
			Space *newSpace = getNewSpace(dir);
			Critter *eatenAnt = newSpace->getCritter();
			eatenAnt->removeCritter();
			setSpace(newSpace);
			std::cout << "***********ANT EATEN(LEFT)************" << std::endl;
		}
		else {
			int direction = (rand() % 4);

			Space *newSpace = getNewSpace(direction);
			if (newSpace != NULL) {
				if (!newSpace->isOccupied()) {
					setSpace(newSpace);
				}
			}
		}
	}
}

void DoodleBug::breed() {
	/*
	//Use the board generate method to creat a new Critter.
	Space *newSpace;
	bool validSpace = false;
	int direction = 0;
	do {
	newSpace = getNewSpace(direction);
	direction++;
	if (newSpace != nullptr || direction >= 3) {
	validSpace = true;
	}
	} while (!validSpace);

	if (newSpace != nullptr) {
	space->getBoard()->createCritter("Doodlebug", newSpace->getPosition().x, newSpace->getPosition().y);
	}
	*/
}

void DoodleBug::starve() {
	//removeCritter();
	std::cout << "Need to implement";
}

void DoodleBug::eatAnt(Ant* eatenAnt)
{
	std::cout << "Need to implemenet";
}


DoodleBug::~DoodleBug() {
	std::cout << "Destroy Doodlebug";
}
