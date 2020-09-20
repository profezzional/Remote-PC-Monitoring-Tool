#pragma once
#include "target.hpp"

// todo: add native dll/sl loader depending on arch

#include <functional>
#include <filesystem>
#include <string>
#include <string_view>

#ifdef TARGET_WINDOWS
#include <Windows.h>
#define EXTENSION ".dll"
#endif

#ifdef TARGET_UNIX
#include <dlfcn.h>
#define EXTENSION ".so"
#endif


class NativeLoader
{
#ifdef TARGET_WINDOWS
	HMODULE hModule = NULL;
#endif

#ifdef TARGET_UNIX
	void* hModule = nullptr;
#endif
public:
	NativeLoader(const std::string& moduleName)
	{
		
#ifdef TARGET_WINDOWS
		this->hModule = LoadLibraryA(std::string(moduleName + EXTENSION).c_str());
#endif

#ifdef TARGET_UNIX
	    this->hModule = dlopen(std::string(moduleName + EXTENSION).c_str(), RTLD_GLOBAL);
#endif
	}
	
	void* getFunctionAddress(std::string_view functionName)
	{

#ifdef TARGET_WINDOWS
		return GetProcAddress(this->hModule, functionName.data());
#endif

#ifdef TARGET_UNIX
	    return dlsym(this->hModule, functionName.data());
#endif
		
	}
	
};

#undef EXTENSION