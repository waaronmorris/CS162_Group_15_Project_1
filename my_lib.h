/********************************************************************* 
** Author: Ibrahim Mahmoud
** Date: 7/8/18
** Description: This is the header file for my_lib.cpp
*********************************************************************/ 

#ifndef MY_LIB
#define MY_LIB

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <locale>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

/*********************************************************************
** Function: CreateArray
** Description: Creates and initializes a new array
** Parameters: int
** Pre-Conditions: n is not negative
** Post-Conditions: Returns newly initialized array
*********************************************************************/
template <class T>
T* CreateArray(int n)
{
	T* array = new T[n];
	
	for (int i = 0; i < n; i++)
		array[i] = 0;
	
	return array;
}

/*********************************************************************
** Function: Create2DArray
** Description: Creates and initializes a new 2D array
** Parameters: int, int
** Pre-Conditions: Both x and y are not negative
** Post-Conditions: Returns newly initialized 2D array
*********************************************************************/
template <class T>
T** Create2DArray(int x, int y)
{
	T** array = new T*[x];
	
	for (int i = 0; i < x; i++)
		array[i] = CreateArray<T>(y);
	
	return array;
}

/*********************************************************************
** Function: DeleteArray
** Description: Deletes an array off the heap
** Parameters: T*
** Pre-Conditions: none
** Post-Conditions: Heap memory is freed
*********************************************************************/
template <class T>
void DeleteArray(T* array)
{
	if (array != NULL)
		delete [] array;
}

/*********************************************************************
** Function: Delete2DArray
** Description: Deletes a 2D array off the heap
** Parameters: T**, int
** Pre-Conditions: n accurately represents the number of rows
**				   in array
** Post-Conditions: Heap memory is freed
*********************************************************************/
template <class T>
void Delete2DArray(T** array, int n, bool pointerArray = false)
{
	for (int i = 0; i < n; i++)
		if (array[i] != NULL)
			if (pointerArray)
				delete array[i];
			else
				delete [] array[i];
	
	if (array != NULL)
		delete [] array;
}

/*********************************************************************
** Function: CopyArray
** Description: Copy the values of one array to another
** Parameters: T*, T*, int
** Pre-Conditions: None of the arrays are empty, and n accurately
**				   represents the size of the copy array
** Post-Conditions: none
*********************************************************************/
template <class T>
void CopyArray(T* original, T* copy, int n)
{
	if (n != 0)
	{
		original = new T[n];
		
		for (int i = 0; i < n; i++)
			original[i] = copy[i];
	}
	else
		original = NULL;
}

/*********************************************************************
** Function: CopyArray
** Description: Copy the values of one 2D array to another
** Parameters: T**, T**, int, int
** Pre-Conditions: None of the arrays are empty, and x and y
**				   accurately represents the size of the copy array
** Post-Conditions: none
*********************************************************************/
template <class T>
void Copy2DArray(T** original, T** copy, int x, int y)
{
	if (x != 0)
	{
		original = new T*[x];
		
		for (int i = 0; i < y; i++)
			CopyArray(original[i], copy[i], y);
	}
	else
		original = NULL;
}

/*********************************************************************
** Function: AddToArray
** Description: Adds an item to the end of an array
** Parameters: T**, int &, T
** Pre-Conditions: None of the arrays are empty, and n accurately
**				   represents the size of the copy array
** Post-Conditions: none
*********************************************************************/
template <class T>
void AddToArray(T** array, int &n, T item)
{
	n++;
	T* temp = new T[n];
	
	for (int i = 0; i < n - 1; i++)
		temp[i] = *array[i];
	
	temp[n - 1] = item;
	
	delete [] *array;
	*array = temp;
}

/*********************************************************************
** Function: RemoveFromArray
** Description: Removes an item from an array
** Parameters: T**, int &, int
** Pre-Conditions: None of the arrays are empty, and n accurately
**				   represents the size of the copy array
** Post-Conditions: none
*********************************************************************/
template <class T>
void RemoveFromArray(T** array, int &n, int index)
{
	n--;
	T* temp = new T[n];
	bool skipped = false;
	
	for (int i = 0; i < n + 1; i++)
		if (i != index)
			temp[i - (int) skipped] = *array[i];
		else
			skipped = true;
	
	delete [] *array;
	*array = temp;
}

struct Point
{
	double X;
	double Y;
};

enum ReturnType
{
	VOID, INT, DOUBLE, BOOL, CHAR, STRING,
};

enum Direction
{
	FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN
};

Direction OppositeDirection(Direction d);

string DirectionToString(Direction d);

void Divider();

int NumberOf(string s, char c);

bool CheckOnlyNumber(string s, bool dec);

bool CheckCorrectNegative(string);

bool IsInt(string);

string GetString(string);

int StringToInt(string);

int GetInt(string = "", bool = false, int = 0, bool = false, int = 0);

bool GetBool(string, string, string);

template <class T>
T* CreateArray(int);

template <class T>
T** Create2DArray(int, int);

template <class T>
void DeleteArray(T*);

template <class T>
void Delete2DArray(T**, int);

void Print2DArray(string, int**, int, int);

int RandInt(int min, int max);

#endif