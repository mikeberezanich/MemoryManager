/********************************************************************************************

File: 		Proj3.cpp
Authors: 	Mike Berezanich
			Ryan Gleason
			Connor Kosmorsky

Date: 		4/26/2017

Purpose:	Testbench for our memory manager

*********************************************************************************************/

//#include "stdafx.h"
#include <iostream>
#include "memMan.h"

using namespace std;

//Testbench from https://github.com/dovedevic/CMPSC473-MemoryManagementTestBenches/blob/master/BarczysnkiJohnsonMakwanaTests/driver.cpp
int main() {
	unsigned int virtualAddressSize = -1, numFrames = -1, N = -1, policy = -1;
	unsigned long long address;

	cout << "Policy Number (LRU = 1, FIFO=0):  ";
	cin >> policy;
	cout << policy << endl;
	cout << "Enter N: ";
	cin >> N;
	cout << N << endl << "Number of Frames: ";
	cin >> numFrames;
	cout << numFrames << endl << "Virtual Address Size: ";
	cin >> virtualAddressSize;
	cout << virtualAddressSize << endl << endl;
	memoryManager mem = memoryManager(policy ? LRU : FIFO, N, numFrames, virtualAddressSize);

	cout << "Give an address: ";
	while (cin >> address) {
		cout << "\nAddress: " << address << endl;
		cout << "Physical memory: " << mem.memoryAccess(address) << endl;
		cout << "Total Swaps: " << mem.numberPageSwaps() << endl << endl;
		cout << "Give an address: ";
	}
	cout << "quit program" << endl;
	return 0;
}
