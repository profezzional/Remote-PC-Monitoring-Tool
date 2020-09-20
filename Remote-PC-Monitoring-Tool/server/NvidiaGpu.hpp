#pragma once
#include "NativeLoader.hpp"
#include "GraphicsCard.hpp"

class NvidiaGpu : public GraphicsCard
{
public:
    NvidiaGpu()
    {
        NativeLoader loader("NvidiaGpu");
        void* pGetDeviceCount = loader.getFunctionAddress("GetDeviceCount");
        if (pGetDeviceCount != nullptr)
        {
            this->GetDeviceCount = (int(__fastcall*)(void))pGetDeviceCount;
        }

        void* pGetDeviceName = loader.getFunctionAddress("GetDeviceName");
        if (pGetDeviceName != nullptr)
        {
            this->GetDeviceName = (std::string(__fastcall*)(int))pGetDeviceName;
        }

        void* pGetDeviceTemp = loader.getFunctionAddress("GetDeviceTemp");
        if (pGetDeviceTemp != nullptr)
        {
            this->GetDeviceTemp = (double(__fastcall*)(int))pGetDeviceTemp;
        }

        void* pGetMemoryInfo = loader.getFunctionAddress("GetMemoryInfo");
        if (pGetMemoryInfo != nullptr)
        {
            this->GetMemoryInfo = (MemoryInfo(__fastcall*)(int))pGetMemoryInfo;
        }
    }

};