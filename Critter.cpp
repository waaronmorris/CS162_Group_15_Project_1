/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#include "Critter.h"
#include <string>
#include <iostream>

Critter::~Critter(){}

const std::string Critter::getSymbol() {
    return symbol;
}

Space *Critter::getSpace() const {
    return space;
}

void Critter::setSpace(Space *s) {
    space->removeCritter();
    space = s;
    space->setCritter(this);
}

void Critter::removeCritter(){
    space->removeCritter();
    space = nullptr;
}
