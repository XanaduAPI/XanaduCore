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
	/// Iterator type definition
	typedef char*					iterator;
	typedef const char*				const_iterator;
	typedef iterator				Iterator;
	typedef const_iterator				ConstIterator;
	typedef std::reverse_iterator<iterator>		reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

	/// Iterator operation
	virtual iterator begin() XANADU_NOTHROW;

	/// Iterator operation
	virtual const_iterator begin() const XANADU_NOTHROW;

	/// Iterator operation
	virtual const_iterator cbegin() const XANADU_NOTHROW;

	/// Iterator operation
	virtual const_iterator constBegin() const XANADU_NOTHROW;

	/// Iterator operation
	virtual iterator end() XANADU_NOTHROW;

	/// Iterator operation
	virtual const_iterator end() const XANADU_NOTHROW;

	/// Iterator operation
	virtual const_iterator cend() const XANADU_NOTHROW;

	/// Iterator operation
	virtual const_iterator constEnd() const XANADU_NOTHROW;

	/// Iterator operation
	virtual reverse_iterator rbegin() XANADU_NOTHROW;

	/// Iterator operation
	virtual reverse_iterator rend() XANADU_NOTHROW;

	/// Iterator operation
	virtual const_reverse_iterator rbegin() const XANADU_NOTHROW;

	/// Iterator operation
	virtual const_reverse_iterator rend() const XANADU_NOTHROW;

	/// Iterator operation
	virtual const_reverse_iterator crbegin() const XANADU_NOTHROW;

	/// Iterator operation
	virtual const_reverse_iterator crend() const XANADU_NOTHROW;

public:
	/// Add at the front
	virtual XByteArray& prepend(char _Char) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(int _Count, char _Char) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String, int _Length) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(char _Char) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(int _Count, char _Char) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const char* _String) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const char* _String, int _Length) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int _Index, char _Char) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int _Index, int _Count, char _Char) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int _Index, const char* _String) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int _Index, const char* _String, int _Length) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int _Index, const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(int _Index, int _Length) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int _Index, int _Length, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int _Index, int _Length, const char* _After, int _Asize) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int _Index, int _Length, const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, const XByteArray& _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, int _Bsize, const char* _After, int _Asize) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const XByteArray& _Before, const XByteArray& _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const XByteArray& _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, const XByteArray& _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, char _After) XANADU_NOTHROW;

public:
	/// Convert to Base64
	virtual XByteArray ToBase64() const XANADU_NOTHROW;

	/// Convert to HEX
	virtual XByteArray ToHex() const XANADU_NOTHROW;

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
