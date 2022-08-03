//****************************************************************************************************
//
//		File:					server.h
//		
//		Name:					Alex Orescanin
//
//		This program will house the Server struct	 
// 
//		other files included: queue.h, node.h, customer.h, sim.cpp, customerList.txt,
//								assumptions.txt, trace.txt
//		
//****************************************************************************************************

#ifndef SERVER_H
#define SERVER_H

//****************************************************************************************************

struct Server
{
	int custId;
	int endTime;
	bool busy;

	Server();
};

//****************************************************************************************************

Server::Server()
{
	custId = 0;
	endTime = 0;
	busy = false;
}

//****************************************************************************************************

#endif !SERVER_H
