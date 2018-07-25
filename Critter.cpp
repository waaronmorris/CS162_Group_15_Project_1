/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#include "Critter.h"
#include <string>


const std::string Critter::getSymbol() {
    return symbol;
}

void Critter::setSymbol(const std::string &symbol) {
    Critter::symbol = symbol;
}

Space *Critter::getSpace() const {
    return space;
}

void Critter::setSpace(Space *s) {
    space->removeCritter();
    space = s;
    space->setCritter(this);
}
