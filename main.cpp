/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/25/18
** Description: This program runs a critter simulation where the ants
**				are moving randomly on a 2D board and the doodlebugs
**				are trying to eat them, while also moving randomly.
*********************************************************************/ 

// NOTE: I'M CURRENTLY USING A POINTER ARRAY OF "MenuItem" IN MY MENUS. I AM TRYING TO
//		 MAKE "currentInt" CHANGE WHEN THE USER DOES INTEGER INPUT. IF I AM UNABLE TO
//		 FIGURE IT OUT I WILL SWITCH BACK TO A REGULAR ARRAY OF "MenuItem" (NO POINTERS)

#include "menu.h"
// FIX UPDATING CURRENT VALUES - currentInt (a member of MenuItem) is not changing after getting integer input
// FIX DOUBLE INPUT (not a priority, as this program doesn't use doubles)
int main()
{
	// Randomize seed
	srand(time(NULL));
	
	// Variable declaration
	Menu mainMenu = Menu("Main Menu");
	Menu options = Menu("Options Menu");
	Menu nextStep = Menu("Next Turn Menu");
	
	// Options Menu Starting Values
	double rows = 20;
	double cols = 20;
	double iterations = 100;
	int ants = 100;
	int doodlebugs = 5;
	
	// Menu menu items
	mainMenu.AddItem(new MenuItem("Game Options (EXTRA CREDIT INCLUDED)"));
	mainMenu.AddItem(new MenuItem("Quit"));
	
	// Options menu items
	options.AddItem(new MenuItem("Play Game"));
	options.AddItem(new MenuItem("Number of Rows", "Number of Rows", 5, 100, rows));
	options.AddItem(new MenuItem("Number of Columns", "Number of Columns", 5, 100, cols));
	options.AddItem(new MenuItem("Number of Iterations", "Number of Iterations", 1, 100000, iterations));
	options.AddItem(new MenuItem("Number of Initial Ants", "Number of Initial Ants", 1, 10000, ants));
	options.AddItem(new MenuItem("Number of Initial Doodlebugs", "Number of Initial Doodlebugs", 1, 10000, doodlebugs));
	options.AddItem(new MenuItem("Back"));
	
	// Next Step Menu (we don't have to use this, it's an option)
	nextStep.AddItem(new MenuItem("Start Next Step"));
	nextStep.AddItem(new MenuItem("Quit Game"));
	
	do // Main menu loop
	{
		mainMenu.Prompt();
		
		switch (mainMenu.GetInput())
		{
			case 0: // Game Options
				do // Options menu loop
				{
					options.Prompt();
					
					switch (options.GetInput())
					{
						case 1: // Number of Rows
							rows = options[1]->GetIntInput();
							
							break;
						case 2: // Number of Columns
							cols = options[2]->GetIntInput();
							
							break;
						case 3: // Number of Iterations
							iterations = options[3]->GetIntInput();
							
							break;
						case 4: // Number of Initial Ants
							ants = options[4]->GetIntInput();
							
							break;
						case 5: // Number of Initial Doodlebugs
							doodlebugs = options[5]->GetIntInput();
							
							break;
					}
				} while (options.GetInput() != 0 && options.GetInput() != 6);
				
				if (options.GetInput() == 0) // Play Game
				{
					if (ants + doodlebugs > rows * cols)
						cout << "\nThere are " << rows * cols << " available spaces and you want to add"
							 << ants + doodlebugs << "critters, or " << ants << " ants and " << doodlebugs << " doodlebugs.\n"
							 << "Please either increase the board dimensions or decrease the critter count.\n";
					else
					{/*
						// Game initialization
						Board *gameBoard = new Board();
						gameBoard->setBoard(20, 20);

						//Create Ant
						for (int i = 0; i < 5; i++)
						{
							gameBoard->createCritter("Ant", i, i);
						}

						gameBoard->runBoard();
						delete gameBoard;
						return 0;*/
					}

					// Text to prompt user to again
					mainMenu.SetMenuTitle("Play Again?");
				}
				
				break;
			default: // Quit
				cout << "\nHave a nice day!\n\n";
				break;
		}
	} while (mainMenu.GetInput() != 1);
	
	return 0;
}