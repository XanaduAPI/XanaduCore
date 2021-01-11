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

//一些C++头文件
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

/// Macro needed by Xanadu series
#define			XANADU_NEW						new(std::nothrow)
#define			XANADU_DELETE_ARR(_Value)				if(_Value){delete[] _Value;_Value = nullptr;}
#define			XANADU_DELETE_PTR(_Value)				if(_Value){delete _Value;	_Value = nullptr;}

namespace Xanadu
{
	/// Case Sensitivity Enum
	enum CaseSensitivity
	{
		CaseInsensitive,						/// no
		CaseSensitive,							/// yes
	};

	/// Trinomial value
	enum Boolean
	{
		VALUE_NULL = -1,						/// null value
		VALUE_FALSE = 0,						/// false
		VALUE_TRUE = 1,							/// true
	};
};

#endif//_XANADU_CORE_HEADER_H_
