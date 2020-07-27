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