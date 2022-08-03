//****************************************************************************************************
//
//		File:					sortCompares.cpp
//		
//		Name:					Alex Orescanin
//
//		This program will compare 6 sorting algorithms: insertion sort, selection sort, 
//		bubble sort, shell sort, heap sort, and quick sort
// 
//		other files included: results.h, ordered.txt, unordered.txt, reversed.txt
//		
//****************************************************************************************************

#include<iostream>
#include<fstream>
#include<iomanip>
#include<utility>

using namespace std;

#include "results.h"

//****************************************************************************************************

void getData(int list[], int size, const char filename[]);
void insertionSort(int list[], int size, int& comp, int& cpy);
void selectionSort(int list[], int size, int& comp, int& cpy);
void bubbleSort(int list[], int size, int& comp, int& cpy);
void shellSort(int list[], int size, int& comp, int& cpy);
void heapSort(int list[], int size, int& comp, int& cpy);
void _siftUp(int list[], int child, int& comp, int& cpy);
void _siftDown(int list[], int parent, int heapSize, int& comp, int& cpy);
void quickSort(int list[], int size, int& comp, int& cpy);
void _quickSort(int list[], int left, int right, int& comp, int& cpy);
void putMedianLeft(int list[], int left, int right, int& comp, int& cpy);
int partition(int list[], int left, int right, int& comp, int& cpy);
void calcResults(Results& result);
void displayResults(Results iResults, Results sResults, Results bResults,
					Results shResults, Results hResults, Results qResults);

//****************************************************************************************************

