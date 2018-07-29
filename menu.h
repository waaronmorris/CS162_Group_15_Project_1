/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/8/18
** Description: This is the header file for menu.cpp
*********************************************************************/ 

#ifndef MENU
#define MENU

#include "menu_item.h"

class Menu
{
	private:
		MenuItem** items;
		string menuTitle;
		int numItems;
		int input;
	
	public:
		Menu();
		Menu(string);
		Menu(const Menu &);
		~Menu();
		
		Menu& operator = (const Menu &);
		MenuItem* operator [] (unsigned int);
		
		void AddItem(MenuItem*);
		
		void RemoveItem(int index);
<<<<<<< HEAD
		void RemoveAll();
=======
>>>>>>> 37572b50b943df1d58b254d35c1649e57240cb8f
		
		void DisplayItems(bool = true);
		
		int Prompt(bool = true);
		
		string GetMenuTitle();
		void SetMenuTitle(string);
		
		int GetInput();
		
		int GetNumItems();
		
		MenuItem* GetItem(unsigned int);
};

#endif