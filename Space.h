/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/

#ifndef PROJECT_SPACE_H
#define PROJECT_SPACE_H

class Critter;

struct Position{
    int x;
    int y;
}

class Space {
private:
    std::string color;
    Position position;
    Critter *critter;

public:
    Critter *getCritter();
    std::string getSymbol();
    void changeSymbol();
    void setCritter(Critter *movedCritter);
    void removeCritter();
    Position getPosition();
    void setSpace(int x, int y);
    };

};


#endif //PROJECT_SPACE_H
