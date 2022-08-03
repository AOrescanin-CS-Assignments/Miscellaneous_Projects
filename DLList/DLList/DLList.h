//****************************************************************************************************
//
//		File:					DLList.h
//		
//		Name:					Alex Orescanin
//
//		This program will contain the definition of the templated class "DLList"
// 
//		other files included: studentList.cpp, Student.h, node.h, studentFile.txt
//		 	
//****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H

//****************************************************************************************************

#include<new>
#include "node.h"

//****************************************************************************************************

template<typename TYPE>
class DLList
{
private:
	Node<TYPE>* front;
	Node<TYPE>* rear;

public:
	DLList();
	~DLList();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataOut)const;
	bool viewFront(TYPE& dataOut)const;
	bool viewRear(TYPE& dataOut)const;
	void display()const;
	void displayReverse()const;
	int getNumValues()const;
	bool isEmpty()const;
	bool isFull()const;
};

//****************************************************************************************************

template<typename TYPE>
DLList<TYPE>::DLList()
{
	front = nullptr;
	rear = nullptr;
}

//****************************************************************************************************

template<typename TYPE>
DLList<TYPE>::~DLList()
{
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		pBefore = pTemp;
		pTemp = pTemp->next;
		delete pBefore;
	}

	front = nullptr;
	rear = nullptr;
}

//****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	while ((pAfter) && (pAfter->data < dataIn))
	{
		pAfter = pAfter->next;
	}

	if (pAfter)
	{
		pBefore = pAfter->prev;
	}
	else
	{
		pBefore = rear;
	}

	pNew = new (nothrow) Node<TYPE>(dataIn, pAfter, pBefore);

	if (pNew)
	{
		if (pBefore)
		{
			pBefore->next = pNew;
		}
		else
		{
			front = pNew;
		}

		if (pAfter)
		{
			pAfter->prev = pNew;
		}
		else
		{
			rear = pNew;
		}

		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDelete = front;

	while ((pDelete) && (pDelete->data < dataOut))
	{
		pDelete = pDelete->next;
	}

	if ((pDelete) && (pDelete->data == dataOut))
	{
		dataOut = pDelete->data;

		if (pDelete->prev)
		{
			(pDelete->prev)->next = pDelete->next;
		}
		else
		{
			front = pDelete->next;
		}

		if (pDelete->next)
		{
			(pDelete->next)->prev = pDelete->prev;
		}
		else
		{
			rear = pDelete->prev;
		}

		delete pDelete;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::retrieve(TYPE& dataOut)const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->data < dataOut))
	{
		pTemp = pTemp->next;
	}

	if ((pTemp) && (pTemp->data == dataOut))
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::viewFront(TYPE& dataOut)const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::viewRear(TYPE& dataOut)const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
void DLList<TYPE>::display()const
{
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		cout << pTemp->data;
		pTemp = pTemp->next;
	}
}

//****************************************************************************************************

template<typename TYPE>
void DLList<TYPE>::displayReverse()const
{
	Node<TYPE>* pTemp = rear;

	while (pTemp)
	{
		cout << pTemp->data;
		pTemp = pTemp->prev;
	}
}

//****************************************************************************************************

template<typename TYPE>
int DLList<TYPE>::getNumValues()const
{
	int numValues = 0;
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		numValues++;
		pTemp = pTemp->next;
	}

	return numValues;
}

//****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::isEmpty()const
{
	return (front == nullptr);
}

//****************************************************************************************************

template<typename TYPE>
bool DLList<TYPE>::isFull()const
{
	bool success = true;
	Node<TYPE>* pTemp;
	pTemp = new (nothrow) Node<TYPE>();

	if (pTemp)
	{
		success = false;
		delete pTemp;
		pTemp = nullptr;
	}

	return success;
}

//****************************************************************************************************

#endif !LLIST_H