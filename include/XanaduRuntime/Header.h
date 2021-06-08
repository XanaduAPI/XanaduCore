#ifndef			_XANADU_RUNTIME_HEADER_H_
#define			_XANADU_RUNTIME_HEADER_H_


// 根据平台的特定宏重新定义Xanadu系列所使用的平台宏
#if defined(_WIN32)
#define			XANADU_SYSTEM_WINDOWS
#endif
#if defined (__linux__) || defined (_LINUX_)
#define			XANADU_SYSTEM_LINUX
#endif
#if defined (__APPLE__)
#define			XANADU_SYSTEM_MACOS
#endif
#if defined (__ANDROID__) || defined (ANDROID)
#define			XANADU_SYSTEM_ANDROID
#define			XANADU_SYSTEM_LINUX
#define 		XANADU_SYSTEM_ARM
#endif
#if defined (__arm__) || defined (__ARM_ARCH)
#define			XANADU_SYSTEM_LINUX
#define 		XANADU_SYSTEM_ARM
#endif


// 根据编译器的特定宏重新定义Xanadu当前使用的编译器
#if defined(__GNUC__)
#define 		XANADU_COMPILE_GCC
#elif _MSC_VER
#define 		XANADU_COMPILE_MSVC
#else
#define 		XANADU_COMPILE_UNKNOWN
#endif


// Xanadu系列使用的调用约定
#if defined(XANADU_COMPILE_MSVC)
#define			XANADUAPI						__cdecl
#elif defined(XANADU_COMPILE_GCC)
// #define		XANADUAPI						__attribute__((__cdecl__))
#define			XANADUAPI
#else
#define			XANADUAPI
#endif // XANADU_COMPILE_MSVC


// 根据操作系统版本包含一些C运行时库头文件
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>
#include <fcntl.h>
#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cfloat>
#if defined(XANADU_SYSTEM_WINDOWS)
#include <io.h>
#include <direct.h>
#include <process.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <Iphlpapi.h>
#else
#ifdef XANADU_SYSTEM_MACOS
#include <sys/uio.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <objc/objc.h>
#include <objc/message.h>
#include <xlocale.h>
#else
#include <sys/io.h>
#include <sys/vfs.h>
#include <locale.h>
#endif
#include <wctype.h>
#include <unistd.h>
#include <utime.h>
#include <fcntl.h>
#include <stdarg.h>
#include <dlfcn.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <sys/statvfs.h>
#include <netdb.h>
#include <signal.h>
#include <sys/wait.h>
#include <pthread.h>
#endif

// 一些Xanadu系列使用的宏
#define			XANADU_PATH						1024
#define			XANADU_CHECK(_Value, ...)				if(!(_Value)){	return __VA_ARGS__;	}
#define			XANADU_CHECK_RETURN(_Value, ...)			if(!(_Value)){	return __VA_ARGS__;	}

#if !defined(XANADU_SYSTEM_WINDOWS)
#define			MAX_PATH						260
#define			_snprintf						snprintf
#endif

template <class T> void PX_UNUSED(T const&) {}
#define			XANADU_UNPARAMETER(_Value)				PX_UNUSED(_Value)
#if defined(XANADU_COMPILE_MSVC)
#define			XANADU_DEPRECATED					__declspec(deprecated)
#elif defined(XANADU_COMPILE_GCC)
#define			XANADU_DEPRECATED					__attribute__((deprecated))
#else
#define			XANADU_DEPRECATED
#endif
#define			XANADU_NAME2STR(_Value)					(#_Value)
#define			XANADU_STR2WSTR(_String)				L##_String
#define			__XFILE__						__FILE__
#define			__XLINE__						__LINE__
#define			__XFUNCTION__						__FUNCTION__
#if defined(XANADU_COMPILE_MSVC)
#define			__XFUNCSIG__						__FUNCSIG__
#else
#define			__XFUNCSIG__						__PRETTY_FUNCTION__
#endif
#define			__XTIMESTAMP__						__TIMESTAMP__


