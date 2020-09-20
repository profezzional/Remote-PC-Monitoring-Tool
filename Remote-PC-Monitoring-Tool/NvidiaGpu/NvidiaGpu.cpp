#include "../server/target.hpp"
#include <string>

// todo: Add CMakeLists.txt file and update build scripts for this proj
#include "NvidiaGpuCommon.hpp"
#include <iostream>
#include <nvml.h>
#pragma comment(lib, "nvml.lib")

// todo: Validate this works on linux
#define EXPORT extern "C" _declspec(dllexport)

void initialize()
{
	static bool isInitialized = false;
	if (!isInitialized)
	{
		nvmlInit_v2();
	}
}

EXPORT int GetDeviceCount()
{
	initialize();
	unsigned int deviceCount = 0;
	nvmlReturn_t result = nvmlDeviceGetCount_v2(&deviceCount);
	if (result == NVML_SUCCESS)
	{
		return static_cast<int>(deviceCount);
	}
	std::cerr << result << std::endl;
	// todo: Add proper nullable return type
	return -1;
}

EXPORT std::string GetDeviceName(int deviceIndex)
{
	initialize();
	nvmlDevice_t hDevice = 0;
	if (nvmlDeviceGetHandleByIndex_v2(deviceIndex, &hDevice) == NVML_SUCCESS)
	{
		char deviceName[256];
		if (nvmlDeviceGetName(hDevice, deviceName, sizeof(deviceName)) == NVML_SUCCESS)
		{
			return std::string(deviceName);
		}
	}
	// todo: Add proper nullable return type
	return "ERROR";
}

EXPORT double GetDeviceTemp(int deviceIndex)
{
	initialize();
	nvmlDevice_t hDevice = 0;
	if (nvmlDeviceGetHandleByIndex_v2(deviceIndex, &hDevice) == NVML_SUCCESS)
	{
		unsigned int temp;
		if (nvmlDeviceGetTemperature(hDevice, NVML_TEMPERATURE_GPU, &temp) == NVML_SUCCESS)
		{
			return temp;
		}
	}
	// todo: Add proper nullable return type
	return -1;
}

EXPORT MemoryInfo GetMemoryInfo(int deviceIndex)
{
	initialize();
	nvmlDevice_t hDevice = 0;
	if (nvmlDeviceGetHandleByIndex_v2(deviceIndex, &hDevice) == NVML_SUCCESS)
	{
		nvmlMemory_t memoryInfo = {};
		if (nvmlDeviceGetMemoryInfo(hDevice, &memoryInfo) == NVML_SUCCESS)
		{
			return MemoryInfo{ memoryInfo.total, memoryInfo.free, memoryInfo.used };
		}
	}
	// todo: Add proper nullable return type
	return MemoryInfo{0, 0, 0};
}

