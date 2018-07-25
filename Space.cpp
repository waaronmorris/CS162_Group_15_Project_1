/*********************************************************************
** Program name: Space
** Author:
** Date:
** Description: A class for a space in a Langston simulation.
*********************************************************************/

#include "Space.h"
#include <iostream>

Ant *Space::getAnt() {
    return ant;
}

std::string Space::getSymbol(){
    std::string rv;
    rv = color;
    if(ant){
        if (getCritter()){
            rv = getCritter()->getSymbol();
        }
    }
    return rv;
}

void Space::changeColor() {
    if (color == "_"){
        color = "#";
    }
    else if (color=="#"){
        color = "_";
    }
}

void Space::setAnt(Ant *movedAnt) {
    ant = movedAnt;
}

void Space::removeAnt() {
    ant = nullptr;

}

Position Space::getPosition() {
    return position;
}

void Space::setSpace(int x, int y){
    color = "_";
    position.x = x;
    position.y = y;
}
