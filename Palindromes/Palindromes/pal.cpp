//****************************************************************************************************
//
//		File:					pal.cpp
//		
//		Name:					Alex Orescanin
//
//		This program will house the main function and test for valid palindrome
// 
//		other files included: stack.h, queue.h, node.h, palindromes.txt	 
//		
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

#include "stack.h"
#include "queue.h"

//****************************************************************************************************

bool testNdisplayPal(Stack<char>& pStack, Queue<char>& pQueue);
char getPalType(bool isType2, bool isType3);
void displayPalResult(char palType, bool isPal);

//****************************************************************************************************

int main()
{
	Stack<char> pStack;
	Queue<char> pQueue;
	char pal[81];
	char palType;
	int length;
	bool isPal;
	ifstream fin;

	fin.open("palindromes.txt");

	while (fin.getline(pal, 81, '#'))
	{
		bool isType2 = false;
		bool isType3 = false;

		length = (int)strlen(pal);

		for (int i = 0; i < length; i++)
		{
			if (isalnum(pal[i]))
			{
				pal[i] = tolower(pal[i]);
				pStack.push(pal[i]);
				pQueue.enqueue(pal[i]);
			}
			else if (isspace(pal[i]))
			{
				isType2 = true;
			}
			else
			{
				isType3 = true;
			}
		}

		isPal = testNdisplayPal(pStack, pQueue);

		if (isPal)
		{
			palType = getPalType(isType2, isType3);
		}

		displayPalResult(palType, isPal);
	}

	return 0;
}

//****************************************************************************************************

bool testNdisplayPal(Stack<char>& pStack, Queue<char>& pQueue)
{
	bool success = true;
	char sData,
		qData;

	while (pStack.pop(sData) && pQueue.dequeue(qData))
	{
		if (sData != qData)
		{
			success = false;
		}

		cout << sData;
	}


	return success;
}

//****************************************************************************************************

char getPalType(bool isType2, bool isType3)
{
	char palType = '1';

	if (isType2 == true)
	{
		palType = '2';
	}

	if (isType3 == true)
	{
		palType = '3';
	}

	return palType;
}

//****************************************************************************************************

void displayPalResult(char palType, bool isPal)
{
	if (isPal)
	{
		cout << " - Type " << palType << endl;
	}
	else
	{
		cout << " - Invalid" << endl;
	}
}

/****************************************************************************************************

***Type 1 is no spaces or punctuation
***Type 2 is with spaces but no punctuation
***Type 3 is with punctuation(with or without spaces)
Sample Output: 
aha - Type 3
isitiitisi - Type 3
deed - Type 1
srotor - Invalid
neveroddoreven - Type 2
nolemonsnomelon - Type 3
racecar - Type 2
cimoc - Invalid
wasitacaroracatisaw - Type 3
yddad - Invalid

****************************************************************************************************/