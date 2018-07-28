/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#ifndef PROJECT_SPACE_H
#define PROJECT_SPACE_H

#include <string>
#include "Board.h"

class Critter;

struct Position{
    int x;
    int y;
};

class Space {
private:
    std::string color;
    Board *board;
    Position position;
    Critter *critter;

public:
	/*!
     * Default Constructor for Space
     */
    Space();
	
    /*!
     * Identifies if the space is occupied
     *
     * @return Is the space currently occupied
     */
    bool isOccupied();

    /*!
     * get the board of the space
     * @return A Board
     */
    Board *getBoard() const;

    /*!
     * Sets the board for the space.
     * @param board
     */
    void setBoard(Board *board);
    /*!
     * returns the critter located on the board
     * @return A Critter
     */
    Critter *getCritter();
    /*!
     * returns the symbol of the critter currently on the space
     */
    std::string getSymbol();
    /*!
     * Sets a critter on the current space.
     * @param movedCritter
     */
    void setCritter(Critter *movedCritter);
    /*!
     * removes a critter from the space
     */
    void removeCritter();

    /*!
     * Get the position of the space on the grid space.
     * @return Position of space on grid space
     */
    Position getPosition();
    /*!
     *
     * @param x the row of the current grid space
     * @param y the column of the grid space
     * @param b the grid space
     */
    void setSpace(int x, int y, Board* b);

    /*!
     * Basic Deconstructor
     */
    virtual ~Space();
};

#endif //PROJECT_SPACE_H
