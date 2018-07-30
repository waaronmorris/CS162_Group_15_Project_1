/*********************************************************************
** Program name: 
** Author:
** Date:
** Description: 
*********************************************************************/

#ifndef PROJECT_1_BOARD_H
#define PROJECT_1_BOARD_H

#include <string>
#include <map>

class Critter;

class Space;

struct Position{
    int x;
    int y;
};

class Board {
private:
    int rows;
    int columns;
    Space ***spaces;
    Position **empty;
    int emptyCount=0;

    std::map<std::string, int> critterSlots;
    std::map<std::string, int> critterCount;
    std::map<std::string, Critter **> critters;

public:

    void UpdateEmptySpaces();
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
     * Set the Number of Rows and Columns the table contains, as well as
	 * adds a set number of ants and doodlebugs to the board
     * @param r Number of rows
     * @param c Number of columns
     * @param ants Number of ants
     * @param doodlebugs Number of doodlebugs
     */
    void setBoard(int r, int c, int ants, int doodlebugs);
	
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
    void extendCritterSlots(std::string type);
    void removeCritter(std::string type, Critter *critter);
    void resetCritterSlots(std::string type, int loc);
};

#endif //PROJECT_1_BOARD_H
