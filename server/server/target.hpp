#ifndef TARGET_DOT_HPP
#define TARGET_DOT_HPP
#endif

// macros for identifying the target to compile to

#ifdef _WIN32
#ifndef TARGET_WINDOWS
#define TARGET_WINDOWS
#endif
#elif __linux__
#ifndef TARGET_LINUX
#define TARGET_LINUX
#endif
#elif __APPLE__
#ifndef TARGET_OSX
#define TARGET_OSX
#endif
#endif


// debug logging to console
#if _DEBUG
#ifndef DEBUG_LOG
#define DEBUG_LOG(x) std::cout << (x) << std::endl
#endif
#else
#ifndef DEBUG_LOG
#define DEBUG_LOG(x)
#endif
#endif