int main()
{
	int ordered[1000],
		unordered[1000],
		reversed[1000];

	Results iResults,
			sResults,
			bResults,
			shResults,
			hResults,
			qResults;

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	insertionSort(ordered, 1000, iResults.ordCompares, iResults.ordCopies);
	insertionSort(unordered, 1000, iResults.unOrdCompares, iResults.unOrdCopies);
	insertionSort(reversed, 1000, iResults.revOrdCompares, iResults.revOrdCopies);
	calcResults(iResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	selectionSort(ordered, 1000, sResults.ordCompares, sResults.ordCopies);
	selectionSort(unordered, 1000, sResults.unOrdCompares, sResults.unOrdCopies);
	selectionSort(reversed, 1000, sResults.revOrdCompares, sResults.revOrdCopies);
	calcResults(sResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	bubbleSort(ordered, 1000, bResults.ordCompares, bResults.ordCopies);
	bubbleSort(unordered, 1000, bResults.unOrdCompares, bResults.unOrdCopies);
	bubbleSort(reversed, 1000, bResults.revOrdCompares, bResults.revOrdCopies);
	calcResults(bResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	shellSort(ordered, 1000, shResults.ordCompares, shResults.ordCopies);
	shellSort(unordered, 1000, shResults.unOrdCompares, shResults.unOrdCopies);
	shellSort(reversed, 1000, shResults.revOrdCompares, shResults.revOrdCopies);
	calcResults(shResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	heapSort(ordered, 1000, hResults.ordCompares, hResults.ordCopies);
	heapSort(unordered, 1000, hResults.unOrdCompares, hResults.unOrdCopies);
	heapSort(reversed, 1000, hResults.revOrdCompares, hResults.revOrdCopies);
	calcResults(hResults);

	getData(ordered, 1000, "ordered.txt");
	getData(unordered, 1000, "unordered.txt");
	getData(reversed, 1000, "reversed.txt");
	quickSort(ordered, 1000, qResults.ordCompares, qResults.ordCopies);
	quickSort(unordered, 1000, qResults.unOrdCompares, qResults.unOrdCopies);
	quickSort(reversed, 1000, qResults.revOrdCompares, qResults.revOrdCopies);
	calcResults(qResults);

	displayResults(iResults, sResults, bResults, shResults, hResults, qResults);
}

//****************************************************************************************************

void getData(int list[], int size, const char filename[])
{
	int index = 0;
	ifstream inFile;
	inFile.open(filename);

	while ((index < size) && (inFile >> list[index]))
	{
		index++;
	}
}

//****************************************************************************************************

void insertionSort(int list[], int size, int& comp, int& cpy)
{
	int hold,
		j;

	for (int i = 1; i < size; i++)
	{
		hold = list[i];

		for (j = (i - 1); (j >= 0) && (++comp) && (list[j] > hold); j--)
		{
			list[j + 1] = list[j];
			cpy++;
		}

		list[j + 1] = hold;
		cpy += 2;
	}
}

//****************************************************************************************************

void selectionSort(int list[], int size, int& comp, int& cpy)
{
	int minIndex;

	for (int i = 0; i < (size - 1); i++)
	{
		minIndex = i;

		for (int j = (i + 1); j < size; j++)
		{
			if (list[j] < list[minIndex])
			{
				minIndex = j;
			}

			comp++;
		}

		swap(list[minIndex], list[i]);
		cpy += 3;
	}
}

//****************************************************************************************************

void bubbleSort(int list[], int size, int& comp, int& cpy)
{
	bool didSwap = true;

	for (int i = 0; (i < (size - 1)) && (didSwap); i++)
	{
		didSwap = false;

		for (int j = (size - 1); j > i; j--)
		{
			if (list[j] < list[j - 1])
			{
				swap(list[j], list[j - 1]);
				didSwap = true;
				cpy += 3;
			}

			comp++;
		}
	}
}

//****************************************************************************************************

void shellSort(int list[], int size, int& comp, int& cpy)
{
	int hold,
		j;

	for (int gap = (size / 2); gap >= 10; gap = gap / 2)
	{
		if (gap % 2 == 0)
		{
			gap++;
		}

		for (int i = gap; i < size; i++)
		{
			hold = list[i];

			for (j = (i - gap); (j >= 0) && (++comp) && (list[j] > hold); j = (j - gap))
			{
				list[j + gap] = list[j];
				cpy++;
			}

			list[j + gap] = hold;
			cpy += 2;
		}
	}

	insertionSort(list, size, comp, cpy);
}

//****************************************************************************************************

void heapSort(int list[], int size, int& comp, int& cpy)
{
	for (int i = 1; i < size; i++)
	{
		_siftUp(list, i, comp, cpy);
	}

	for (int j = (size - 1); j > 0; j--)
	{
		swap(list[0], list[j]);
		cpy += 3;

		_siftDown(list, 0, j, comp, cpy);
	}
}

//****************************************************************************************************

void _siftUp(int list[], int child, int& comp, int& cpy)
{
	int parent;

	if (child > 0)
	{
		parent = (child - 1) / 2;

		if (list[child] > list[parent])
		{
			swap(list[child], list[parent]);
			cpy += 3;

			_siftUp(list, parent, comp, cpy);
		}

		comp++;
	}
}

//****************************************************************************************************

void _siftDown(int list[], int parent, int heapSize, int& comp, int& cpy)
{
	int child;
	child = (2 * parent) + 1;

	if (child < heapSize)
	{
		if (((child + 1) < heapSize) && (++comp) && (list[child] < list[child + 1]))
		{
			child++;
		}

		if (list[parent] < list[child])
		{
			swap(list[parent], list[child]);
			cpy += 3;

			_siftDown(list, child, heapSize, comp, cpy);
		}

		comp++;
	}
}

//****************************************************************************************************

void quickSort(int list[], int size, int& comp, int& cpy)
{
	_quickSort(list, 0, (size - 1), comp, cpy);

	insertionSort(list, size, comp, cpy);
}

//****************************************************************************************************

void _quickSort(int list[], int left, int right, int& comp, int& cpy)
{
	int pivotPt;

	if (((right - left) + 1) > 10)
	{
		putMedianLeft(list, left, right, comp, cpy);

		pivotPt = partition(list, left, right, comp, cpy);

		_quickSort(list, left, (pivotPt - 1), comp, cpy);
		_quickSort(list, (pivotPt + 1), right, comp, cpy);
	}
}

//****************************************************************************************************
void putMedianLeft(int list[], int left, int right, int& comp, int& cpy)
{
	int mid = (left + right) / 2;

	if (list[left] < list[mid])
	{
		swap(list[left], list[mid]);
		cpy += 3;
	}

	if (list[mid] > list[right])
	{
		swap(list[mid], list[right]);
		cpy += 3;
	}

	if (list[left] > list[right])
	{
		swap(list[left], list[right]);
		cpy += 3;
	}

	comp += 3;
}

//****************************************************************************************************

int partition(int list[], int left, int right, int& comp, int& cpy)
{
	int gt = right,
		lte = left + 1;

	while (lte <= gt)
	{
		while (list[lte] <= list[left])
		{
			lte++;
			comp++;
		}

		comp++;

		while (list[gt] > list[left])
		{
			gt--;
			comp++;
		}

		comp++;

		if (lte < gt)
		{
			swap(list[lte], list[gt]);
			cpy += 3;
			lte++;
			gt--;
		}
	}

	swap(list[left], list[gt]);
	cpy += 3;

	return gt;
}

//****************************************************************************************************

void calcResults(Results& result)
{
	result.avgCompares = (result.ordCompares + result.unOrdCompares + result.revOrdCompares) / 3;
	result.avgCopies = (result.ordCopies + result.unOrdCopies + result.revOrdCopies) / 3;
}

//****************************************************************************************************

void displayResults(Results iResults, Results sResults, Results bResults,
	Results shResults, Results hResults, Results qResults)
{
	cout << right << setw(60) << "Compares / Copies" << endl << endl;
	cout << left << setw(20) << "Sorts:" << left << setw(20) << "Ordered"
		<< left << setw(20) << "UnOrdered" << left << setw(20) << "Reversed"
		<< left << setw(20) << "Average" << endl << endl;
	cout << left << setw(17) << "Insert" << iResults.ordCompares << " / "
		<< left << setw(14) << iResults.ordCopies << iResults.unOrdCompares << " / "
		<< left << setw(12) << iResults.unOrdCopies << iResults.revOrdCompares << " / "
		<< left << setw(14) << iResults.revOrdCopies << iResults.avgCompares << " / "
		<< left << setw(11) << iResults.avgCopies << endl << endl;
	cout << left << setw(15) << "Select" << sResults.ordCompares << " / "
		<< left << setw(13) << sResults.ordCopies << sResults.unOrdCompares << " / "
		<< left << setw(13) << sResults.unOrdCopies << sResults.revOrdCompares << " / "
		<< left << setw(13) << sResults.revOrdCopies << sResults.avgCompares << " / "
		<< left << setw(13) << sResults.avgCopies << endl << endl;
	cout << left << setw(17) << "Bubble" << bResults.ordCompares << " / "
		<< left << setw(14) << bResults.ordCopies << bResults.unOrdCompares << " / "
		<< left << setw(13) << bResults.unOrdCopies << bResults.revOrdCompares << " / "
		<< left << setw(13) << bResults.revOrdCopies << bResults.avgCompares << " / "
		<< left << setw(13) << bResults.avgCopies << endl << endl;
	cout << left << setw(15) << "Shell" << shResults.ordCompares << " / "
		<< left << setw(15) << shResults.ordCopies << shResults.unOrdCompares << " / "
		<< left << setw(15) << shResults.unOrdCopies << shResults.revOrdCompares << " / "
		<< left << setw(13) << shResults.revOrdCopies << shResults.avgCompares << " / "
		<< left << setw(13) << shResults.avgCopies << endl << endl;
	cout << left << setw(15) << "Heap" << hResults.ordCompares << " / "
		<< left << setw(15) << hResults.ordCopies << hResults.unOrdCompares << " / "
		<< left << setw(14) << hResults.unOrdCopies << hResults.revOrdCompares << " / "
		<< left << setw(13) << hResults.revOrdCopies << hResults.avgCompares << " / "
		<< left << setw(12) << hResults.avgCopies << endl << endl;
	cout << left << setw(15) << "Quick" << qResults.ordCompares << " / "
		<< left << setw(15) << qResults.ordCopies << qResults.unOrdCompares << " / "
		<< left << setw(15) << qResults.unOrdCopies << qResults.revOrdCompares << " / "
		<< left << setw(15) << qResults.revOrdCopies << qResults.avgCompares << " / "
		<< left << setw(15) << qResults.avgCopies << endl << endl;
}

/*

Sample Output:
										   Compares / Copies

Sorts:              Ordered             UnOrdered           Reversed            Average

Insert           999 / 1998          257314 / 258317      499500 / 501498        252604 / 253937

Select         499500 / 2997         499500 / 2997         499500 / 2997         499500 / 2997

Bubble           999 / 0             499065 / 768957       499500 / 1498500      333188 / 755819

Shell          6013 / 12026          20949 / 27513          13781 / 20780        13581 / 20106

Heap           22462 / 47922          17194 / 28575         15965 / 24948        18540 / 33815

Quick          8387 / 2760           10983 / 9179           8387 / 4260           9252 / 5399


*/