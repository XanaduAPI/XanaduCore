#ifndef			_XANADU_CORE_STRING_H_
#define			_XANADU_CORE_STRING_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <string>

typedef			wchar_t							XChar;
typedef			std::string						AString;
typedef			std::wstring						WString;
typedef			std::string						UString;
typedef			std::string						LString;
#ifdef XANADU_SYSTEM_WINDOWS
typedef			AString							NString;
#else
typedef			UString							NString;
#endif//XANADU_SYSTEM_WINDOWS

class XANADU_CORE_EXPORT XString : public std::wstring
{
public:
	using _MyBase = std::wstring;

public:
	XString() XANADU_NOTHROW;

	virtual ~XString() XANADU_NOTHROW;

public:
	XString& operator=(const XChar* _Memory) XANADU_NOTHROW;

	XString& operator=(const WString& _String) XANADU_NOTHROW;

	XString& operator=(const XString& _String) XANADU_NOTHROW;

	XString& operator=(XString&& _String) XANADU_NOTHROW;
};

#endif//_XANADU_CORE_STRING_H_