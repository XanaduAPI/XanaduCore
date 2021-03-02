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
	/// Type of data size and pos
	using						size_type = XAllocator::size_type;

public:
	/// Subscript returned when no matching data is found
	static const size_type				npos = XAllocator::npos;

public:
	/// Constructors
	XByteArray() noexcept;

	/// Constructors
	XByteArray(const char* _Memory, size_type _Size = XByteArray::npos) noexcept;

	/// Constructors
	XByteArray(size_type _Size, char _Char) noexcept;

	/// Constructors
	XByteArray(size_type _Size) noexcept;

	/// Constructors
	XByteArray(const XByteArray& _Bytes) noexcept;

	/// Destructor
	virtual ~XByteArray() noexcept;

public:
	/// operator overload =
	XByteArray& operator = (const char* _Memory) noexcept;

	/// operator overload =
	XByteArray& operator = (const XByteArray& _Bytes) noexcept;

	/// operator overload =
	XByteArray& operator = (XByteArray&& _Other) noexcept;

public:
	/// operator overload +
	XByteArray operator + (char _Char) const noexcept;

	/// operator overload +
	XByteArray operator + (const char* _Memory) const noexcept;

	/// operator overload +
	XByteArray operator + (const XByteArray& _Bytes) const noexcept;

public:
	/// operator overload +=
	XByteArray& operator += (char _Char) noexcept;

	/// operator overload +=
	XByteArray& operator += (const char* _Memory) noexcept;

	/// operator overload +=
	XByteArray& operator += (const XByteArray& _Bytes) noexcept;

public:
	/// operator overload ==
	virtual bool operator == (const char* _Memory)const  noexcept;

	/// operator overload ==
	virtual bool operator == (const XByteArray& _Bytes)const  noexcept;

public:
	/// Get data pointer
	virtual char* data() noexcept;

	/// Get data const pointer
	virtual const char* data() const noexcept;

	/// Get data size
	virtual size_type size() const noexcept;

	/// Get Data size
	virtual size_type length() const noexcept;

	/// resize
	virtual void resize(size_type _Size) noexcept;

	/// Truncates the byte array at index position pos. If pos is beyond the end of the array, nothing happens.
	virtual void truncate(size_type _Index) noexcept;

	/// Fills a character to the specified length of space, or if XByteArray::npos, all of it
	virtual XByteArray& fill(char _Char, size_type _Size = XByteArray::npos) noexcept;

	/// Get the current capacity
	virtual size_type capacity() const noexcept;

	/// Check for null values
	virtual bool empty() const noexcept;

	/// Check if there is a value
	virtual bool exist() const noexcept;

public:
	/// Read by subscript
	virtual char at(size_type _Index) const noexcept;

	/// Get the first one
	virtual char front() const noexcept;

	/// Get the first one
	virtual char& front() noexcept;

	/// Get the last one
	virtual char back() const noexcept;

	/// Get the last one
	virtual char& back() noexcept;

	/// Read by subscript
	virtual char& operator[](size_type _Index) noexcept;

	/// Read by subscript
	virtual char operator[](size_type _Index) const noexcept;

public:
	/// Iterator type definition
	typedef char*					iterator;
	typedef const char*				const_iterator;
	typedef iterator				Iterator;
	typedef const_iterator				ConstIterator;
	typedef std::reverse_iterator<iterator>		reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

	/// Iterator operation
	virtual iterator begin() noexcept;

	/// Iterator operation
	virtual const_iterator begin() const noexcept;

	/// Iterator operation
	virtual const_iterator cbegin() const noexcept;

	/// Iterator operation
	virtual const_iterator constBegin() const noexcept;

	/// Iterator operation
	virtual iterator end() noexcept;

	/// Iterator operation
	virtual const_iterator end() const noexcept;

	/// Iterator operation
	virtual const_iterator cend() const noexcept;

	/// Iterator operation
	virtual const_iterator constEnd() const noexcept;

	/// Iterator operation
	virtual reverse_iterator rbegin() noexcept;

	/// Iterator operation
	virtual reverse_iterator rend() noexcept;

	/// Iterator operation
	virtual const_reverse_iterator rbegin() const noexcept;

	/// Iterator operation
	virtual const_reverse_iterator rend() const noexcept;

	/// Iterator operation
	virtual const_reverse_iterator crbegin() const noexcept;

	/// Iterator operation
	virtual const_reverse_iterator crend() const noexcept;

