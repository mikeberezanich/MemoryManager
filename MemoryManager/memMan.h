/********************************************************************************************

File: 		memMan.h
Authors: 	Mike Berezanich
			Ryan Gleason
			Connor Kosmorsky

Date: 		4/26/2017

Purpose:	Header file for memoryManager class

*********************************************************************************************/

#include "virtualMemoryManagerInterface.hpp"

typedef struct {
	unsigned long long page;
	unsigned int time;
} frame;

class memoryManager : public virtualMemoryManagerInterface
{
public:
	memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA);
	unsigned long long memoryAccess(unsigned long long address) override;

	void firstInFirstOut(unsigned long long address);
	void leastRecentlyUsed(unsigned long long address);
};