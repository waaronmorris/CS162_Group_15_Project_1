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
		MenuItem(string, string, double, double, double);
		MenuItem(string, string, string, string, bool);
		MenuItem(string, string, string);
		MenuItem(string);
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
		double GetCurrentDouble();
		bool GetCurrentBool();
		char GetCurrentChar();
		string GetCurrentString();
		
		int GetIntInput();
		double GetDoubleInput();
		bool GetBoolInput();
		char GetCharInput();
		string GetStringInput();
};

#endif