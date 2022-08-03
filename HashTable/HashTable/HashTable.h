//****************************************************************************************************
//
//		File:					HashTable.h
//		
//		Name:					Alex Orescanin
//
//		This program will contain the Hash Table class
// 
//		other files included: studentList.cpp, student.h, node.h, studentFile.txt
//		
//****************************************************************************************************

#ifndef HASHTABLE_H
#define HASHTABLE_H

//****************************************************************************************************

#include<new>
#include "node.h"

//****************************************************************************************************

template<typename TYPE>
class HashTable
{
private:
	Node<TYPE>* table;
	int size;

	bool _isPrime(int s)const;
	int _hash(const TYPE& dataIn)const;
	void _tableOut(ostream& out)const;

public:
	HashTable(int s = 23);
	~HashTable();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataOut)const;
	bool isEmpty()const;
	void writeFile()const;
	void displayTable()const;
	void statistics()const;
};

//****************************************************************************************************

template<typename TYPE>
HashTable<TYPE>::HashTable(int s)
{
	if ((s % 2) != 0)
	{
		s += 2;
	}
	else
	{
		s += 1;
	}

	while (!_isPrime(s))
	{
		s += 2;
	}

	size = s;
	table = new Node<TYPE>[size];
}

//****************************************************************************************************

template<typename TYPE>
bool HashTable<TYPE>::_isPrime(int s)const
{
	bool success = true;

	if ((s % 3 == 0) || (s % 5 == 0) || (s % 7 == 0) || (s % 9 == 0) || (s % 11 == 0) ||
		(s % 13 == 0) || (s % 15 == 0) || (s % 17 == 0) || (s % 19 == 0))
	{
		success = false;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
HashTable<TYPE>::~HashTable()
{
	Node<TYPE>* pDel;
	Node<TYPE>* pBefore;

	for (int i = 0; i < size; i++)
	{
		if (table[i].next)
		{
			pDel = table[i].next;

			while (pDel)
			{
				pBefore = pDel;
				pDel = pDel->next;
				delete pBefore;
			}
		}
	}

	delete[] table;
	table = nullptr;
	size = 0;
}

//****************************************************************************************************

template<typename TYPE>
int HashTable<TYPE>::_hash(const TYPE& dataIn)const
{
	return (dataIn % size);
}

//****************************************************************************************************

template<typename TYPE>
bool HashTable<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;
	int loc;

	loc = _hash(dataIn);

	if (table[loc].data == 0)
	{
		table[loc].data = dataIn;
		success = true;
	}
	else
	{
		pNew = new (nothrow) Node<TYPE>(dataIn, table[loc].next);

		if (pNew)
		{
			table[loc].next = pNew;
			success = true;
		}
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool HashTable<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	int loc;
	Node<TYPE>* pPrev;
	Node<TYPE>* pTemp;

	loc = _hash(dataOut);
	pPrev = &(table[loc]);
	pTemp = table[loc].next;

	if (table[loc].data == dataOut)
	{
		dataOut = table[loc].data;

		if (pTemp)
		{
			table[loc] = *pTemp;
			delete pTemp;
		}
		else
		{
			table[loc].data = 0;
		}

		success = true;
	}
	else if (table[loc].next != nullptr)
	{
		while ((pTemp) && (pTemp->data != dataOut))
		{
			pPrev = pTemp;
			pTemp = pTemp->next;
		}

		if ((pTemp) && (pTemp->data == dataOut))
		{
			dataOut = pTemp->data;

			if (pPrev)
			{
				pPrev->next = pTemp->next;
			}

			delete pTemp;

			success = true;
		}
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool HashTable<TYPE>::retrieve(TYPE& dataOut)const
{
	bool success = true;
	int loc;
	Node<TYPE>* pTemp;

	loc = _hash(dataOut);

	if (table[loc].data == dataOut)
	{
		dataOut = table[loc].data;
		success = true;
	}
	else if (table[loc].next != nullptr)
	{
		pTemp = table[loc].next;

		while ((pTemp) && (pTemp->data != dataOut))
		{
			pTemp = pTemp->next;
		}

		if ((pTemp) && (pTemp->data == dataOut))
		{
			dataOut = pTemp->data;
			success = true;
		}
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool HashTable<TYPE>::isEmpty()const
{
	bool success = true;
	int index = 0;

	while ((index < size) && (success == true))
	{
		if (table[index].data != 0)
		{
			success = false;
		}

		index++;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
void HashTable<TYPE>::writeFile()const
{
	ofstream fout("studentTable.txt");

	_tableOut(fout);

	fout.close();
}

//****************************************************************************************************

template<typename TYPE>
void HashTable<TYPE>::displayTable()const
{
	_tableOut(cout);
}

//****************************************************************************************************

template<typename TYPE>
void HashTable<TYPE>::_tableOut(ostream& out)const
{
	Node<TYPE>* pTemp;

	out << "Address Prime Area" << setw(18) << "Overflow" << endl;

	for (int i = 0; i < size; i++)
	{
		out << "[";

		if (i < 10)
		{
			out << "0";
		}

		out << i << "]";

		if (table[i].data != 0)
		{
			out << setw(7) << table[i].data;
			out << setw(4) << " ";

			pTemp = table[i].next;

			while (pTemp)
			{
				out << right << setw(8) << pTemp->data;

				if (pTemp->next)
				{
					out << ",";
				}
				pTemp = pTemp->next;
			}
		}

		out << endl;
	}
}

//****************************************************************************************************

template<typename TYPE>
void HashTable<TYPE>::statistics()const
{
	int numElements = 0,
		numEmpty = 0,
		numChains = 0,
		chainLen,
		longestChain = 0,
		numColl = 0,
		numSteps = 0;

	double avgChainLen,
		percColl,
		loadFactor,
		avgNumSteps;

	Node<TYPE>* pTemp;

	for (int i = 0; i < size; i++)
	{
		if (table[i].data != 0)
		{
			numElements++;
			numSteps++;
		}
		else
		{
			numEmpty++;
		}

		pTemp = table[i].next;

		if (pTemp)
		{
			numChains++;
		}

		chainLen = 0;

		while (pTemp)
		{
			numElements++;
			chainLen++;
			numColl++;
			numSteps += (chainLen + 1);
			pTemp = pTemp->next;
		}

		if (chainLen > longestChain)
		{
			longestChain = chainLen;
		}
	}

	avgChainLen = numColl / double(numChains);
	percColl = (numColl / double(numElements)) * 100.0;
	loadFactor = ((size - numEmpty) / double(size)) * 100.0;
	avgNumSteps = numSteps / double(numElements);

	cout << left << setw(29) << "Table size: " << size << endl << endl
		<< left << setw(29) << "Number of elements: " << numElements << endl << endl
		<< left << setw(29) << "Empty positions: " << numEmpty << endl << endl
		<< left << setw(29) << "Number of chains: " << numChains << endl << endl
		<< left << setw(29) << "Max chain length: " << longestChain << endl << endl
		<< left << setw(29) << "Number of collisions: " << numColl << endl << endl
		<< left << setw(29) << "Average chain length: " << fixed << setprecision(1) << avgChainLen
		<< endl << endl
		<< left << setw(29) << "Percentage collisions: " << fixed << setprecision(1) << percColl
		<< " %" << endl << endl
		<< left << setw(29) << "Load factor: " << fixed << setprecision(1) << loadFactor << " %"
		<< endl << endl
		<< left << setw(29) << "Average # search steps: " << fixed << setprecision(3) << avgNumSteps
		<< endl << endl;
}

//****************************************************************************************************

#endif !HASHTABLE_H