/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/8/18
** Description: This is the implementation file for menu.hs
*********************************************************************/ 

#include "menu.h"

/*********************************************************************
** Function: Menu
** Description: Constructor for a Menu class object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Menu::Menu()
{
	menuTitle = "";
	input = -1;
	numItems = 0;
	items = new MenuItem*[0];
}
/*********************************************************************
** Function: Menu
** Description: Constructor for a Menu class object
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Menu::Menu(string menuTitle)
{
	this->menuTitle = menuTitle;
	input = -1;
	numItems = 0;
	items = new MenuItem*[0];
}
/*********************************************************************
** Function: Menu
** Description: Copy constructor for a Menu class object
** Parameters: const Menu &
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Menu::Menu(const Menu &copy)
{
	this->menuTitle = copy.menuTitle;
	this->input = copy.input;
	this->numItems = copy.numItems;
	
	Copy2DArray<MenuItem>(this->items, copy.items, copy.numItems, 1);
}
/*********************************************************************
** Function: ~Menu
** Description: Destructor for a Menu class object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Clears dynamic memory
*********************************************************************/
Menu::~Menu()
{
	Delete2DArray<MenuItem>(items, numItems, true);
}

/*********************************************************************
** Function: Equality Operator
** Description: Sets one Menu object equal to another
** Parameters: const Menu &
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Menu& Menu::operator = (const Menu &copy)
{
	if (this->numItems != 0)
		delete [] this->items;
	
	this->menuTitle = copy.menuTitle;
	this->input = copy.input;
	this->numItems = copy.numItems;
	
	Copy2DArray<MenuItem>(this->items, copy.items, copy.numItems, 1);
	
	return *this;
}
MenuItem* Menu::operator [] (unsigned int index)
{
	return GetItem(index);
}

/*********************************************************************
** Function: AddItem
** Description: Adds a MenuItem to the items array
** Parameters: MenuItem
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Menu::AddItem(MenuItem* item)
{
	numItems++;
	MenuItem** temp = new MenuItem*[numItems];
	
	for (int i = 0; i < numItems - 1; i++)
		temp[i] = items[i];
	
	temp[numItems - 1] = item;
	
	delete [] items;
	items = temp;
}

/*********************************************************************
** Function: RemoveItem
** Description: Removes a MenuItem to the items array
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Menu::RemoveItem(int index)
{
	numItems--;
	MenuItem** temp = new MenuItem*[numItems];
	bool skipped = false;
	
	for (int i = 0; i < numItems + 1; i++)
		if (i != index)
			temp[i - (int) skipped] = items[i];
		else
			skipped = true;
	
	delete [] items;
	items = temp;
}
<<<<<<< HEAD
<<<<<<< HEAD
/*********************************************************************
** Function: RemoveAll
** Description: Removes all MenuItems from array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Menu::RemoveAll()
{
	for (int i = 0; i < numItems; i++)
		RemoveItem(0);
}
=======
>>>>>>> 37572b50b943df1d58b254d35c1649e57240cb8f
=======
>>>>>>> d8e20ade9b3d20b57cdc2e0c89210287cafaa26e

/*********************************************************************
** Function: DisplayItems
** Description: Display the menu items to the user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Menu::DisplayItems(bool printCurrentValues)
{
	Divider();
	
	if (menuTitle == "")
		cout << "\nMenu Items:\n";
	else
		cout << endl << menuTitle << ":\n";
	
	for (int i = 0; i < numItems; i++)
		cout << '\t' << (i + 1) << ". " << items[i]->GetTitle(printCurrentValues) << '\n';
}

/*********************************************************************
** Function: Prompt
** Description: Prompt user to pick a menu item to get input from
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Menu::Prompt(bool printCurrentValues)
{
	DisplayItems(printCurrentValues);
	
	if (numItems > 0)
	{
		input = GetInt("\nPick a menu item", true, 1, true, numItems) - 1;
		
		return input;
	}
	
	cout << "\nMenu has no items.\n";
	
	return input -1;
}

/*********************************************************************
** Function: GetMenuTitle
** Description: Gets the menu title
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string Menu::GetMenuTitle()
{
	return menuTitle;
}
/*********************************************************************
** Function: SetMenuTitle
** Description: Sets the menu title
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Menu::SetMenuTitle(string menuTitle)
{
	this->menuTitle = menuTitle;
}

/*********************************************************************
** Function: GetInput
** Description: Returns the last input given by the user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Menu::GetInput()
{
	return input;
}

/*********************************************************************
** Function: GetNumItems
** Description: Gets the number of items in the items array
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Menu::GetNumItems()
{
	return numItems;
}

/*********************************************************************
** Function: GetItem
** Description: Gets MenuItem from items array
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem* Menu::GetItem(unsigned int index)
{
	return items[index];
}