// 一些大小定义
#define			XANADU_SIZE_PHASE					(1024)
#define			XANADU_SIZE_BIT						(8)
#define			XANADU_SIZE_BYTE					(1)
#define			XANADU_SIZE_KB						(XANADU_SIZE_PHASE * XANADU_SIZE_BYTE)
#define			XANADU_SIZE_MB						(XANADU_SIZE_PHASE * XANADU_SIZE_KB)
#define			XANADU_SIZE_GB						(XANADU_SIZE_PHASE * XANADU_SIZE_MB)
#define			XANADU_SIZE_TB						(XANADU_SIZE_PHASE * XANADU_SIZE_GB)
#define			XANADU_SIZE_PB						(XANADU_SIZE_PHASE * XANADU_SIZE_TB)
#define			XANADU_SIZE_EB						(XANADU_SIZE_PHASE * XANADU_SIZE_PB)
#define			XANADU_SIZE_ZB						(XANADU_SIZE_PHASE * XANADU_SIZE_EB)
#define			XANADU_SIZE_YB						(XANADU_SIZE_PHASE * XANADU_SIZE_ZB)
#define			XANADU_SIZE_BB						(XANADU_SIZE_PHASE * XANADU_SIZE_YB)
#define			XANADU_SIZE_NB						(XANADU_SIZE_PHASE * XANADU_SIZE_BB)
#define			XANADU_SIZE_DB						(XANADU_SIZE_PHASE * XANADU_SIZE_NB)
#define			XANADU_SIZE_CB						(XANADU_SIZE_PHASE * XANADU_SIZE_DB)


// Xanadu的类型定义
typedef			char							int8S;
typedef			unsigned char						int8U;
typedef			short							int16S;
typedef			unsigned short						int16U;
typedef			int							int32S;
typedef			unsigned int						int32U;
typedef			long long						int64S;
typedef			unsigned long long					int64U;
#if !defined(XANADU_SYSTEM_WINDOWS)
typedef			void*							HANDLE;
#endif


// Xanadu.Runtime 项目使用的运行时导出声明
#ifndef			_XANADU_RUNTIME_BUILD_STATIC
#ifdef			_XANADU_RUNTIME_BUILD_SHARED
#if defined(XANADU_COMPILE_MSVC)
#define			XANADU_RUNTIME_EXPORT					__declspec(dllexport)
#elif defined(XANADU_COMPILE_GCC)
#define			XANADU_RUNTIME_EXPORT					__attribute__((visibility("default")))
#else
#define			XANADU_RUNTIME_EXPORT
#endif
#else
#if defined(XANADU_COMPILE_MSVC)
#define			XANADU_RUNTIME_EXPORT					__declspec(dllimport)
#elif defined(XANADU_COMPILE_GCC)
#define			XANADU_RUNTIME_EXPORT					__attribute__((visibility("default")))
#else
#define			XANADU_RUNTIME_EXPORT
#endif
#endif
#else
#define			XANADU_RUNTIME_EXPORT
#endif


// Xanadu.Runtime 整数的大小定义
#define 		XANADU_INT16S_MIN					(-32768)
#define 		XANADU_INT16S_MAX					(0x7FFF)
#define 		XANADU_INT16U_MIN					(0U)
#define 		XANADU_INT16U_MAX					(0xFFFFU)
#define 		XANADU_INT32S_MIN					(-2147483647 - 1)
#define 		XANADU_INT32S_MAX					(0x7FFFFFFF)
#define 		XANADU_INT32U_MIN					(0U)
#define 		XANADU_INT32U_MAX					(0xFFFFFFFFU)
#define 		XANADU_INT64S_MIN					(-9223372036854775807 - 1)
#define 		XANADU_INT64S_MAX					(0x7FFFFFFFFFFFFFFFLL)
#define 		XANADU_INT64U_MIN					(0ULL)
#define 		XANADU_INT64U_MAX					(0xFFFFFFFFFFFFFFFFULL)

#endif
