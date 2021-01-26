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
	static const int64U				npos = XAllocator::npos;

public:
	/// Constructors
	XByteArray() XANADU_NOTHROW;

	/// Constructors
	XByteArray(const char* _Memory, int64U _Size = XByteArray::npos) XANADU_NOTHROW;

	/// Constructors
	XByteArray(int64U _Size, char _Char) XANADU_NOTHROW;

	/// Constructors
	XByteArray(int64U _Size) XANADU_NOTHROW;

	/// Constructors
	XByteArray(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Destructor
	virtual ~XByteArray() XANADU_NOTHROW;

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
	/// operator overload ==
	virtual bool operator == (const char* _Memory)const  XANADU_NOTHROW;

	/// operator overload ==
	virtual bool operator == (const XByteArray& _Bytes)const  XANADU_NOTHROW;

public:
	/// Get data pointer
	virtual char* data() XANADU_NOTHROW;

	/// Get data const pointer
	virtual const char* data() const XANADU_NOTHROW;

	/// Get data size
	virtual int64U size() const XANADU_NOTHROW;

	/// Get Data size
	virtual int64U length() const XANADU_NOTHROW;

	/// resize
	virtual void resize(int64U _Size) XANADU_NOTHROW;

	/// Fills a character to the specified length of space, or if XByteArray::npos, all of it
	virtual XByteArray& fill(char _Char, int64U _Size = XByteArray::npos) XANADU_NOTHROW;

	/// Get the current capacity
	virtual int64U capacity() const XANADU_NOTHROW;

	/// Check for null values
	virtual bool isEmpty() const XANADU_NOTHROW;

	/// Check if there is a value
	virtual bool isExist() const XANADU_NOTHROW;

public:
	/// Read by subscript
	virtual char at(int64U _Index) const XANADU_NOTHROW;

	/// Get the first one
	virtual char front() const XANADU_NOTHROW;

	/// Get the first one
	virtual char& front() XANADU_NOTHROW;

	/// Get the last one
	virtual char back() const XANADU_NOTHROW;

	/// Get the last one
	virtual char& back() XANADU_NOTHROW;

	/// Read by subscript
	virtual char& operator[](int64U _Index) XANADU_NOTHROW;

	/// Read by subscript
	virtual char operator[](int64U _Index) const XANADU_NOTHROW;

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
	virtual XByteArray& prepend(int64U _Count, char _Char) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String, int64U _Length) XANADU_NOTHROW;

	/// Add at the front
	virtual XByteArray& prepend(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(char _Char) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(int64U _Count, char _Char) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const char* _String) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const char* _String, int64U _Length) XANADU_NOTHROW;

	/// Add at the end
	virtual XByteArray& append(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64U _Index, char _Char) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64U _Index, int64U _Count, char _Char) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64U _Index, const char* _String) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64U _Index, const char* _String, int64U _Length) XANADU_NOTHROW;

	/// Insert by pos
	virtual XByteArray& insert(int64U _Index, const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(int64U _Index, int64U _Length) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int64U _Index, int64U _Length, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int64U _Index, int64U _Length, const char* _After, int64U _Asize) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(int64U _Index, int64U _Length, const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(char _Before, const XByteArray& _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, const char* _After) XANADU_NOTHROW;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, int64U _Bsize, const char* _After, int64U _Asize) XANADU_NOTHROW;

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
	virtual XByteArray left(int64U _Length) const XANADU_NOTHROW;

	/// Get the data on the right by length
	virtual XByteArray right(int64U _Length) const XANADU_NOTHROW;

	/// Retrieve the middle data by length
	virtual XByteArray mid(int64U _Index, int64U _Length = XByteArray::npos) const XANADU_NOTHROW;

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
	virtual int64U find(char _Char, int64U _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64U find(const char* _Memory, int64U _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64U find(const XByteArray& _Bytes, int64U _From = 0) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64U rfind(char _Char, int64U _From = XByteArray::npos) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64U rfind(const char* _Memory, int64U _From = XByteArray::npos) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64U rfind(const XByteArray& _Bytes, int64U _From = XByteArray::npos) const XANADU_NOTHROW;

public:
	/// Find in positive order from the specified location
	virtual int64U indexOf(char _Char, int64U _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64U indexOf(const char* _Memory, int64U _From = 0) const XANADU_NOTHROW;

	/// Find in positive order from the specified location
	virtual int64U indexOf(const XByteArray& _Bytes, int64U _From = 0) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64U lastIndexOf(char _Char, int64U _From = XByteArray::npos) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64U lastIndexOf(const char* _Memory, int64U _From = XByteArray::npos) const XANADU_NOTHROW;

	/// Find in reverse order from the specified location
	virtual int64U lastIndexOf(const XByteArray& _Bytes, int64U _From = XByteArray::npos) const XANADU_NOTHROW;

public:
	/// Check for inclusion
	virtual bool contains(char _Char) const XANADU_NOTHROW;

	/// Check for inclusion
	virtual bool contains(const char* _Memory) const XANADU_NOTHROW;

	/// Check for inclusion
	virtual bool contains(const XByteArray& _Bytes) const XANADU_NOTHROW;

	/// Check if they are the same
	virtual int compare(const char* _Memory, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	/// Check if they are the same
	virtual int compare(const XByteArray& _Bytes, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

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
	/// split
	virtual std::list<XByteArray> split(const char _Char) const XANADU_NOTHROW;

	/// split
	virtual std::list<XByteArray> split(const char* _Memory) const XANADU_NOTHROW;

	/// split
	virtual std::list<XByteArray> split(const char* _Memory, int64U _Size) const XANADU_NOTHROW;

	/// split
	virtual std::list<XByteArray> split(const XByteArray& _Bytes) const XANADU_NOTHROW;

public:
	/// Convert to Base64
	virtual XByteArray toBase64() const XANADU_NOTHROW;

	/// Convert to HEX
	virtual XByteArray toHex() const XANADU_NOTHROW;

	/// Format from memory
	static XByteArray XANADUAPI fromMemory(const char* _Memory, int64U _Size) XANADU_NOTHROW;

	/// Format from Base64
	static XByteArray XANADUAPI fromBase64(const void* _Memory, int64U _Size) XANADU_NOTHROW;

	/// Format from Base64
	static XByteArray XANADUAPI fromBase64(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Format from HEX
	static XByteArray XANADUAPI fromHex(const void* _Memory, int64U _Size = XByteArray::npos) XANADU_NOTHROW;

	/// Format from HEX
	static XByteArray XANADUAPI fromHex(const XByteArray& _Bytes) XANADU_NOTHROW;
};

#endif//_XANADU_CORE_BYTEARRAY_H_
