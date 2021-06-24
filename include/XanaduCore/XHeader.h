#ifndef			_XANADU_CORE_HEADER_H_
#define			_XANADU_CORE_HEADER_H_


// Redefine the platform macro used by Xanadu according to the platform specific macro
#if defined(_WIN32)
#define			_XANADU_SYSTEM_WINDOWS
#endif
#if defined (__linux__) || defined (_LINUX_)
#define			_XANADU_SYSTEM_LINUX
#endif
#if defined (__APPLE__)
#define			_XANADU_SYSTEM_MACOS
#endif
#if defined (__ANDROID__) || defined (ANDROID)
#define			_XANADU_SYSTEM_ANDROID
#define			_XANADU_SYSTEM_LINUX
#define 		_XANADU_SYSTEM_ARM
#endif
#if defined (__arm__) || defined (__ARM_ARCH)
#define			_XANADU_SYSTEM_LINUX
#define 		_XANADU_SYSTEM_ARM
#endif


// Redefine the compiler currently used by Xanadu according to the specific macro of the compiler
#if defined(__GNUC__)
#define 		_XANADU_COMPILE_GCC
#elif _MSC_VER
#define 		_XANADU_COMPILE_MSVC
#else
#define 		_XANADU_COMPILE_UNKNOWN
#endif


// Calling conventions used by Xanadu
#if defined(_XANADU_COMPILE_MSVC)
#define			XANADUAPI						__cdecl
#elif defined(_XANADU_COMPILE_GCC)
// #define		XANADUAPI						__attribute__((__cdecl__))
#define			XANADUAPI
#else
#define			XANADUAPI
#endif


// Include some C runtime library header files based on the operating system version
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/timeb.h>
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
#include <cwchar>
#include <cctype>
#include <cwctype>
#include <cinttypes>
#include <cstring>
#include <codecvt>
#include <locale>
#include <list>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
#include <locale>
#include <codecvt>
#include <string>
#include <cstring>
#include <algorithm>
#include <regex>
#include <map>
#include <functional>
#include <mutex>
#include <thread>
#if defined(_XANADU_SYSTEM_WINDOWS)
#include <io.h>
#include <direct.h>
#include <process.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <Iphlpapi.h>
#else
#if defined(_XANADU_SYSTEM_MACOS)
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

// Macro used by Xanadu
#define			XANADU_PATH						1024
#define			XANADU_CHECK(_Value, ...)				if(!(_Value)){	return __VA_ARGS__;	}
#define			XANADU_CHECK_RETURN(_Value, ...)			if(!(_Value)){	return __VA_ARGS__;	}
#if !defined(_XANADU_SYSTEM_WINDOWS)
#define			MAX_PATH						260
#define			_snprintf						snprintf
#endif
#define			XANADU_NEW						new(std::nothrow)
#define			XANADU_DELETE_ARR(_Value)				if(_Value){delete[] _Value;_Value = nullptr;}
#define			XANADU_DELETE_PTR(_Value)				if(_Value){delete _Value;	_Value = nullptr;}

template <class T> void PX_UNUSED(T const&) {}
#define			XANADU_UNPARAMETER(_Value)				PX_UNUSED(_Value)
#define			XANADU_NAME2STR(_Value)					(#_Value)
#define			XANADU_STR2WSTR(_String)				L##_String
#define			__XFILE__						__FILE__
#define			__XLINE__						__LINE__
#define			__XFUNCTION__						__FUNCTION__
#if defined(_XANADU_COMPILE_MSVC)
#define			__XFUNCSIG__						__FUNCSIG__
#else
#define			__XFUNCSIG__						__PRETTY_FUNCTION__
#endif
#define			__XTIMESTAMP__						__TIMESTAMP__


// Some size definitions
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


// Type definition of Xanadu
#define			XVector							std::vector
#define			XList							std::list
#define			XArray							std::array
#define			XMap							std::map
typedef			char							int8S;
typedef			unsigned char						int8U;
typedef			short							int16S;
typedef			unsigned short						int16U;
typedef			int							int32S;
typedef			unsigned int						int32U;
typedef			long long						int64S;
typedef			unsigned long long					int64U;
#if !defined(_XANADU_SYSTEM_WINDOWS)
typedef			void*							HANDLE;
#endif


// Xanadu.Runtime export declaration used by the project
#ifndef			_XANADU_CORE_BUILD_STATIC
#ifdef			_XANADU_CORE_BUILD_SHARED
#if defined(_XANADU_COMPILE_MSVC)
#define			XANADU_CORE_EXPORT					__declspec(dllexport)
#elif defined(_XANADU_COMPILE_GCC)
#define			XANADU_CORE_EXPORT					__attribute__((visibility("default")))
#else
#define			XANADU_CORE_EXPORT
#endif
#else
#if defined(_XANADU_COMPILE_MSVC)
#define			XANADU_CORE_EXPORT					__declspec(dllimport)
#elif defined(_XANADU_COMPILE_GCC)
#define			XANADU_CORE_EXPORT					__attribute__((visibility("default")))
#else
#define			XANADU_CORE_EXPORT
#endif
#endif
#else
#define			XANADU_CORE_EXPORT
#endif


// Xanadu.Runtime Size definition of integers
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

namespace Xanadu
{
	// Case Sensitivity Enum
	enum CaseSensitivity
	{
		CaseInsensitive,						// no
		CaseSensitive,							// yes
	};

	// Trinomial value
	enum Boolean
	{
		VALUE_NULL = -1,						// null value
		VALUE_FALSE = 0,						// false
		VALUE_TRUE = 1,							// true
	};
};

#endif
