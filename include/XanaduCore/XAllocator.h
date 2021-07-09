#ifndef			_XANADU_CORE_ALLOCATOR_H_
#define			_XANADU_CORE_ALLOCATOR_H_

#include <XanaduCore/XHeader.h>

// Xallocator belongs to the memory allocator of Xanadu series
class XANADU_CORE_EXPORT XAllocator
{
public:
	// Type of data size and pos
	using						size_type = size_t;

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
	// 构造
	XAllocator() noexcept;

	// 构造
	XAllocator(size_type _Length) noexcept;

	// 构造
	XAllocator(size_type _Length, char _Char) noexcept;

	// 构造
	XAllocator(const void* _Memory, size_type _Length) noexcept;

	// 构造
	XAllocator(const XAllocator& _Allocator) noexcept;

	// Destructor
	virtual ~XAllocator() noexcept;

public:
	// operators overload =
	XAllocator& operator = (const XAllocator& _Allocator) noexcept;

	// operators overload +
	XAllocator operator + (const XAllocator& _Allocator) noexcept;

	// operators overload +=
	XAllocator& operator += (const XAllocator& _Allocator) noexcept;

public:
	// Fix Pos
	virtual size_type memoryFixSize(size_type _Pos) const noexcept;

	// 检查是否为空，当长度为0时返回true
	virtual bool memoryIsEmpty() const noexcept;

	// 检查是否有值，当长度不为0时返回true
	virtual bool memoryIsExist() const noexcept;

public:
	// Allocator memory
	virtual bool memoryAllocator(size_type _Length) noexcept;

	// Allocator memory
	virtual bool memoryAllocator(const void* _Memory, size_type _Length) noexcept;

	// _clear memory
	virtual void memoryRelease() noexcept;

	// append memory
	virtual bool memoryAppend(size_type _Length) noexcept;

	// append memory
	virtual bool memoryAppend(size_type _Length, char _Char) noexcept;

	// append memory
	virtual bool memoryAppend(const void* _Memory, size_type _Length) noexcept;

	// append memory
	virtual bool memoryAppend(const XAllocator& _Allocator) noexcept;

	// Reduce memory
	virtual bool memoryReduce(size_type _Length) noexcept;

	// Resize memory
	virtual bool memoryResize(size_type _Length) noexcept;

	// truncate memory
	virtual void memoryTruncate(size_type _Pos) noexcept;

	// Insert memory
	virtual bool memoryInsert(size_type _Pos, size_type _Length) noexcept;

	// Insert memory
	virtual bool memoryInsert(size_type _Pos, const void* _Memory, size_type _Length) noexcept;

	// remove memory
	virtual bool memoryRemove(size_type _Pos, size_type _Length) noexcept;

	// Copy Memory
	virtual bool memoryCopy(const void* _Memory, size_type _Length) noexcept;

	// Copy Memory
	virtual bool memoryCopy(const XAllocator& _Allocator) noexcept;

	// Move Memory
	virtual bool memoryMove(XAllocator& _Allocator) noexcept;

	// find Memory
	virtual size_type memoryFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept;

	// find Memory
	virtual size_type memoryFind(size_type _Pos, const XAllocator& _Allocator) const noexcept;

	// Reverse find Memory
	virtual size_type memoryReverseFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept;

	// Reverse find Memory
	virtual size_type memoryReverseFind(size_type _Pos, const XAllocator& _Allocator) const noexcept;

	// compare
	virtual int memoryCompare(const void* _Memory, size_type _Length) const noexcept;

	// Replace Memory
	virtual bool memoryReplace(size_type _Pos, size_type _Length, const void* _Memory, size_type _Size) noexcept;

	// Replace Memory
	virtual bool memoryReplace(size_type _Pos, size_type _Length, const XAllocator& _Allocator) noexcept;

public:
	// Get the address of the memory
	virtual char* memoryAddress() noexcept;

	// Get the address of the memory
	virtual const char* memoryAddress() const noexcept;

	// Get the length of the memory
	virtual size_type memoryLength() const noexcept;

	// Get the capacity of the memory
	virtual size_type memoryCapacity() const noexcept;
};

#endif
