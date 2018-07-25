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
    bool isOccupied();
    Board *getBoard() const;
    void setBoard(Board *board);
    Critter *getCritter();
    std::string getSymbol();
    void setCritter(Critter *movedCritter);
    void removeCritter();
    Position getPosition();
    void setSpace(int x, int y, Board* b);
    virtual ~Space();
};

};


#endif //PROJECT_SPACE_H
