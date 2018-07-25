/*********************************************************************
** Program name: Langston Ants
** Author:
** Date:
** Description: A space for keeping track of all the items on a Langston board
 * (i.e. an Ant and Spaces).
*********************************************************************/


#ifndef PROJECT_1_BOARD_H
#define PROJECT_1_BOARD_H

#include <string>

class Critter;

class Space;

class Board {
private:
    int rows;
    int columns;
    int critterCount=0;

    Space ***spaces;
    Critter **critters;

public:
    /*!
     *
     * @return int Number of Rows of the Board
     */
    int getRows() const;
    /*!
     *
     * @return int Number of columns of the Board
     */
    int getColumns() const;
    /*!
     * Set the Number of Rows and Columns the table contains
     * @param r Number of rows
     * @param c Number of Columns
     */
    void setBoard(int r, int c);
    /*!
     * Retrieve one space on the board
     * @param r The Row of the Space
     * @param c The Column of the Space
     * @return The Space Requested
     */
    Space *getSpace(int r, int c);
    /*!
     * Basic Deconstructor
     */
    ~Board();
    /*!
     * A Function to print the board based on the Symbol of each space.
     */
    void printBoard();
    /*!
     * A basic cycle function to run through a step
     */
    void runBoard();

    /*!
     * A function to create a Critter (Ant or DoodleBug
     * @param type string of Critter Type (Ant or Doodlebug)
     * @param x the row to place the Critter
     * @param y the column to place the Critter
     */
    void createCritter(std::string type, int x, int y);
    /*!
     * Basic Function to expand the number of Critters on the Board.
     */
    void extendCritterSlots();

};

#endif //PROJECT_1_BOARD_H
