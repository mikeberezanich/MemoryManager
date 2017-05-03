#include "memMan.h"

memoryManager::memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : virtualMemoryManagerInterface(p, pS, nF, vA)
{
	//calls interface's constructor which I believe sets the attributes itself
}

unsigned long long memoryManager::memoryAccess(unsigned long long address)
{
	int page, numSwaps, physicalAddress;
	bool needed = false;
	//depends which policy is being used
	//FIFO
	if (policy == FIFO) {
		firstInFirstOut();
	}
	else if (policy == LRU) {
		leastRecentlyUsed();
	}
	//find frame to insert page, determine if swap is necessary
	//page is found by finding page that needs to be swapped
	page = 0;


	//if swap is needed make it true 


	//swap necessary?
	if (needed) {
		swap(0, 0);
	}

	//"Function must not return until any page swapping is completed, if necessary"
	return physicalAddress;
}

void memoryManager::swap(unsigned int frameNumber, unsigned int pageNumber)
{
	
}

void memoryManager::firstInFirstOut() {

	//do work here 	

}

void memoryManager::leastRecentlyUsed() {

	//do work here

}