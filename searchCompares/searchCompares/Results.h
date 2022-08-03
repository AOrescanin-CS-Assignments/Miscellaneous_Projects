//****************************************************************************************************
//
//		File:					Results.h
//		
//		Name:					Alex Orescanin
// 
//		This program will contain the Results struct that will hold our 4 data members
// 
//		other files included: searches.cpp, ordered.txt, unordered.txt, searchNums.txt
//		
//****************************************************************************************************

#ifndef RESULTS_H
#define RESULTS_H

//****************************************************************************************************

struct Results
{
	int numSuccesses;
	int totalCompares;
	double percSuccesses;
	double avgNumCompares;

	Results();
};

//****************************************************************************************************

Results::Results()
{
	numSuccesses = 0;
	totalCompares = 0;
}

//****************************************************************************************************

#endif !RESULTS_H