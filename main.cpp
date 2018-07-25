/*********************************************************************
** Program name:
** Author:
** Date:
** Description:
*********************************************************************/
#include "Critter.hpp"
#include <iostream>

int main()
{
	//double pointer initiation
	Critter** critterArray;
	
	//dynamically allocate array of 20 Critter-pointers
	critterArray = new Critter*[20];
	for (int i = 0; i < 20; i++)
	{
		//for each Critter-pointer, dynamically allocate another array of 20 Critters
		critterArray[i] = new Critter[20];
	}
	
	//print the current board of empty spaces (0s)
	critterArray[0][0].printBoard();
	
	
	
	std::cout << std::endl;

	//place critter changes the spot on board given by the x,y paramaters to "1"
	//because it was called by a different critter object, i'm demonstrating how
	//any of the critter objects in the critter 2d arraay can change the static board
	//member
	critterArray[1][0].placeCritter(3,4);
	//then any of the critter objects will print the current, updated board
	critterArray[2][4].printBoard();

	
	//free dynamic memory
	for (int i = 0; i <20; i++)
	{
		delete [] critterArray[i];
	}

	delete [] critterArray;
	
	return 0;
}

