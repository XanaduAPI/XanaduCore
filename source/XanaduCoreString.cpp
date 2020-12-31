//
// Created by Administrator on 2020/12/31.
//

#include <XanaduCore/XanaduCoreString.h>

XString::XString() XANADU_NOTHROW
{
}

XString::~XString() XANADU_NOTHROW
{
}


XString& XString::operator=(const XChar* _Memory) XANADU_NOTHROW
{
	return *this;
}

XString& XString::operator=(const WString& _String) XANADU_NOTHROW
{
	return *this;
}

XString& XString::operator=(const XString& _String) XANADU_NOTHROW
{
	return *this;
}

XString& XString::operator=(XString&& _String) XANADU_NOTHROW
{
	return *this;
}
