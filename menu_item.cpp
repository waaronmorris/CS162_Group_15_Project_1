/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/8/18
** Description: This is the implementation file for menu_item.h
*********************************************************************/ 

#include "menu_item.h"

/*********************************************************************
** Function: MenuItem
** Description: Default constructor for a MenuItem class object
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem()
{
	this->type = VOID;
	this->title = "";
	this->prompt = "";
	this->bounds = false;
	this->minBound = 0;
	this->maxBound = 0;
	this->yesPrompt = "";
	this->noPrompt = "";
	this->currentInt = 0;
	this->currentDouble = 0;
	this->currentBool = false;
	this->currentChar = 0;
	this->currentString = "";
}
/*********************************************************************
** Function: MenuItem
** Description: Constructor for a MenuItem class object for integers
** Parameters: string, string, int, int, int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem(string title, string prompt, int minBound, int maxBound, int currentValue, ReturnType type)
{
	this->type = type;
	this->title = title;
	this->prompt = prompt;
	this->bounds = true;
	this->minBound = minBound;
	this->maxBound = maxBound;
	this->yesPrompt = "";
	this->noPrompt = "";
	this->currentInt = currentValue;
	this->currentDouble = currentValue;
	this->currentBool = false;
	this->currentChar = 0;
	this->currentString = "";
}
/*********************************************************************
** Function: MenuItem
** Description: Constructor for a MenuItem class object for doubles
** Parameters: string, string, double, double, double
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem(string title, string prompt, double minBound, double maxBound, double currentValue, ReturnType type)
{
	this->type = type;
	this->title = title;
	this->prompt = prompt;
	this->bounds = true;
	this->minBound = minBound;
	this->maxBound = maxBound;
	this->yesPrompt = "";
	this->noPrompt = "";
	this->currentInt = currentValue;
	this->currentDouble = currentValue;
	this->currentBool = false;
	this->currentChar = 0;
	this->currentString = "";
}
/*********************************************************************
** Function: MenuItem
** Description: Constructor for a MenuItem class object for booleans
** Parameters: string, string, string, string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem(string title, string prompt, string yesPrompt, string noPrompt, bool currentBool, ReturnType type)
{
	this->type = type;
	this->title = title;
	this->prompt = prompt;
	this->bounds = false;
	this->minBound = 0;
	this->maxBound = 0;
	this->yesPrompt = yesPrompt;
	this->noPrompt = noPrompt;
	this->currentInt = 0;
	this->currentDouble = 0;
	this->currentBool = currentBool;
	this->currentChar = 0;
	this->currentString = "";
}
/*********************************************************************
** Function: MenuItem
** Description: Constructor for a MenuItem class object for chars
** Parameters: string, string, char
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem(string title, string prompt, char currentChar, ReturnType type)
{
	this->type = type;
	this->title = title;
	this->prompt = prompt;
	this->bounds = false;
	this->minBound = 0;
	this->maxBound = 0;
	this->yesPrompt = "";
	this->noPrompt = "";
	this->currentInt = 0;
	this->currentDouble = 0;
	this->currentBool = false;
	this->currentChar = currentChar;
	this->currentString = "";
}
/*********************************************************************
** Function: MenuItem
** Description: Constructor for a MenuItem class object for strings
** Parameters: string, string, string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem(string title, string prompt, string currentString, ReturnType type)
{
	this->type = type;
	this->title = title;
	this->prompt = prompt;
	this->bounds = false;
	this->minBound = 0;
	this->maxBound = 0;
	this->yesPrompt = "";
	this->noPrompt = "";
	this->currentInt = 0;
	this->currentDouble = 0;
	this->currentBool = false;
	this->currentChar = 0;
	this->currentString = currentString;
}
/*********************************************************************
** Function: MenuItem
** Description: Constructor for a MenuItem class object for clicks
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem(string title, ReturnType type)
{
	this->type = type;
	this->title = title;
	this->prompt = "";
	this->bounds = false;
	this->minBound = 0;
	this->maxBound = 0;
	this->yesPrompt = "";
	this->noPrompt = "";
	this->currentInt = 0;
	this->currentDouble = 0;
	this->currentBool = false;
	this->currentChar = 0;
	this->currentString = "";
}
/*********************************************************************
** Function: MenuItem
** Description: Copy Constructor for a MenuItem class object
** Parameters: const MenuItem &
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem::MenuItem(const MenuItem &copy)
{
	this->type = copy.type;
	this->title = copy.title;
	this->prompt = copy.prompt;
	this->bounds = copy.bounds;
	this->minBound = copy.minBound;
	this->maxBound = copy.maxBound;
	this->yesPrompt = copy.yesPrompt;
	this->noPrompt = copy.noPrompt;
	this->currentInt = copy.currentInt;
	this->currentDouble = copy.currentDouble;
	this->currentBool = copy.currentBool;
	this->currentChar = copy.currentChar;
	this->currentString = copy.currentString;
}

/*********************************************************************
** Function: Equality Operator
** Description: Sets one MenuItem object equal to another
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
MenuItem& MenuItem::operator = (const MenuItem &copy)
{
	this->type = copy.type;
	this->title = copy.title;
	this->prompt = copy.prompt;
	this->bounds = copy.bounds;
	this->minBound = copy.minBound;
	this->maxBound = copy.maxBound;
	this->yesPrompt = copy.yesPrompt;
	this->noPrompt = copy.noPrompt;
	this->currentInt = copy.currentInt;
	this->currentDouble = copy.currentDouble;
	this->currentBool = copy.currentBool;
	this->currentChar = copy.currentChar;
	this->currentString = copy.currentString;
	
	return *this;
}

/*********************************************************************
** Function: SetType
** Description: Sets the return type of the MenuItem
** Parameters: ReturnType
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetType(ReturnType type)
{
	this->type = type;
}
/*********************************************************************
** Function: GetType
** Description: Gets the return type of the MenuItem
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
ReturnType MenuItem::GetType()
{
	return this->type;
}

/*********************************************************************
** Function: SetTitle
** Description: Sets the title of the MenuItem
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetTitle(string title)
{
	this->title = title;
}
/*********************************************************************
** Function: SetTitle
** Description: Gets the title of the MenuItem
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string MenuItem::GetTitle(bool printCurrentValues)
{
	stringstream ss;
	
	ss << this->title;
	
	if (printCurrentValues)
		switch (this->type)
		{
			case INT:
				ss << " (Current: " << currentInt << ')';
				
				break;
			case DOUBLE:
				ss << " (Current: " << currentDouble << ')';
				
				break;
			case BOOL:
				ss << " (Current: " << currentBool << ')';
				
				break;
			case CHAR:
				ss << " (Current: " << currentChar << ')';
				
				break;
			case STRING:
				ss << " (Current: " << currentString << ')';
				
				break;
			default: // VOID
				break;
		}
	
	return ss.str();
}

/*********************************************************************
** Function: SetTitle
** Description: Sets the title of the MenuItem
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetPrompt(string prompt)
{
	this->prompt = prompt;
}
/*********************************************************************
** Function: GetTitle
** Description: Gets the title of the MenuItem
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string MenuItem::GetPrompt(bool printCurrentValues)
{
	stringstream ss;
	
	ss << this->prompt;
	
	if (printCurrentValues)
		switch (this->type)
		{
			case INT:
			case DOUBLE:
				ss << " (" << minBound << '-' << maxBound << ')';
				
				break;
			default: // VOID, BOOL, CHAR, STRING
				break;
		}
	
	return ss.str();
}

/*********************************************************************
** Function: SetYesPrompt
** Description: Sets the "yes" prompt for a bool MenuItem
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetYesPrompt(string yesPrompt)
{
	this->yesPrompt = yesPrompt;
}
/*********************************************************************
** Function: GetYesPrompt
** Description: Gets the "yes" prompt from a MenuItem
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string MenuItem::GetYesPrompt()
{
	return this->yesPrompt;
}

/*********************************************************************
** Function: SetNoPrompt
** Description: Sets the "no" prompt for a bool MenuItem
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetNoPrompt(string noPrompt)
{
	this->noPrompt = noPrompt;
}
/*********************************************************************
** Function: GetNoPrompt
** Description: Gets the "no" prompt from a MenuItem
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string MenuItem::GetNoPrompt()
{
	return this->noPrompt;
}

/*********************************************************************
** Function: ToggleBounds
** Description: Toggle whether the bounds should be used
** Parameters: bool
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::ToggleBounds(bool bounds)
{
	this->bounds = bounds;
}
/*********************************************************************
** Function: IsBoundsOn
** Description: Returns whether bounds are being used or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool MenuItem::IsBoundsOn()
{
	return this->bounds;
}

/*********************************************************************
** Function: SetMinBound
** Description: Sets the lower bound of a MenuItem
** Parameters: double
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetMinBound(double minBound)
{
	this->minBound = minBound;
}
/*********************************************************************
** Function: GetMinBound
** Description: Gets the lower bound of a MenuItem
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
double MenuItem::GetMinBound()
{
	return this->minBound;
}

/*********************************************************************
** Function: SetMaxBound
** Description: Sets the upper bound of a MenuItem
** Parameters: double
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetMaxBound(double maxBound)
{
	this->maxBound = maxBound;
}
/*********************************************************************
** Function: GetMaxBound
** Description: Gets the upper bound of a MenuItem
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
double MenuItem::GetMaxBound()
{
	return this->maxBound;
}

/*********************************************************************
** Function: GetCurrentInt
** Description: Returns the current integer value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int MenuItem::GetCurrentInt()
{
	return this->currentInt;
}
/*********************************************************************
** Function: SetCurrentInt
** Description: Sets the current int value
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetCurrentInt(int currentInt)
{
	this->currentInt = currentInt;
}

/*********************************************************************
** Function: GetCurrentDouble
** Description: Returns the current double value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
double MenuItem::GetCurrentDouble()
{
	return this->currentDouble;
}
/*********************************************************************
** Function: SetCurrentDouble
** Description: Sets the current double value
** Parameters: double
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetCurrentDouble(double currentDouble)
{
	this->currentDouble = currentDouble;
}

/*********************************************************************
** Function: GetCurrentBool
** Description: Returns the current boolean value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool MenuItem::GetCurrentBool()
{
	return this->currentBool;
}
/*********************************************************************
** Function: SetCurrentBool
** Description: Sets the current boolean value
** Parameters: bool
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetCurrentBool(bool currentBool)
{
	this->currentBool = currentBool;
}

/*********************************************************************
** Function: GetCurrentChar
** Description: Returns the current character value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
char MenuItem::GetCurrentChar()
{
	return this->currentChar;
}
/*********************************************************************
** Function: SetCurrentChar
** Description: Sets the current char value
** Parameters: char
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetCurrentChar(char currentChar)
{
	this->currentChar = currentChar;
}

/*********************************************************************
** Function: GetCurrentString
** Description: Returns the current string value
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string MenuItem::GetCurrentString()
{
	return this->currentString;
}
/*********************************************************************
** Function: SetCurrentString
** Description: Sets the current string value
** Parameters: string
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void MenuItem::SetCurrentString(string currentString)
{
	this->currentString = currentString;
}

/*********************************************************************
** Function: GetIntInput
** Description: Gets an integer input from user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int MenuItem::GetIntInput()
{
	return currentInt = GetInt(GetPrompt(), bounds, (int) minBound, bounds, (int) maxBound);
}

/*********************************************************************
** Function: GetDoubleInput
** Description: Gets a double input from user (BUGGY)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
double MenuItem::GetDoubleInput()
{
	return currentDouble = GetInt(GetPrompt(), bounds, (int) minBound, bounds, (int) maxBound);
}

/*********************************************************************
** Function: GetBoolInput
** Description: Gets a bool input from user
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
bool MenuItem::GetBoolInput()
{
	return currentBool = GetBool(GetPrompt(), yesPrompt, noPrompt);
}

/*********************************************************************
** Function: GetCharInput
** Description: Gets a char input from user (BUGGY)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
char MenuItem::GetCharInput()
{
	return currentChar = GetString(GetPrompt())[0];
}

/*********************************************************************
** Function: GetStringInput
** Description: Gets a string input from user (BUGGY)
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string MenuItem::GetStringInput()
{
	return currentString = GetString(GetPrompt());
}