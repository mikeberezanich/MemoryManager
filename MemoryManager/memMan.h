#include "virtualMemoryManagerInterface.hpp"

class memoryManager : public virtualMemoryManagerInterface
{
public:
	memoryManager(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA);
	unsigned long long memoryAccess(unsigned long long address) override;
	void swap(unsigned int frameNumber, unsigned int pageNumber);

	void firstInFirstOut();

	void leastRecentlyUsed();

	ReplacementPolicy policy;
	unsigned int pageSize;
	unsigned int numFrames;
	unsigned int virtualAddressSpaceSize;
};