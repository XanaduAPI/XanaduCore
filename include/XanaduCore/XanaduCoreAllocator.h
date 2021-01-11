//
// Created by Administrator on 2021/1/7.
//

/*
 * This is a memory allocator, Memory allocation for Xanadu series.
 * */

#ifndef			_XANADU_CORE_ALLOCATOR_H_
#define			_XANADU_CORE_ALLOCATOR_H_

#include <XanaduCore/XanaduCoreHeader.h>

/// Xallocator belongs to the memory allocator of Xanadu series
class XANADU_CORE_EXPORT XAllocator
{
private:
	/// Memory address
	void*						_memory_address = nullptr;

	/// Memory length
	int64S						_memory_length = 0;

	/// Memory capacity
	int64S						_memory_capacity = 0;

public:
	/// Subscript returned when no matching data is found
	static const int64S				npos = -1LL;

public:
	/// Constructors
	XAllocator() XANADU_NOTHROW;

	/// Constructors
	XAllocator(int64S _Length) XANADU_NOTHROW;

	/// Constructors
	XAllocator(int64S _Length, char _Char) XANADU_NOTHROW;

	/// Constructors
	XAllocator(const void* _Memory, int64S _Length) XANADU_NOTHROW;

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
	virtual int64S MemoryPosFix(int64S _Pos) const XANADU_NOTHROW;

	/// Check for null values
	virtual bool MemoryIsEmpty() const XANADU_NOTHROW;

	/// Check if there is a value
	virtual bool MemoryIsExist() const XANADU_NOTHROW;

public:
	/// Allocator memory
	virtual bool MemoryAllocator(int64S _Length) XANADU_NOTHROW;

	/// Allocator memory
	virtual bool MemoryAllocator(const void* _Memory, int64S _Length) XANADU_NOTHROW;

	/// Release memory
	virtual void MemoryRelease() XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(int64S _Length) XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(int64S _Length, char _Char) XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(const void* _Memory, int64S _Length) XANADU_NOTHROW;

	/// Append memory
	virtual bool MemoryAppend(const XAllocator& _Allocator) XANADU_NOTHROW;

	/// Reduce memory
	virtual bool MemoryReduce(int64S _Length) XANADU_NOTHROW;

	/// Resize memory
	virtual bool MemoryResize(int64S _Length) XANADU_NOTHROW;

	/// Insert memory
	virtual bool MemoryInsert(int64S _Pos, int64S _Length) XANADU_NOTHROW;

	/// Insert memory
	virtual bool MemoryInsert(int64S _Pos, const void* _Memory, int64S _Length) XANADU_NOTHROW;

	/// Remove memory
	virtual bool MemoryRemove(int64S _Pos, int64S _Length) XANADU_NOTHROW;

	/// Copy Memory
	virtual bool MemoryCopy(const void* _Memory, int64S _Length) XANADU_NOTHROW;

	/// Copy Memory
	virtual bool MemoryCopy(const XAllocator& _Allocator) XANADU_NOTHROW;

	/// Move Memory
	virtual bool MemoryMove(XAllocator& _Allocator) XANADU_NOTHROW;

	/// Find Memory
	virtual int64S MemoryFind(int64S _Pos, const void* _Memory, int64S _Length) const XANADU_NOTHROW;

	/// Find Memory
	virtual int64S MemoryFind(int64S _Pos, const XAllocator& _Allocator) const XANADU_NOTHROW;

	/// Reverse Find Memory
	virtual int64S MemoryReverseFind(int64S _Pos, const void* _Memory, int64S _Length) const XANADU_NOTHROW;

	/// Reverse Find Memory
	virtual int64S MemoryReverseFind(int64S _Pos, const XAllocator& _Allocator) const XANADU_NOTHROW;

	/// Replace Memory
	virtual bool MemoryReplace(int64S _Pos, int64S _Length, const void* _Memory, int64S _Size) XANADU_NOTHROW;

	/// Replace Memory
	virtual bool MemoryReplace(int64S _Pos, int64S _Length, const XAllocator& _Allocator) XANADU_NOTHROW;

public:
	/// Get the address of the memory
	virtual void* MemoryAddress() XANADU_NOTHROW;

	/// Get the address of the memory
	virtual const void* MemoryAddress() const XANADU_NOTHROW;

	/// Get the length of the memory
	virtual int64S MemoryLength() const XANADU_NOTHROW;

	/// Get the capacity of the memory
	virtual int64S MemoryCapacity() const XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_ALLOCATOR_H_
