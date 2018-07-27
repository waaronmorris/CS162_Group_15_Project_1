/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#ifndef PROJECT_CRITTER_H
#define PROJECT_CRITTER_H

#include <string>
#include "Space.h"


class Critter {
protected:
    std::string symbol="0";
    Space *space;
public:
    //required functions
    virtual ~Critter()=0;
    virtual void move()=0;
    virtual void breed()=0;
    virtual Space *getNewSpace(int direction, bool &validSpace)=0;

    //Function to assist Space and Board
    /*!
     * A function to return the symbol. Ants should be O and Doodlebugs should be X
     * @return The symbol of the space during print out.
     */
    const std::string getSymbol();
    /*!
     * Get the space a critter is on.
     * @return
     */
    Space *getSpace() const;
    /*!
     * Set the space a Critter has moved to.
     * @param space The space a critter now occupies
     */
    void setSpace(Space *space);
    /*!
     * Removes the critter from the Game.
     */
    void removeCritter();
};

#endif //PROJECT_CRITTER_H
