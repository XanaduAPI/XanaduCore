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
	/// Subscript returned when no matching data is found
	static const int64S				npos = XAllocator::npos;

public:
	/// Constructors
	XByteArray() XANADU_NOTHROW;

	/// Constructors
	XByteArray(const char* _Memory, int64S _Size = -1) XANADU_NOTHROW;

	/// Constructors
	XByteArray(int64S _Size, char _Char) XANADU_NOTHROW;

	/// Constructors
	XByteArray(int64S _Size) XANADU_NOTHROW;

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
	virtual int64S size() const XANADU_NOTHROW;

	/// resize
	virtual void resize(int64S _Size) XANADU_NOTHROW;

	/// Fills a character to the specified length of space, or if -1, all of it
	virtual XByteArray& fill(char _Char, int64S _Size = -1) XANADU_NOTHROW;

	/// Get the current capacity
	virtual int64S capacity() const XANADU_NOTHROW;

	/// Check for null values
	virtual bool isEmpty() const XANADU_NOTHROW;

	/// Check if there is a value
	virtual bool isExist() const XANADU_NOTHROW;

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
	/// Vector compatibility: increments to the last bit
	virtual void push_back(char _Char) XANADU_NOTHROW;

	/// Vector compatibility: increments to the last bit
	virtual void push_back(const char* _Memory) XANADU_NOTHROW;

	/// Vector compatibility: increments to the last bit
	virtual void push_back(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Vector compatible: increments to the first
	virtual void push_front(char _Char) XANADU_NOTHROW;

	/// Vector compatible: increments to the first
	virtual void push_front(const char* _Memory) XANADU_NOTHROW;

	/// Vector compatible: increments to the first
	virtual void push_front(const XByteArray& _Bytes) XANADU_NOTHROW;

public:
	/// Add at the front
	virtual XByteArray& prepend(char _Char) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(int64S _Count, char _Char) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String, int64S _Length) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(char _Char) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(int64S _Count, char _Char) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const char* _String) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const char* _String, int64S _Length) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64S _Index, char _Char) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64S _Index, int64S _Count, char _Char) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64S _Index, const char* _String) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64S _Index, const char* _String, int64S _Length) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64S _Index, const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(int64S _Index, int64S _Length) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int64S _Index, int64S _Length, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int64S _Index, int64S _Length, const char* _After, int64S _Asize) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int64S _Index, int64S _Length, const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, const XByteArray& _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, int64S _Bsize, const char* _After, int64S _Asize) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const XByteArray& _Before, const XByteArray& _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const XByteArray& _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, const XByteArray& _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, char _After) XANADU_NOTHROW;

public:
	/// Get the data on the left by length
	virtual XByteArray left(int64S _Length) const XANADU_NOTHROW;

	/// Get the data on the right by length
	virtual XByteArray right(int64S _Length) const XANADU_NOTHROW;

	/// Retrieve the middle data by length
	virtual XByteArray mid(int64S _Index, int64S _Length = XByteArray::npos) const XANADU_NOTHROW;

public:
	/// Check if the head is the same
	virtual bool startsWith(char _Char) const XANADU_NOTHROW;

	/// Check if the head is the same
	virtual bool startsWith(const char* _Memory) const XANADU_NOTHROW;

	/// Check if the head is the same
	virtual bool startsWith(const XByteArray& _Bytes) const XANADU_NOTHROW;

	/// Check if the tails are the same
	virtual bool endsWith(char _Char) const XANADU_NOTHROW;

	/// Check if the tails are the same
	virtual bool endsWith(const char* _Memory) const XANADU_NOTHROW;

	/// Check if the tails are the same
	virtual bool endsWith(const XByteArray& _Bytes) const XANADU_NOTHROW;

public:
	/// Find in positive order from the specified location
	virtual int64S find(char _Char, int64S _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64S find(const char* _Memory, int64S _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64S find(const XByteArray& _Bytes, int64S _From = 0) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64S rfind(char _Char, int64S _From = -1) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64S rfind(const char* _Memory, int64S _From = -1) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64S rfind(const XByteArray& _Bytes, int64S _From = -1) const XANADU_NOTHROW;

public:
	/// Find in positive order from the specified location
	virtual int64S indexOf(char _Char, int64S _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64S indexOf(const char* _Memory, int64S _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64S indexOf(const XByteArray& _Bytes, int64S _From = 0) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64S lastIndexOf(char _Char, int64S _From = -1) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64S lastIndexOf(const char* _Memory, int64S _From = -1) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64S lastIndexOf(const XByteArray& _Bytes, int64S _From = -1) const XANADU_NOTHROW;

public:
	/// Check if it's lowercase
	virtual bool isLower() const XANADU_NOTHROW;

	/// Check if it's uppercase
	virtual bool isUpper() const XANADU_NOTHROW;

	/// Convert to lowercase
	virtual XByteArray toLower() const XANADU_NOTHROW;

	/// Convert to uppercase
	virtual XByteArray toUpper() const XANADU_NOTHROW;

	/// Remove start and end whitespace strings ('\t','\n','\v','\f','\r','_')
	virtual XByteArray trimmed() const XANADU_NOTHROW;

	/// Remove beginning, middle, and end whitespace strings ('\t','\n','\v','\f','\r','_')
	virtual XByteArray simplified() const XANADU_NOTHROW;

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
