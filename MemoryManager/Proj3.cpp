
　
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

	
}

　
//LRU
void leastRecentlyUsed() {

}

int memoryAccess(int logicalAddress) {
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
		swap();
	} 
	
	
	return physicalAddress;
}

void swap() {
	//numPageSwaps();
	
}

int main()
{
	//input from constructor: replacemenet policy, pageSize, numFrames, virtualAddressSpaceSize
	//input logical address
	//output: physical address

	/*
	virtualMemoryManagerInterface(p, pS, nF, vA) {
		mem.policy = p;
		mem.pageSize = pS;
		mem.numFrames = nF;
		mem.virtualAddressSpaceSize = vA;
	}
	*/

	int physicalAddress;
	int logicalAddress = 0;

	//virtualMemoryManagerInterface memoryManager; 
	//Start the process
	physicalAddress = memoryAccess(logicalAddress);
	

    return physicalAddress;
}

　
