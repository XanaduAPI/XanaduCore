/*
 * This is a memory allocator, Memory allocation for Xanadu series.
 * */

#ifndef			_XANADU_CORE_ALLOCATOR_H_
#define			_XANADU_CORE_ALLOCATOR_H_

#include <XanaduCore/XanaduCoreHeader.h>

/// Xallocator belongs to the memory allocator of Xanadu series
class XANADU_CORE_EXPORT XAllocator
{
public:
	/// Type of data size and pos
	using						size_type = int64U;

	/// Subscript returned when no matching data is found
	static const size_type				npos = static_cast<size_type>(-1);

private:
	/// Memory address
	char*						_memory_address = nullptr;

	/// Memory length
	size_type					_memory_length = 0;

	/// Memory capacity
	size_type					_memory_capacity = 0;

public:
	/// Constructors
	XAllocator() XANADU_NOTHROW;

	/// Constructors
	XAllocator(size_type _Length) XANADU_NOTHROW;

	/// Constructors
	XAllocator(size_type _Length, char _Char) XANADU_NOTHROW;

	/// Constructors
	XAllocator(const void* _Memory, size_type _Length) XANADU_NOTHROW;

	/// Constructors
	XAllocator(const XAllocator& _Allocator) XANADU_NOTHROW;

	/// Destructor
	virtual ~XAllocator() XANADU_NOTHROW;

public:
	/// operator overload =
	XAllocator& operator = (const XAllocator& _Allocator) XANADU_NOTHROW;

	/// operator overload +
	XAllocator operator + (const XAllocator& _Allocator) XANADU_NOTHROW;

	/// operator overload +=
	XAllocator& operator += (const XAllocator& _Allocator) XANADU_NOTHROW;

public:
	/// Fix Pos
	virtual size_type MemoryPosFix(size_type _Pos) const XANADU_NOTHROW;

	/// Check for null values
	virtual bool MemoryIsEmpty() const XANADU_NOTHROW;

	/// Check if there is a value
	virtual bool MemoryIsExist() const XANADU_NOTHROW;

public:
	/// Allocator memory
	virtual bool MemoryAllocator(size_type _Length) XANADU_NOTHROW;

	/// Allocator memory
	virtual bool MemoryAllocator(const void* _Memory, size_type _Length) XANADU_NOTHROW;

	/// Release memory
	virtual void MemoryRelease() XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(size_type _Length) XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(size_type _Length, char _Char) XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(const void* _Memory, size_type _Length) XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(const XAllocator& _Allocator) XANADU_NOTHROW;

	/// Reduce memory
	virtual bool MemoryReduce(size_type _Length) XANADU_NOTHROW;

	/// Resize memory
	virtual bool MemoryResize(size_type _Length) XANADU_NOTHROW;

	/// truncate memory
	virtual void MemoryTruncate(size_type _Pos) XANADU_NOTHROW;

	/// Insert memory
	virtual bool MemoryInsert(size_type _Pos, size_type _Length) XANADU_NOTHROW;

	/// Insert memory
	virtual bool MemoryInsert(size_type _Pos, const void* _Memory, size_type _Length) XANADU_NOTHROW;

	/// Remove memory
	virtual bool MemoryRemove(size_type _Pos, size_type _Length) XANADU_NOTHROW;

	/// Copy Memory
	virtual bool MemoryCopy(const void* _Memory, size_type _Length) XANADU_NOTHROW;

	/// Copy Memory
	virtual bool MemoryCopy(const XAllocator& _Allocator) XANADU_NOTHROW;

	/// Move Memory
	virtual bool MemoryMove(XAllocator& _Allocator) XANADU_NOTHROW;

	/// Find Memory
	virtual size_type MemoryFind(size_type _Pos, const void* _Memory, size_type _Length) const XANADU_NOTHROW;

	/// Find Memory
	virtual size_type MemoryFind(size_type _Pos, const XAllocator& _Allocator) const XANADU_NOTHROW;

	/// Reverse Find Memory
	virtual size_type MemoryReverseFind(size_type _Pos, const void* _Memory, size_type _Length) const XANADU_NOTHROW;

	/// Reverse Find Memory
	virtual size_type MemoryReverseFind(size_type _Pos, const XAllocator& _Allocator) const XANADU_NOTHROW;

	/// Replace Memory
	virtual bool MemoryReplace(size_type _Pos, size_type _Length, const void* _Memory, size_type _Size) XANADU_NOTHROW;

	/// Replace Memory
	virtual bool MemoryReplace(size_type _Pos, size_type _Length, const XAllocator& _Allocator) XANADU_NOTHROW;

public:
	/// Get the address of the memory
	virtual void* MemoryAddress() XANADU_NOTHROW;

	/// Get the address of the memory
	virtual const void* MemoryAddress() const XANADU_NOTHROW;

	/// Get the length of the memory
	virtual size_type MemoryLength() const XANADU_NOTHROW;

	/// Get the capacity of the memory
	virtual size_type MemoryCapacity() const XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_ALLOCATOR_H_
