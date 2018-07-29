/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/8/18
** Description: This is the header file for menu_item.cpp
*********************************************************************/ 

#ifndef MENU_ITEM
#define MENU_ITEM

#include "my_lib.h"

class MenuItem
{
	private:
		ReturnType type;
		string title;
		string prompt;
		string yesPrompt;
		string noPrompt;
		bool bounds;
		double minBound;
		double maxBound;
		int currentInt;
		double currentDouble;
		bool currentBool;
		char currentChar;
		string currentString;
	
	public:
		MenuItem();
<<<<<<< HEAD
		MenuItem(string, string, int, int, int, ReturnType = INT);
		MenuItem(string, string, double, double, double, ReturnType = DOUBLE);
		MenuItem(string, string, string, string, bool, ReturnType = BOOL);
		MenuItem(string, string, char, ReturnType = CHAR);
		MenuItem(string, string, string, ReturnType = STRING);
		MenuItem(string, ReturnType = VOID);
=======
		MenuItem(string, string, double, double, double);
		MenuItem(string, string, string, string, bool);
		MenuItem(string, string, string);
		MenuItem(string);
>>>>>>> 37572b50b943df1d58b254d35c1649e57240cb8f
		MenuItem(const MenuItem &);
		
		MenuItem& operator = (const MenuItem &);
		
		void SetType(ReturnType);
		ReturnType GetType();
		
		void SetTitle(string);
		string GetTitle(bool = true);
		
		void SetPrompt(string);
		string GetPrompt(bool = true);
		
		void SetYesPrompt(string);
		string GetYesPrompt();
		
		void SetNoPrompt(string);
		string GetNoPrompt();
		
		void ToggleBounds(bool);
		bool IsBoundsOn();
		
		void SetMinBound(double);
		double GetMinBound();
		
		void SetMaxBound(double);
		double GetMaxBound();
		
		int GetCurrentInt();
<<<<<<< HEAD
		void SetCurrentInt(int);
		
		double GetCurrentDouble();
		void SetCurrentDouble(double);
		
		bool GetCurrentBool();
		void SetCurrentBool(bool);
		
		char GetCurrentChar();
		void SetCurrentChar(char);
		
		string GetCurrentString();
		void SetCurrentString(string);
=======
		double GetCurrentDouble();
		bool GetCurrentBool();
		char GetCurrentChar();
		string GetCurrentString();
>>>>>>> 37572b50b943df1d58b254d35c1649e57240cb8f
		
		int GetIntInput();
		double GetDoubleInput();
		bool GetBoolInput();
		char GetCharInput();
		string GetStringInput();
};

#endif