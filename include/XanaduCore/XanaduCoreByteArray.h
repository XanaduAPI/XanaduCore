#ifndef			_XANADU_CORE_BYTEARRAY_H_
#define			_XANADU_CORE_BYTEARRAY_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <vector>

class XANADU_CORE_EXPORT XByteArray : public std::vector<char>
{
public:
	using _MyBase = std::vector<char>;

public:
	XByteArray() XANADU_NOTHROW;

	XByteArray(const char* _Memory, int _Size = -1) XANADU_NOTHROW;

	XByteArray(int _Size, char _Char) XANADU_NOTHROW;

	XByteArray(int _Size) XANADU_NOTHROW;

	XByteArray(const XByteArray& _Object) XANADU_NOTHROW;

	XByteArray(XByteArray&& _Object) XANADU_NOTHROW;

	virtual ~XByteArray() XANADU_NOTHROW;

public:
	XByteArray& operator=(const char* _Memory) XANADU_NOTHROW;

	XByteArray& operator=(const XByteArray &) XANADU_NOTHROW;

	XByteArray& operator=(XByteArray &&other) XANADU_NOTHROW;
};

#endif//_XANADU_CORE_BYTEARRAY_H_