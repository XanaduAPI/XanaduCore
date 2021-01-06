#ifndef			_XANADU_CORE_BYTEARRAY_H_
#define			_XANADU_CORE_BYTEARRAY_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <vector>

/// <summary>
/// A byte array tool
/// </summary>
class XANADU_CORE_EXPORT XByteArray : public std::vector<char>
{
private:
	using	_BaseClass = std::vector<char>;

public:
	XByteArray() XANADU_NOTHROW : _BaseClass()
	{
	};

	XByteArray(const char* _Memory, int _Size = -1) XANADU_NOTHROW : _BaseClass(_Memory, _Size)
	{
	};

	XByteArray(int _Size, char _Char) XANADU_NOTHROW : _BaseClass(_Size, _Char)
	{
	};

	XByteArray(int _Size) XANADU_NOTHROW : _BaseClass(_Size)
	{
	};

	XByteArray(const XByteArray&) XANADU_NOTHROW : _BaseClass()
	{
	};

	virtual ~XByteArray() XANADU_NOTHROW
	{
	};

public:
	virtual char* data() XANADU_NOTHROW
	{
		return &_BaseClass::front();
	};

	virtual const char* data() const XANADU_NOTHROW
	{
		return &_BaseClass::front();
	};

	virtual int32S size()
	{
		return _BaseClass::size();
	};
};

#endif//_XANADU_CORE_BYTEARRAY_H_
