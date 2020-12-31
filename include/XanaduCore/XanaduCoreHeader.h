#ifndef			_XANADU_CORE_HEADER_H_
#define			_XANADU_CORE_HEADER_H_

#include <XanaduRuntime/XanaduRuntime.h>

#ifndef			XANADU_CORE_BUILD_STATIC
#ifdef			XANADU_CORE_LIB
#ifdef XANADU_SYSTEM_WINDOWS
#define			XANADU_CORE_EXPORT					__declspec(dllexport)
#else
#define			XANADU_CORE_EXPORT					__attribute__((visibility("default")))
#endif//XANADU_SYSTEM_WINDOWS
#else
#ifdef XANADU_SYSTEM_WINDOWS
#define			XANADU_CORE_EXPORT					__declspec(dllimport)
#else
#define			XANADU_CORE_EXPORT					__attribute__((visibility("default")))
#endif//XANADU_SYSTEM_WINDOWS
#endif//XANADU_CORE_LIB
#else
#define			XANADU_CORE_EXPORT
#endif//XANADU_CORE_BUILD_STATIC
#define			XANADU_CORE_LOCAL

namespace Xanadu
{
	//大小写敏感性枚举
	enum CaseSensitivity
	{
		CaseInsensitive,						//不区分大小写
		CaseSensitive,							//区分大小写
	};

	//三项值
	enum Boolean
	{
		VALUE_NULL = -1,						//null value
		VALUE_FALSE = 0,						//false
		VALUE_TRUE = 1,							//true
	};
};

#endif//_XANADU_CORE_HEADER_H_