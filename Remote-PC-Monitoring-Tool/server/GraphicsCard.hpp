#pragma once
#include <functional>
#include "target.hpp"
#include "../NvidiaGpu/NvidiaGpuCommon.hpp"


// AMD and NVIDIA cards will inherit from this class
class GraphicsCard
{
public:
    std::function<int(void)> GetDeviceCount;
    std::function<std::string(int deviceIndex)> GetDeviceName;
    std::function<double(int deviceIndex)> GetDeviceTemp;
    std::function<MemoryInfo(int deviceIndex)> GetMemoryInfo;

	// static function to get the GPU manufacturer and return a pointer to either an AMD or nvidia card
    static GraphicsCard* GetGraphicsCard();
};