public:
	/// Vector compatibility: increments to the last bit
	virtual void push_back(char _Char) noexcept;

	/// Vector compatibility: increments to the last bit
	virtual void push_back(const char* _Memory) noexcept;

	/// Vector compatibility: increments to the last bit
	virtual void push_back(const XByteArray& _Bytes) noexcept;

	/// Vector compatible: increments to the first
	virtual void push_front(char _Char) noexcept;

	/// Vector compatible: increments to the first
	virtual void push_front(const char* _Memory) noexcept;

	/// Vector compatible: increments to the first
	virtual void push_front(const XByteArray& _Bytes) noexcept;

public:
	/// Add at the front
	virtual XByteArray& prepend(char _Char) noexcept;

	/// Add at the front
	virtual XByteArray& prepend(size_type _Count, char _Char) noexcept;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String) noexcept;

	/// Add at the front
	virtual XByteArray& prepend(const char* _String, size_type _Length) noexcept;

	/// Add at the front
	virtual XByteArray& prepend(const XByteArray& _Bytes) noexcept;

	/// Add at the end
	virtual XByteArray& append(char _Char) noexcept;

	/// Add at the end
	virtual XByteArray& append(size_type _Count, char _Char) noexcept;

	/// Add at the end
	virtual XByteArray& append(const char* _String) noexcept;

	/// Add at the end
	virtual XByteArray& append(const char* _String, size_type _Length) noexcept;

	/// Add at the end
	virtual XByteArray& append(const XByteArray& _Bytes) noexcept;

	/// Insert by pos
	virtual XByteArray& insert(size_type _Index, char _Char) noexcept;

	/// Insert by pos
	virtual XByteArray& insert(size_type _Index, size_type _Count, char _Char) noexcept;

	/// Insert by pos
	virtual XByteArray& insert(size_type _Index, const char* _String) noexcept;

	/// Insert by pos
	virtual XByteArray& insert(size_type _Index, const char* _String, size_type _Length) noexcept;

	/// Insert by pos
	virtual XByteArray& insert(size_type _Index, const XByteArray& _Bytes) noexcept;

public:
	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(size_type _Index, size_type _Length) noexcept;

	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(const char _Char) noexcept;

	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(const char* _Memory) noexcept;

	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(const char* _Memory, size_type _Size) noexcept;

	/// Delete the specified length of data from the specified pos
	virtual XByteArray& remove(const XByteArray& _Bytes) noexcept;

public:
	/// Replace data
	virtual XByteArray& replace(size_type _Index, size_type _Length, const char* _After) noexcept;

	/// Replace data
	virtual XByteArray& replace(size_type _Index, size_type _Length, const char* _After, size_type _Asize) noexcept;

	/// Replace data
	virtual XByteArray& replace(size_type _Index, size_type _Length, const XByteArray& _Bytes) noexcept;

	/// Replace data
	virtual XByteArray& replace(char _Before, const char* _After) noexcept;

	/// Replace data
	virtual XByteArray& replace(char _Before, const XByteArray& _After) noexcept;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, const char* _After) noexcept;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, size_type _Bsize, const char* _After, size_type _Asize) noexcept;

	/// Replace data
	virtual XByteArray& replace(const XByteArray& _Before, const XByteArray& _After) noexcept;

	/// Replace data
	virtual XByteArray& replace(const XByteArray& _Before, const char* _After) noexcept;

	/// Replace data
	virtual XByteArray& replace(const char* _Before, const XByteArray& _After) noexcept;

	/// Replace data
	virtual XByteArray& replace(char _Before, char _After) noexcept;

public:
	/// Get the data on the left by length
	virtual XByteArray left(size_type _Length) const noexcept;

	/// Get the data on the right by length
	virtual XByteArray right(size_type _Length) const noexcept;

	/// Retrieve the middle data by length
	virtual XByteArray mid(size_type _Index, size_type _Length = XByteArray::npos) const noexcept;

