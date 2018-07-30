/*********************************************************************
** Program name: 
** Author:
** Date:
** Description: 
*********************************************************************/

#include "Space.h"
/*
Space::Space
{
	this->critter = NULL;
}
*/
Critter *Space::getCritter(){
    return critter;
}

std::string Space::getSymbol(){
    std::string rv;
	
    //add some validation on whether a Critter is present
    if (isOccupied()){
        rv = getCritter()->getSymbol();
    } else {
        rv = "_";
    }

    return rv;
}

void Space::setCritter(Critter *movedCritter){
    critter = movedCritter;
}

void Space::removeCritter(){
    if (critter != NULL){
        critter = NULL;
    }
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

Board *Space::getBoard(){
    return board;
}

void Space::setBoard(Board *board) {
    Space::board = board;
}

bool Space::isOccupied() {
    return critter != NULL;
}
