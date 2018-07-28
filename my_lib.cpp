/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/8/18
** Description: This is the implementation file for my_lib.h
*********************************************************************/ 

#include "my_lib.h"

/*********************************************************************
** Function: OppositeDirection
** Description: Returns the opposite direction of the input
** Parameters: Direction
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
Direction OppositeDirection(Direction d)
{
	switch (d)
	{
		case UP:
			return DOWN;
		case DOWN:
			return UP;
		case FORWARD:
			return BACKWARD;
		case BACKWARD:
			return FORWARD;
		case RIGHT:
			return LEFT;
		case LEFT:
			return RIGHT;
	}
}

/*********************************************************************
** Function: DirectionToString
** Description: Returns the string equivalent of a Direction
** Parameters: Direction
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
string DirectionToString(Direction d)
{
	switch (d)
	{
		case UP:
			return "UP";
		case DOWN:
			return "DOWN";
		case FORWARD:
			return "FORWARD";
		case BACKWARD:
			return "BACKWARD";
		case RIGHT:
			return "RIGHT";
		case LEFT:
			return "LEFT";
	}
}

/*********************************************************************
** Function: Divider
** Description: Outputs a line to the screen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Divider()
{
	cout << "\n----------------------------------------\n";
}

/*********************************************************************
** Function: NumberOf
** Description: Counts how many desired chars exist in string
** Parameters: string, char
** Pre-Conditions: String and char are both not empty
** Post-Conditions: Returns positive integer
*********************************************************************/
int NumberOf(string s, char c)
{
	int n = 0;

	for (unsigned int i = 0; i < s.length(); i++)
		if (s[i] == c)
			n++;
	
	return n;
}

/*********************************************************************
** Function: CheckOnlyNumber
** Description: Checks to see if string only contain just numerical characters
** Parameters: string, dec
** Pre-Conditions: String is not empty
** Post-Conditions: Returns a boolean
*********************************************************************/
bool CheckOnlyNumber(string s, bool dec = false)
{
	for (unsigned int i = 0; i < s.length(); i++)
		if ( ((s[i] < '0' || s[i] > '9') && s[i] != '-' && !dec) || (dec && NumberOf(s, '.') > 1) )
			return false;
	
	return true;
}

/*********************************************************************
** Function: CheckCorrectNegative
** Description: Checks to see if the negative character is in the correct spot
** Parameters: string
** Pre-Conditions: String is not empty
** Post-Conditions: Returns boolean
*********************************************************************/
bool CheckCorrectNegative(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
		if (s[i] == '-' && i != 0)
			return false;
	
	return true;		
}

/*********************************************************************
** Function: IsInt
** Description: Checks to see if a string can be converted to an integer
** Parameters: string
** Pre-Conditions: String is not empty
** Post-Conditions: Returns a boolean
*********************************************************************/
bool IsInt(string num)
{
	return (CheckCorrectNegative(num) && CheckOnlyNumber(num));
}

/*********************************************************************
** Function: GetString
** Description: Gets a string input from user
** Parameters: string
** Pre-Conditions: String is not empty
** Post-Conditions: Returns valid string
*********************************************************************/
string GetString(string s)
{
	string str = "";
	
	cout << s << ": ";
	getline(cin, str);
	
	cin.ignore();
	
	return str;
}

/*********************************************************************
** Function: StringToInt
** Description: Converts a string to an integer
** Parameters: string
** Pre-Conditions: String is not empty
** Post-Conditions: Returns a valid integer
*********************************************************************/
int StringToInt(string s)
{
	int n = 0;
	
	for (unsigned int i = 0; i < s.length(); i++)
		if (s[s.length() - i - 1] != '-')
			n += (s[s.length() - i - 1] - 48) * pow(10, i);
		else
			n *= -1;
	
	return n;
}

/*********************************************************************
** Function: GetInt
** Description: Gets an int input from user
** Parameters: string, int, int
** Pre-Conditions: String is not empty
** Post-Conditions: Returns valid int
*********************************************************************/
int GetInt(string str, bool minLimit, int min, bool maxLimit, int max)
{
	if (min == max && minLimit && maxLimit)
	{
		cout << "\nOnly value possible is " << min << ".\n";
		return min;
	}
	if (minLimit && maxLimit && min > max)
	{
		cout << "\nThe minimum limit is larger than the maximum limit. Values were swapped.";
		
		min += max;
		max = min - max;
		min -= max;
	}
	
	string s;
	
	do
	{
		cout << str << ": ";
		cin >> s;
		
		if (!IsInt(s))
			cout << "\nPlease input an integer.\n";
		if (minLimit && IsInt(s) && StringToInt(s) < min)
			cout << "\nPlease input an integer larger or equal to " << min << ".\n";
		else if (maxLimit && IsInt(s) && StringToInt(s) > max)
			cout << "\nPlease input an integer smaller or equal to " << max << ".\n";
	} while (!IsInt(s) || (minLimit && IsInt(s) && StringToInt(s) < min) || (maxLimit && IsInt(s) && StringToInt(s) > max));
	
	return StringToInt(s);
}

/*********************************************************************
** Function: GetBool
** Description: Gets an boolean input from user
** Parameters: string, string, string
** Pre-Conditions: String is not empty
** Post-Conditions: Returns valid bool
*********************************************************************/
bool GetBool(string question, string yes = "yes", string no = "no")
{
	string s = "";
	
	if (yes == "")
		yes = "yes";
	if (no == "")
		no = "no";
	
	cout << endl << question << " (0-" << no << ", 1-" << yes << ") ";
	
	do
	{
		cin >> s;
		
		if (s != "0" && s != "1")
			cout << "\nPlease input either '0' or a '1'.\n";
	} while (s != "0" && s != "1");
	
	return s == "1";
}

/*********************************************************************
** Function: Print2DArray
** Description: Outpus a 2D integer array to the screen
** Parameters: string, int**, int, int
** Pre-Conditions: array is not empty, x and y accurately represents
**		   		   the rows and columns of the array, respectively
** Post-Conditions: None
*********************************************************************/
void Print2DArray(string s, int** array, int x, int y)
{
	cout << endl << s << ":";
	
	for (int i = 0; i <= x; i++)
	{
		cout << "\n\t";
		
		for (int j = 0; j < y && i < x; j++)
			cout << array[i][j] << '\t';
	}
}

/*********************************************************************
** Function: RandInt
** Description: Returns a random number between to integers
** Parameters: int, int
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int RandInt(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}