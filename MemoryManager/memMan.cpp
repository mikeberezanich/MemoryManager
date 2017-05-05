/********************************************************************************************

File: 		memMan.cpp
Authors: 	Mike Berezanich
			Ryan Gleason
			Connor Kosmorsky

Date: 		4/26/2017

Purpose:	Emulate a virtual memory manager using the following replacement policies:
			1. First in, First Out (FIFO)
			2. Least Recently Used (LRU)

*********************************************************************************************/

#include <vector>
#include "memMan.h"

vector<frame> memMap;
unsigned int timer;

memoryManager::memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : virtualMemoryManagerInterface(p, pS, nF, vA)
{
	//calls interface's constructor to set replacement policy, page size, num frames, and virtual address space size

	timer = 0;
	memMap.resize(nF);

	//initialize memMap frames
	for (unsigned int i = 0; i < nF; i++) {
		memMap[i].page = -1;
		memMap[i].time = -1;
	}
}

unsigned long long memoryManager::memoryAccess(unsigned long long address)
{
	unsigned int minTime = memMap[0].time;
	unsigned int nextFrame = 0;
	unsigned long long pgNum = address / int(pow(2, N));
	unsigned int offset = address % int(pow(2, N));
	bool inMap = false;

	timer++;

	unsigned int i;
	for (i = 0; i < numFrames && !inMap; i++) {
		//empty frame available
		if (memMap[i].time == -1) {
			memMap[i].page = pgNum;
			memMap[i].time = timer;
			inMap = true;
		}
		//found in memMap
		else if (memMap[i].page == pgNum) {
			//only wanna update with LRU because we need to use the original times to determine next for FIFO
			if (policy == LRU)
				memMap[i].time = timer;

			inMap = true;
		}
		//haven't found in memMap so keep track of next frame to go
		else {
			if (memMap[i].time < minTime) {
				nextFrame = i;
				minTime = memMap[i].time;
			}
		}

	}

	//if none of the pages in our map match the address's page, swap from main memory and update frame
	if (!inMap) {
		swap(nextFrame, memMap[nextFrame].page);

		memMap[nextFrame].page = pgNum;
		memMap[nextFrame].time = timer;

		//physical address of the next frame
		return nextFrame * (unsigned int)pow(2, N) + offset;
	}

	//physical address of empty/found frame
	return (i - 1) * (unsigned int)pow(2, N) + offset;
}
