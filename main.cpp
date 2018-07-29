/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/25/18
** Description: This program runs a critter simulation where the ants
**				are moving randomly on a 2D board and the doodlebugs
**				are trying to eat them, while also moving randomly.
*********************************************************************/ 

#include "Board.h"
#include "menu.h"

#define ROWS 20
#define COLUMNS 20
#define ITERATIONS 100
#define ANTS 100
#define DOODLEBUGS 5

// FIX DOUBLE INPUT (not a priority, as this program doesn't use doubles, but for future projects)

////I may be wrong but it looks like you are only updating "rows" externally in main. I don't see how the MenuItem object is 
////updating internally. I don't really have a good understanding of how all your menu code works but is there another function you
////need to call before the menu will update with the choice? - Tres

/* Tres -
 * 
 * The way my menu functions work is I declare a Menu object and add MenuItems to it.
 * Each MenuItem serves to organize Menu inputs, but so far it isn't able to save the last value entered by the user, which is a bug I'm trying to fix.
 * I've worked around that by saving the user inputs in external variables (such as "rows", what you pointed out in your above comment).
 * Unfortunately, when MenuItem.GetIntInput() is called, it is supposed to save the user input to a private member called "currentInt", but it doesn't
 * 		seem to actually save. Every time the Menu.Prompt() is called, it should display the MenuItems with the updated current values, but the current
 * 		values don't actually seem to change. This is the bug I'm trying to fix, but until then, I'm using external variables to save user input.
 * 
 * UPDATE: Thanks to William Morris, the issue has now been resolved. No longer using external variables to save user input.
 * 
 * As for how the menu works, here is a simple pseudocode that mimics what I do:
 * 		
 *		Declaration of Menu object
 *		
 *		Menu.AddItem( new MenuItem( "Start" ))	// Index 0
 *		Menu.AddItem( new MenuItem( int ))		// Index 1
 *		Menu.AddItem( new MenuItem( bool )) 	// Index 2
 *		Menu.AddItem( new MenuItem( "Quit" ))	// Index 3
 *		
 * 		do // Menu Loop
 *		{
 *			Menu.Prompt() 						// Asks user to choose a MenuItem from the array
 *			
 *			switch Menu.GetInput() 				// Decides what to do when the user chooses a MenuItem
 *			{
 *				case 1: 						// MenuItem at index 1
 *					Menu[1].GetIntInput(); 		// Get int input from the MenuItem at index 1
 * 					
 * 					break;
 *				case 2: 						// MenuItem at index 2
 *					Menu[2].GetBoolInput(); 	// Get bool input from the MenuItem at index 2
 * 					
 * 					break;
 * 				default: 						// If user does not choose indexes 1 and 2
 * 					break;
 *			}
 *		} while Menu.GetInput() is not index 0 or 3; 	// Continues loop while the user does not choose the MenuItem at indexes 0 and 3
 * 		
 * 		// Continue code
 */

int main()
{
	// Randomize seed
	srand(time(NULL));
	
	// Menu Declarations
	Menu mainMenu = Menu("Main Menu");
	Menu options = Menu("Options Menu");
	Menu nextStep = Menu("Next Turn Menu");
	
	// Menu menu items
	mainMenu.AddItem(new MenuItem("Game Options (EXTRA CREDIT INCLUDED)"));
	mainMenu.AddItem(new MenuItem("Quit"));
	
	// Options menu items
	options.AddItem(new MenuItem("Play Game"));
	options.AddItem(new MenuItem("Number of Rows", "Number of Rows", 5, 100, ROWS));
	options.AddItem(new MenuItem("Number of Columns", "Number of Columns", 5, 100, COLUMNS));
	options.AddItem(new MenuItem("Number of Iterations", "Number of Iterations", 1, 100000, ITERATIONS));
	options.AddItem(new MenuItem("Number of Initial Ants", "Number of Initial Ants", 1, 10000, ANTS));
	options.AddItem(new MenuItem("Number of Initial Doodlebugs", "Number of Initial Doodlebugs", 1, 10000, DOODLEBUGS));
	options.AddItem(new MenuItem("Reset Defaults"));
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
							options[1]->GetIntInput();
							
							break;
						case 2: // Number of Columns
							options[2]->GetIntInput();
							
							break;
						case 3: // Number of Iterations
							options[3]->GetIntInput();
							
							break;
						case 4: // Number of Initial Ants
							options[4]->GetIntInput();
							
							break;
						case 5: // Number of Initial Doodlebugs
							options[5]->GetIntInput();
							
							break;
						case 6:
							options[1]->SetCurrentInt(ROWS);
							options[2]->SetCurrentInt(COLUMNS);
							options[3]->SetCurrentInt(ITERATIONS);
							options[4]->SetCurrentInt(ANTS);
							options[5]->SetCurrentInt(DOODLEBUGS);
							
							break;
					}
				} while (options.GetInput() != 0 && options.GetInput() != 7); // Repeat Options Menu while user did not choose "Start" or "Back"
				
				if (options.GetInput() == 0) // Play Game
				{
					// if (ants + doodlebugs > rows * cols)
					if (options[4]->GetCurrentInt() * options[5]->GetCurrentInt() > options[1]->GetCurrentInt() * options[2]->GetCurrentInt())
					{
						Divider();
						
						cout << "\nThere are " << options[1]->GetCurrentInt() * options[2]->GetCurrentInt() << " available spaces and you want to add "
							 << options[4]->GetCurrentInt() * options[5]->GetCurrentInt() << " critters, or "
							 << options[4]->GetCurrentInt() << " ants and " << options[5]->GetCurrentInt() << " doodlebugs.\n"
							 << "Please either increase the board dimensions or decrease the critter count.\n";
					}
					else
					{
						// Game initialization
						Board *gameBoard = new Board();
						
						int rows = options[1]->GetCurrentInt();
						int cols = options[2]->GetCurrentInt();
						int iterations = options[3]->GetCurrentInt();
						int ants = options[4]->GetCurrentInt();
						int doodlebugs = options[5]->GetCurrentInt();
						
						// Board initialization
						gameBoard->setBoard(rows, cols);
						//gameBoard->addCritters(ants, doodlebugs);
						
						/* I created the ants and doodlebugs in Board.setBoard(), please look over - Ibrahim
						 * 
						//Create Ants
						for (int i = 0; i < ants; i++)
						{
							gameBoard->createCritter("Ant", RandInt(0, (cols-1)), RandInt(0, (rows-1)));
						}
						*/
						
						// Run Simulation
                        for (int i = 0; i < iterations; i++)
                            gameBoard->runBoard();
						
						// End of Simulation
						delete gameBoard;
						
						// Text to prompt user to again
						mainMenu.SetMenuTitle("Play Again?");
					}
				}
				
				break;
			default: // Quit
				cout << "\nHave a nice day!\n\n";
				break;
		}
	} while (mainMenu.GetInput() != 1);
	
	return 0;
}
