//
// Created by Administrator on 2020/12/31.
//

#include <XanaduCore/XanaduCoreByteArray.h>

XByteArray::XByteArray() XANADU_NOTHROW
{
}

XByteArray::XByteArray(const char* _Memory, int _Size) XANADU_NOTHROW
{
}

XByteArray::XByteArray(int _Size, char _Char) XANADU_NOTHROW
{
	resize(_Size);
}

XByteArray::XByteArray(int _Size) XANADU_NOTHROW
{
	resize(_Size);
}

XByteArray::XByteArray(const XByteArray& _Object) XANADU_NOTHROW
{
}

XByteArray::XByteArray(XByteArray&& _Object) XANADU_NOTHROW
{
}

XByteArray::~XByteArray() XANADU_NOTHROW
{
}


XByteArray& XByteArray::operator=(const char* _Memory) XANADU_NOTHROW
{
	return *this;
}

XByteArray& XByteArray::operator=(const XByteArray &) XANADU_NOTHROW
{
	return *this;
}

XByteArray& XByteArray::operator=(XByteArray &&other) XANADU_NOTHROW
{
	return *this;
}