public:
	/// Check if the head is the same
	virtual bool startsWith(char _Char) const noexcept;

	/// Check if the head is the same
	virtual bool startsWith(const char* _Memory) const noexcept;

	/// Check if the head is the same
	virtual bool startsWith(const XByteArray& _Bytes) const noexcept;

	/// Check if the tails are the same
	virtual bool endsWith(char _Char) const noexcept;

	/// Check if the tails are the same
	virtual bool endsWith(const char* _Memory) const noexcept;

	/// Check if the tails are the same
	virtual bool endsWith(const XByteArray& _Bytes) const noexcept;

public:
	/// find in positive order from the specified location
	virtual size_type find(char _Char, size_type _From = 0) const noexcept;

	/// find in positive order from the specified location
	virtual size_type find(const char* _Memory, size_type _From = 0) const noexcept;

	/// find in positive order from the specified location
	virtual size_type find(const XByteArray& _Bytes, size_type _From = 0) const noexcept;

	/// find in reverse order from the specified location
	virtual size_type rfind(char _Char, size_type _From = XByteArray::npos) const noexcept;

	/// find in reverse order from the specified location
	virtual size_type rfind(const char* _Memory, size_type _From = XByteArray::npos) const noexcept;

	/// find in reverse order from the specified location
	virtual size_type rfind(const XByteArray& _Bytes, size_type _From = XByteArray::npos) const noexcept;

public:
	/// find in positive order from the specified location
	virtual size_type indexOf(char _Char, size_type _From = 0) const noexcept;

	/// find in positive order from the specified location
	virtual size_type indexOf(const char* _Memory, size_type _From = 0) const noexcept;

	/// find in positive order from the specified location
	virtual size_type indexOf(const XByteArray& _Bytes, size_type _From = 0) const noexcept;

	/// find in reverse order from the specified location
	virtual size_type lastIndexOf(char _Char, size_type _From = XByteArray::npos) const noexcept;

	/// find in reverse order from the specified location
	virtual size_type lastIndexOf(const char* _Memory, size_type _From = XByteArray::npos) const noexcept;

	/// find in reverse order from the specified location
	virtual size_type lastIndexOf(const XByteArray& _Bytes, size_type _From = XByteArray::npos) const noexcept;

public:
	/// Check for inclusion
	virtual bool contains(char _Char) const noexcept;

	/// Check for inclusion
	virtual bool contains(const char* _Memory) const noexcept;

	/// Check for inclusion
	virtual bool contains(const XByteArray& _Bytes) const noexcept;

	/// Check if they are the same
	virtual int compare(const char* _Memory, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	/// Check if they are the same
	virtual int compare(const XByteArray& _Bytes, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	/// Check if it's lowercase
	virtual bool isLower() const noexcept;

	/// Check if it's uppercase
	virtual bool isUpper() const noexcept;

	/// Convert to lowercase
	virtual XByteArray toLower() const noexcept;

	/// Convert to uppercase
	virtual XByteArray toUpper() const noexcept;

	/// Remove start and end whitespace strings ('\t','\n','\v','\f','\r','_')
	virtual XByteArray trimmed() const noexcept;

	/// Remove beginning, middle, and end whitespace strings ('\t','\n','\v','\f','\r','_')
	virtual XByteArray simplified() const noexcept;

public:
	/// split
	virtual std::list<XByteArray> split(const char _Char) const noexcept;

	/// split
	virtual std::list<XByteArray> split(const char* _Memory) const noexcept;

	/// split
	virtual std::list<XByteArray> split(const char* _Memory, size_type _Size) const noexcept;

	/// split
	virtual std::list<XByteArray> split(const XByteArray& _Bytes) const noexcept;

public:
	/// Convert to Base64
	virtual XByteArray toBase64() const noexcept;

	/// Convert to HEX
	virtual XByteArray toHex() const noexcept;

	/// Format from memory
	static XByteArray XANADUAPI fromMemory(const char* _Memory, size_type _Size) noexcept;

	/// Format from Base64
	static XByteArray XANADUAPI fromBase64(const void* _Memory, size_type _Size) noexcept;

	/// Format from Base64
	static XByteArray XANADUAPI fromBase64(const XByteArray& _Bytes) noexcept;

	/// Format from HEX
	static XByteArray XANADUAPI fromHex(const void* _Memory, size_type _Size = XByteArray::npos) noexcept;

	/// Format from HEX
	static XByteArray XANADUAPI fromHex(const XByteArray& _Bytes) noexcept;
};

#endif /// _XANADU_CORE_BYTEARRAY_H_
