//****************************************************************************************************
//
//		File:					queue.h
//		
//		Name:					Alex Orescanin
//
//		This program will contain the definition of the templated class "Queue"	
// 
// 		other files included: sim.cpp, node.h, customer.h, server.h, customerList.txt,
//								assumptions.txt, trace.txt	 
//		
//****************************************************************************************************

#ifndef QUEUE_H
#define QUEUE_H

//****************************************************************************************************

#include<new>
#include "node.h"

//****************************************************************************************************

template<typename TYPE>
class Queue
{
private:
	Node<TYPE>* front;
	Node<TYPE>* back;
	int numValues;

public:
	Queue();
	~Queue();
	bool enqueue(const TYPE& dataIn);
	bool dequeue(TYPE& dataOut);
	bool viewFront(TYPE& dataOut)const;
	bool viewRear(TYPE& dataOut)const;
	int getNumValues()const;
	bool isFull()const;
	bool isEmpty()const;
};
//****************************************************************************************************

template<typename TYPE>
Queue<TYPE>::Queue()
{
	front = nullptr;
	back = nullptr;
	numValues = 0;
}

//****************************************************************************************************

template<typename TYPE>
Queue<TYPE>::~Queue()
{
	Node<TYPE>* pDel;

	while (front)
	{
		pDel = front;
		front = front->next;
		delete pDel;
	}

	back = nullptr;
	numValues = 0;
}

//****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;
	pNew = new (nothrow) Node<TYPE>(dataIn);

	if (pNew)
	{
		if (back)
		{
			back->next = pNew;
		}
		else
		{
			front = pNew;
		}

		back = pNew;
		numValues++;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::dequeue(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDel = front;

	if (front)
	{
		dataOut = front->data;
		front = front->next;
		delete pDel;
		numValues--;

		if (numValues == 0)
		{
			back = nullptr;
		}

		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::viewFront(TYPE& dataOut)const
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
bool Queue<TYPE>::viewRear(TYPE& dataOut)const
{
	bool success = false;

	if (back)
	{
		dataOut = back->data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
int Queue<TYPE>::getNumValues()const
{
	return numValues;
}

//****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::isFull()const
{
	bool success = true;
	Node<TYPE>* pNew;
	pNew = new (nothrow) Node<TYPE>();

	if (pNew)
	{
		success = false;
		delete pNew;
		pNew = nullptr;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool Queue<TYPE>::isEmpty()const
{
	return (front == nullptr);
}

//****************************************************************************************************

#endif !QUEUE_H