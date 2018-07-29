/*********************************************************************
** Program name: Space
** Author:
** Date:
** Description: A class for a space in a Langston simulation.
*********************************************************************/

#include "Space.h"
#include "Critter.h"
#include <iostream>

Space::Space
{
	this->critter = nullptr;
}

Critter *Space::getCritter(){
    return critter;
}

std::string Space::getSymbol(){
    std::string rv;
	
    //add some validation on whether a Critter is present
    if (isOccupied()){
        rv = getCritter()->getSymbol();
    } else {
        rv = " "; // I changed this from "_"
    }

    return rv;
}

void Space::setCritter(Critter *movedCritter){
    critter = movedCritter;
}

void Space::removeCritter(){
    critter = nullptr;
}

Position Space::getPosition() {
    return position;
}

void Space::setSpace(int x, int y, Board *b){
    color = "_";
    position.x = x;
    position.y = y;
    board = b;
}

Space::~Space() {
    //delete critter;
}

Board *Space::getBoard() const {
    return board;
}

void Space::setBoard(Board *board) {
    Space::board = board;
}

bool Space::isOccupied() {
    return critter != NULL;
}
