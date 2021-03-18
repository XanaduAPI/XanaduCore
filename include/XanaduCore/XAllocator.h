#ifndef			_XANADU_CORE_ALLOCATOR_H_
#define			_XANADU_CORE_ALLOCATOR_H_

#include <XanaduCore/XHeader.h>

// Xallocator belongs to the memory allocator of Xanadu series
class XANADU_CORE_EXPORT XAllocator
{
public:
	// Type of data size and pos
	using						size_type = int64U;

	// Subscript returned when no matching data is found
	static const size_type				npos = static_cast<size_type>(-1);

private:
	// Memory address
	char*						_memory_address = nullptr;

	// Memory length
	size_type					_memory_length = 0;

	// Memory capacity
	size_type					_memory_capacity = 0;

public:
	// Constructors
	XAllocator() noexcept;

	// Constructors
	XAllocator(size_type _Length) noexcept;

	// Constructors
	XAllocator(size_type _Length, char _Char) noexcept;

	// Constructors
	XAllocator(const void* _Memory, size_type _Length) noexcept;

	// Constructors
	XAllocator(const XAllocator& _Allocator) noexcept;

	// Destructor
	virtual ~XAllocator() noexcept;

public:
	// operator overload =
	XAllocator& operator = (const XAllocator& _Allocator) noexcept;

	// operator overload +
	XAllocator operator + (const XAllocator& _Allocator) noexcept;

	// operator overload +=
	XAllocator& operator += (const XAllocator& _Allocator) noexcept;

public:
	// Fix Pos
	virtual size_type MemoryPosFix(size_type _Pos) const noexcept;

	// Check for null values
	virtual bool MemoryIsEmpty() const noexcept;

	// Check if there is a value
	virtual bool MemoryIsExist() const noexcept;

public:
	// Allocator memory
	virtual bool MemoryAllocator(size_type _Length) noexcept;

	// Allocator memory
	virtual bool MemoryAllocator(const void* _Memory, size_type _Length) noexcept;

	// Release memory
	virtual void MemoryRelease() noexcept;

	// append memory
	virtual bool MemoryAppend(size_type _Length) noexcept;

	// append memory
	virtual bool MemoryAppend(size_type _Length, char _Char) noexcept;

	// append memory
	virtual bool MemoryAppend(const void* _Memory, size_type _Length) noexcept;

	// append memory
	virtual bool MemoryAppend(const XAllocator& _Allocator) noexcept;

	// Reduce memory
	virtual bool MemoryReduce(size_type _Length) noexcept;

	// Resize memory
	virtual bool MemoryResize(size_type _Length) noexcept;

	// truncate memory
	virtual void MemoryTruncate(size_type _Pos) noexcept;

	// Insert memory
	virtual bool MemoryInsert(size_type _Pos, size_type _Length) noexcept;

	// Insert memory
	virtual bool MemoryInsert(size_type _Pos, const void* _Memory, size_type _Length) noexcept;

	// remove memory
	virtual bool MemoryRemove(size_type _Pos, size_type _Length) noexcept;

	// Copy Memory
	virtual bool MemoryCopy(const void* _Memory, size_type _Length) noexcept;

	// Copy Memory
	virtual bool MemoryCopy(const XAllocator& _Allocator) noexcept;

	// Move Memory
	virtual bool MemoryMove(XAllocator& _Allocator) noexcept;

	// find Memory
	virtual size_type MemoryFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept;

	// find Memory
	virtual size_type MemoryFind(size_type _Pos, const XAllocator& _Allocator) const noexcept;

	// Reverse find Memory
	virtual size_type MemoryReverseFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept;

	// Reverse find Memory
	virtual size_type MemoryReverseFind(size_type _Pos, const XAllocator& _Allocator) const noexcept;

	// Replace Memory
	virtual bool MemoryReplace(size_type _Pos, size_type _Length, const void* _Memory, size_type _Size) noexcept;

	// Replace Memory
	virtual bool MemoryReplace(size_type _Pos, size_type _Length, const XAllocator& _Allocator) noexcept;

public:
	// Get the address of the memory
	virtual void* MemoryAddress() noexcept;

	// Get the address of the memory
	virtual const void* MemoryAddress() const noexcept;

	// Get the length of the memory
	virtual size_type MemoryLength() const noexcept;

	// Get the capacity of the memory
	virtual size_type MemoryCapacity() const noexcept;
};

#endif // _XANADU_CORE_ALLOCATOR_H_
