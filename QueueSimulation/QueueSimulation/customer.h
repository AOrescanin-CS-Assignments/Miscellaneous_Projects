//****************************************************************************************************
//
//		File:					customer.h
//		
//		Name:					Alex Orescanin
//
//		This program will house the Customer struct
// 
//		other files included: queue.h, node.h, sim.cpp, server.h, customerList.txt,
//								assumptions.txt, trace.txt
//		 		
//****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//****************************************************************************************************

struct Customer
{
	int id;
	int arrivalTime;
	int serviceTime;

	Customer();
};

//****************************************************************************************************

Customer::Customer()
{
	id = 0;
	arrivalTime = 0;
	serviceTime = 0;
}

//****************************************************************************************************

#endif !CUSTOMER_H