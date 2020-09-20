#include "GraphicsCard.hpp"
#include "NvidiaGpu.hpp"

// todo: Change this so it doesn't leak memory
GraphicsCard* GraphicsCard::GetGraphicsCard()
{
	bool hasNvidiaGpu = false;
#ifdef TARGET_WINDOWS
	// todo: Fix this so it ain't so ghetto
	hasNvidiaGpu = LoadLibraryA("nvml.dll") != NULL;
#endif

	if (hasNvidiaGpu) return new NvidiaGpu();

	// todo: Add AMD support
	return nullptr;
}