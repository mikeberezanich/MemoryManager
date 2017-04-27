/********************************************************************************************

File: 		Proj3.cpp
Authors: 	Mike Berezanich
		Ryan Gleason

Date: 		4/26/2017

Purpose:	Emulate a virtual memory manager using the following replacement policies:
			1. First in, First Out (FIFO)
			2. Least Recently Used (LRU)

	
*********************************************************************************************/

#include "stdafx.h"
#include <iostream>
#include "virtualMemoryManagerInterface.hpp"

using namespace std;

//data structure to keep track of frames
struct mem_map{
	ReplacementPolicy policy;
	unsigned int pageSize;
	unsigned int numFrames;
	unsigned int virtualAddressSpaceSize;
};

//FIFO
void firstInFirstOut() {

//do work here 	
		
}

　
//LRU
void leastRecentlyUsed() {

//do work here
	
}

unsigned long long memoryAccess(unsigned long long logicalAddress) {
	int page, numSwaps, physicalAddress;
	bool needed = false;

	mem_map mem;
	//depends which policy is being used
	//FIFO
	if (mem.policy == FIFO) {
		firstInFirstOut();
	}
	else if (mem.policy == LRU){
		leastRecentlyUsed();
	}
	//find frame to insert page, determine if swap is necessary
	//page is found by finding page that needs to be swapped
	page = 0;
	

	//if swap is needed make it true 
	

	//swap necessary?
	if (needed) {
		swap(0,0);
	} 
	
	//"Function must not return until any page swapping is completed, if necessary"
	return physicalAddress;
}

void swap(unsigned int frameNumber, unsigned int pageNumber) {
	//numberPageSwaps();
	
}

//input from constructor: replacemenet policy, pageSize, numFrames, virtualAddressSpaceSize
void storeInfo(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) {

	struct mem_map *mem = new mem_map;

	mem->policy = p;
	mem->pageSize = pS;
	mem->numFrames = nF;
	mem->virtualAddressSpaceSize = vA;

}

int main()
{
	//input: logical address
	//output: physical address	

    return 0;
}

　
