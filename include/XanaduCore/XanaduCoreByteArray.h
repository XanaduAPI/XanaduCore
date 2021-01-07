#ifndef			_XANADU_CORE_BYTEARRAY_H_
#define			_XANADU_CORE_BYTEARRAY_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreAllocator.h>

/// <summary>
/// A byte array tool
/// </summary>
class XANADU_CORE_EXPORT XByteArray : private XAllocator
{
public:
	/// Constructors
	XByteArray() XANADU_NOTHROW;

	/// Constructors
	XByteArray(const char* _Memory, int _Size = -1) XANADU_NOTHROW;

	/// Constructors
	XByteArray(int _Size, char _Char) XANADU_NOTHROW;

	/// Constructors
	XByteArray(int _Size) XANADU_NOTHROW;

	/// Constructors
	XByteArray(const XByteArray&) XANADU_NOTHROW;

	/// Destructor
	virtual ~XByteArray();

public:
	/// operator overload =
	XByteArray& operator = (const char* _Memory) XANADU_NOTHROW;

	/// operator overload =
	XByteArray& operator = (const XByteArray& _Bytes) XANADU_NOTHROW;

	/// operator overload =
	XByteArray& operator = (XByteArray&& _Other) XANADU_NOTHROW;

public:
	/// operator overload +
	XByteArray operator + (char _Char) const XANADU_NOTHROW;

	/// operator overload +
	XByteArray operator + (const char* _Memory) const XANADU_NOTHROW;

	/// operator overload +
	XByteArray operator + (const XByteArray& _Bytes) const XANADU_NOTHROW;

public:
	/// operator overload +=
	XByteArray& operator += (char _Char) XANADU_NOTHROW;

	/// operator overload +=
	XByteArray& operator += (const char* _Memory) XANADU_NOTHROW;

	/// operator overload +=
	XByteArray& operator += (const XByteArray& _Bytes) XANADU_NOTHROW;

public:
	/// Get data pointer
	virtual char* data() XANADU_NOTHROW;

	/// Get data const pointer
	virtual const char* data() const XANADU_NOTHROW;

	/// Get data size
	virtual int32S size() const XANADU_NOTHROW;

public:
	/// Read by subscript
	virtual char at(int64S _Index) const XANADU_NOTHROW;

	/// Get the first one
	virtual char front() const XANADU_NOTHROW;

	/// Get the first one
	virtual char& front() XANADU_NOTHROW;

	/// Get the last one
	virtual char back() const XANADU_NOTHROW;

	/// Get the last one
	virtual char& back() XANADU_NOTHROW;

	/// Read by subscript
	virtual char& operator[](int64S _Index) XANADU_NOTHROW;

	/// Read by subscript
	virtual char operator[](int64S _Index) const XANADU_NOTHROW;

public:
	/// Convert to Base64
	XByteArray ToBase64() const XANADU_NOTHROW;

	/// Convert to HEX
	XByteArray ToHex() const XANADU_NOTHROW;

	/// Format from memory
	static XByteArray XANADUAPI FromMemory(const char* _Memory, int _Size) XANADU_NOTHROW;

	/// Format from Base64
	static XByteArray XANADUAPI FromBase64(const void* _Memory, int _Size) XANADU_NOTHROW;

	/// Format from Base64
	static XByteArray XANADUAPI FromBase64(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Format from HEX
	static XByteArray XANADUAPI FromHex(const void* _Memory, int _Size) XANADU_NOTHROW;

	/// Format from HEX
	static XByteArray XANADUAPI FromHex(const XByteArray& _Bytes) XANADU_NOTHROW;
};

#endif//_XANADU_CORE_BYTEARRAY_H_
