//****************************************************************************************************
//
//		File:					stack.h
//		
//		Name:					Alex Orescanin
//
//		This program will contain the definition of the main function 
//		that will read the .txt file and perform each opertaion  
// 
//		other files included: Stack.h, expressions.txt, results.txt
//		
//****************************************************************************************************

#include<iostream>
#include<fstream>
#include<cctype>
#include<cstdlib>

using namespace std;

#include "Stack.h"

//****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile);
void processNumber(char token[], Stack<int>& rpnStack, ofstream& resultsFile, const bool& isValid);
bool processOperator(char token[], Stack<int>& rpnStack, ofstream& resultsFile);
void displayResult(Stack<int>& rpnStack, ofstream& resultsFile, const bool& isValid);
void resetFlagStack(bool& isValid, Stack<int>& rpnStack);

//****************************************************************************************************

int main()
{
	Stack<int> rpnStack;
	char token[4];
	bool isValid = true;
	ifstream fin;
	ofstream fout;

	fin.open("expressions.txt");
	fout.open("results.txt");

	while (fin >> token)
	{
		outputToken(token, fout);

		if (token[0] == ';')
		{
			displayResult(rpnStack, fout, isValid);
			resetFlagStack(isValid, rpnStack);
		}
		else if (isdigit(token[0]))
		{
			processNumber(token, rpnStack, fout, isValid);
		}
		else if (ispunct(token[0]))
		{
			isValid = processOperator(token, rpnStack, fout);
		}
	}

	return 0;
}

//****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile)
{
	resultsFile << endl << "( Token:  " << token << " ) \t\t";

	if (token[0] != ';')
	{
		cout << token << " ";
	}
}

//****************************************************************************************************

void processNumber(char token[], Stack<int>& rpnStack, ofstream& resultsFile, const bool& isValid)
{
	int iVal;
	iVal = atoi(token);

	if (isValid)
	{
		rpnStack.push(iVal);
		resultsFile << '\t' << "Push " << iVal;
	}
}

//****************************************************************************************************

bool processOperator(char token[], Stack<int>& rpnStack, ofstream& resultsFile)
{
	bool success = false;
	int val1,
		val2,
		result;

	if ((rpnStack.pop(val2)) && (rpnStack.pop(val1)))
	{
		resultsFile << "\tPop  " << val2 << "\t\tPop  "
			<< val1;

		switch (token[0])
		{
		case '+': result = val1 + val2;
			rpnStack.push(result);
			break;

		case '-': result = val1 - val2;
			rpnStack.push(result);
			break;

		case '*': result = val1 * val2;
			rpnStack.push(result);
			break;

		case '/': result = val1 / val2;
			rpnStack.push(result);
			break;

		case '%': result = val1 % val2;
			rpnStack.push(result);
			break;
		}

		resultsFile << "\t\tPush " << result;
		success = true;
	}

	return success;
}

//****************************************************************************************************

void displayResult(Stack<int>& rpnStack, ofstream& resultsFile, const bool& isValid)
{
	int data;

	if ((rpnStack.pop(data)) && !(rpnStack.pop(data)))
	{
		cout << "= " << data << endl << endl;
		resultsFile << "\tPop  " << data << endl << "\t\t\t\t\tValid:\tresult = "
			<< data << endl << endl;
	}
	else if (!isValid)
	{
		cout << "\t\tinvalid" << endl << endl;
		resultsFile << endl << "\t\t\t\t\tInvalid RPN expression - too few operands"
			<< endl << endl;
	}
	else
	{
		cout << "\t\tinvalid" << endl << endl;
		resultsFile << endl << "\t\t\t\t\tInvalid RPN expression - too many operands"
			<< endl << endl;
	}
}

//****************************************************************************************************

void resetFlagStack(bool& isValid, Stack<int>& rpnStack)
{
	int iVal;
	isValid = true;
	while (rpnStack.pop(iVal));
}

/****************************************************************************************************

Sample Output:
2 4 * 5 + = 13

13 5 % 5 + = 8

15 1 + 2 / 1 - = 7

15 + 1 + 2 / 1 -                invalid

3 4 + 15 10 - * = 35

3 4 + 6 15 10 - *               invalid

2 13 + 14 6 - - 5 * 4 + = 39

35 6 4 2 2 / + * - = 5

3 4 + 1 2 - * 4 2 / 3 - + = -8

3 14 1 2 4 2 3 + % * + - + = 8

****************************************************************************************************/