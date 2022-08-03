//****************************************************************************************************
//
//		File:					searches.cpp
//		
//		Name:					Alex Orescanin
//
//		This program will contain the main function that will perform the searches
// 
//		other files included: Results.h, ordered.txt, unordered.txt, searchNums.txt
//		
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Results.h"

//****************************************************************************************************

void getData(const char fileName[], int arr[], int size);
bool unOrdSearch(int arr[], int size, int searchKey, int& numCompares);
bool ordSearch(int arr[], int size, int searchKey, int& numCompares);
bool binSearch(int arr[], int size, int searchKey, int& numCompares);
void process(int arr[], int size, int searchNums[], Results& result,
			 bool(*search)(int arr[], int size, int searchKey, int& numCompares));
void updateStats(Results& result);
void display(Results unOrdResults, Results ordResults, Results binResults);

//****************************************************************************************************

int main()
{
	int unOrdList[1000],
		ordList[1000],
		searchNums[500];

	Results unOrdResults,
		ordResults,
		binResults;

	getData("unordered.txt", unOrdList, 1000);
	getData("ordered.txt", ordList, 1000);
	getData("searchNums.txt", searchNums, 500);

	process(unOrdList, 1000, searchNums, unOrdResults, unOrdSearch);
	process(ordList, 1000, searchNums, ordResults, ordSearch);
	process(ordList, 1000, searchNums, binResults, binSearch);

	updateStats(unOrdResults);
	updateStats(ordResults);
	updateStats(binResults);

	display(unOrdResults, ordResults, binResults);

	return 0;
}

//****************************************************************************************************

void getData(const char fileName[], int arr[], int size)
{
	ifstream fin(fileName);
	int counter = 0;

	while ((counter < size) && (fin >> arr[counter]))
	{
		counter++;
	}

	fin.close();
}

//****************************************************************************************************

bool unOrdSearch(int arr[], int size, int searchKey, int& numCompares)
{
	bool success = false;
	int i = 0;

	while ((i < size) && (++numCompares) && (arr[i] != searchKey))
	{
		i++;
	}

	if ((i < size) && (++numCompares) && (arr[i] == searchKey))
	{
		success = true;
	}

	return success;
}

//****************************************************************************************************

bool ordSearch(int arr[], int size, int searchKey, int& numCompares)
{
	bool success = false;
	int i = 0;

	while ((i < size) && (++numCompares) && (arr[i] < searchKey))
	{
		i++;
	}

	if ((i < size) && (++numCompares) && (arr[i] == searchKey))
	{
		success = true;
	}

	return success;
}

//****************************************************************************************************

bool binSearch(int arr[], int size, int searchKey, int& numCompares)
{
	bool success = false;
	int first = 0,
		last,
		middle;

	last = size - 1;

	while ((first <= last) && (success != true))
	{
		middle = (first + last) / 2;

		if ((++numCompares) && (arr[middle] == searchKey))
		{
			success = true;
		}
		else if ((++numCompares) && (arr[middle] < searchKey))
		{
			first = middle + 1;
		}
		else
		{
			last = middle - 1;

		}
	}

	return success;
}

//****************************************************************************************************

void process(int arr[], int size, int searchNums[], Results& result,
	bool(*search)(int arr[], int size, int searchKey, int& numCompares))
{
	int numCompares;

	for (int i = 0; i < 500; i++)
	{
		numCompares = 0;

		if (search(arr, size, searchNums[i], numCompares))
		{
			result.numSuccesses++;
		}

		result.totalCompares += numCompares;
	}
}

//****************************************************************************************************

void updateStats(Results& result)
{
	result.percSuccesses = (result.numSuccesses / 500.0) * 100.0;
	result.avgNumCompares = result.totalCompares / 500.0;
}

//****************************************************************************************************

void display(Results unOrdResults, Results ordResults, Results binResults)
{
	cout << right << setw(45) << "Unordered" << setw(15) << "Ordered" << endl
		<< right << setw(46) << "Sequential" << setw(16) << "Sequential"
		<< setw(13) << "Binary" << endl;
	cout << right << setw(44) << "Search" << setw(16) << "Search"
		<< setw(15) << "Search" << endl << endl;
	cout << left << setw(39) << "Number of Successful Searches" << unOrdResults.numSuccesses
		<< right << setw(16) << ordResults.numSuccesses << setw(15) << binResults.numSuccesses
		<< endl << endl;
	cout << left << setw(39) << "Percent of Successful Searches" << fixed << setprecision(2)
		<< unOrdResults.percSuccesses << "%" << right << setw(15) << fixed << setprecision(2)
		<< ordResults.percSuccesses << "%" << setw(14) << fixed << setprecision(2)
		<< binResults.percSuccesses << "%" << endl << endl;
	cout << left << setw(39) << "Average Compares / Search" << setprecision(0)
		<< unOrdResults.avgNumCompares << right << setw(16) << setprecision(0)
		<< ordResults.avgNumCompares << setw(14) << setprecision(0) << binResults.avgNumCompares;
}

/****************************************************************************************************

Sample Output:
									Unordered        Ordered
									Sequential      Sequential       Binary
									  Search          Search         Search

Number of Successful Searches          242             242            242

Percent of Successful Searches         48.40%          48.40%         48.40%

Average Compares / Search              946             227            19

****************************************************************************************************/