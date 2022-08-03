//****************************************************************************************************
//
//		File:					sim.cpp
//		
//		Name:				Alex Orescanin
//
//		This program will contain the main function and perform the simulation
// 
//		other files included: queue.h, node.h, customer.h, server.h, customerList.txt,
//								assumptions.txt, trace.txt
//		 
//****************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

#include "customer.h"
#include "server.h"
#include "queue.h"

//****************************************************************************************************

int fillCustomerArray(Customer cArray[]);
int findMinQ(Queue<Customer> cQueue[], const Server sArray[]);
void processCustomers(const Customer cArray[], const Server sArray[], Queue<Customer> cQueue[],
	int& currCustomer, const int numCustomers, const int time, ofstream& fout);
void processServers(Server sArray[], Queue<Customer> cQueue[], const int time, ofstream& fout);
bool isAllDone(const Queue<Customer> cQueue[], const Server sArray[],
	const int currCustomer, const int numCustomers);

//****************************************************************************************************

int main()
{
	int time = -1,
		currCuststomer = 0,
		numCustomers;
	Customer cArray[100];
	Server sArray[3];
	Queue<Customer> cQueue[3];
	ofstream fout("trace.txt");

	numCustomers = fillCustomerArray(cArray);

	while (!isAllDone(cQueue, sArray, currCuststomer, numCustomers))
	{
		time++;
		fout << "t = " << time << endl;
		processCustomers(cArray, sArray, cQueue, currCuststomer, numCustomers, time, fout);
		processServers(sArray, cQueue, time, fout);
		fout << endl;
	}

	cout << "All customer processed in " << time << " minutes" << endl;

	return 0;
}

//****************************************************************************************************

int fillCustomerArray(Customer cArray[])
{
	int index = 0,
		numCustomers = 0;

	Customer customer;
	ifstream fin;

	fin.open("customerList.txt");

	while (fin >> customer.id)
	{
		fin >> customer.arrivalTime;
		fin >> customer.serviceTime;

		cArray[index] = customer;
		index++;
		numCustomers++;
	}

	fin.close();

	return numCustomers;
}

//****************************************************************************************************

int findMinQ(Queue<Customer> cQueue[], const Server sArray[])
{
	int minQ = 0;
	int qSize[3];

	for (int i = 0; i < 3; i++)
	{
		qSize[i] = cQueue[i].getNumValues();

		if (sArray[i].busy == true)
		{
			qSize[i]++;
		}
	}

	if (qSize[minQ] > qSize[1])
	{
		minQ++;
	}

	if (qSize[minQ] > qSize[2])
	{
		minQ = 2;
	}

	return minQ;
}

//****************************************************************************************************

void processCustomers(const Customer cArray[], const Server sArray[], Queue<Customer> cQueue[],
	int& currCustomer, const int numCustomers, const int time, ofstream& fout)
{
	int minQ;

	while ((currCustomer < numCustomers) && (time == cArray[currCustomer].arrivalTime))
	{
		minQ = findMinQ(cQueue, sArray);
		cQueue[minQ].enqueue(cArray[currCustomer]);
		fout << "cust-id #" << cArray[currCustomer].id << " added to the queue " << minQ << endl;
		currCustomer++;
	}
}

//****************************************************************************************************

void processServers(Server sArray[], Queue<Customer> cQueue[], const int time, ofstream& fout)
{
	Customer tempCustomer;

	for (int i = 0; i < 3; i++)
	{
		if ((sArray[i].busy == false) || (sArray[i].endTime == time))
		{
			if (cQueue[i].dequeue(tempCustomer))
			{
				sArray[i].custId = tempCustomer.id;
				sArray[i].endTime = time + tempCustomer.serviceTime;
				sArray[i].busy = true;
				fout << "S" << i << " start serving cust-id #" << sArray[i].custId
					<< ", service length = " << tempCustomer.serviceTime
					<< ", service ends at t = " << sArray[i].endTime << endl;
			}
			else
			{
				sArray[i].busy = false;
				fout << "S" << i << " is not busy" << endl;
			}
		}
		else
		{
			fout << "S" << i << " serving cust-id #" << sArray[i].custId
				<< " until t = " << sArray[i].endTime << endl;
		}
	}
}

//****************************************************************************************************

bool isAllDone(const Queue<Customer> cQueue[], const Server sArray[],
	const int currCustomer, const int numCustomers)
{
	return((sArray[0].busy == false) && (sArray[1].busy == false) && (sArray[2].busy == false)
		&& (currCustomer + 1 >= numCustomers) && (cQueue[0].isEmpty())
		&& (cQueue[1].isEmpty() && cQueue[2].isEmpty()));
}

/****************************************************************************************************

Sample output:
All customer processed in 85 minutes

****************************************************************************************************/