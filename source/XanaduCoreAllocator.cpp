//
// Created by Administrator on 2021/1/7.
//

#include <XanaduCore/XanaduCoreAllocator.h>

int64U XanaduAllocatorCalculateCapacity(int64U _Length)
{
	return _Length + 128;
};

/// Constructors
XAllocator::XAllocator() XANADU_NOTHROW
{
	MemoryAllocator(0);
}

/// Constructors
XAllocator::XAllocator(int64U _Length) XANADU_NOTHROW
{
	MemoryAllocator(_Length);
}

/// Constructors
XAllocator::XAllocator(int64U _Length, char _Char) XANADU_NOTHROW
{
	MemoryAllocator(_Length);
	Xanadu::memset(this->_memory_address, _Char, this->_memory_length);
}

/// Constructors
XAllocator::XAllocator(const void* _Memory, int64U _Length) XANADU_NOTHROW
{
	MemoryAllocator(_Memory, _Length);
}

/// Constructors
XAllocator::XAllocator(const XAllocator& _Allocator) XANADU_NOTHROW
{
	MemoryAllocator(_Allocator._memory_address, _Allocator._memory_length);
}

/// Destructor
XAllocator::~XAllocator() XANADU_NOTHROW
{
	XANADU_DELETE_ARR(this->_memory_address);
	this->_memory_length = 0;
	this->_memory_capacity = 0;
}


/// Allocator memory
bool XAllocator::MemoryAllocator(int64U _Length) XANADU_NOTHROW
{
	XANADU_DELETE_ARR(this->_memory_address);

	this->_memory_capacity = XanaduAllocatorCalculateCapacity(this->_memory_length);
	this->_memory_address = XANADU_NEW char[this->_memory_capacity];
	if(this->_memory_address)
	{
		this->_memory_length = _Length;
		Xanadu::memset(this->_memory_address, 0, this->_memory_capacity);
		return true;
	}
	else
	{
		this->_memory_length = 0;
		this->_memory_capacity = 0;
		return false;
	}
}

/// Allocator memory
bool XAllocator::MemoryAllocator(const void* _Memory, int64U _Length) XANADU_NOTHROW
{
	if(MemoryAllocator(_Length))
	{
		if(_Length && _Memory)
		{
			/// Write the incoming value from the beginning
			Xanadu::memcpy(this->_memory_address, _Memory, _Length);
			return true;
		}
	}
	return false;
}

/// Release memory
void XAllocator::MemoryRelease() XANADU_NOTHROW
{
	XANADU_DELETE_ARR(this->_memory_address);
	this->_memory_length = 0;
	this->_memory_capacity = 0;
	MemoryAllocator(0);
}

/// Append memory
bool XAllocator::MemoryAppend(int64U _Length) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Length == 0, false);

	/// When the remaining capacity is sufficient, memory is not reallocated
	if(this->_memory_capacity - this->_memory_length > _Length)
	{
		return true;
	}

	/// Reallocate memory and move the original value
	auto		vTempLength = this->_memory_length + _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XANADU_NEW char[vTempCapacity];
	if (vTempAddress)
	{
		Xanadu::memcpy(vTempAddress, this->_memory_address, this->_memory_length);
		Xanadu::memset(vTempAddress + this->_memory_length, 0, vTempCapacity - this->_memory_length);

		XANADU_DELETE_ARR(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

/// Append memory
bool XAllocator::MemoryAppend(int64U _Length, char _Char) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Length == 0, false);

	/// Save the original length
	auto		vTempLength = this->_memory_length;
	if(MemoryAppend(_Length))
	{
		/// Write the incoming value from the original length
		Xanadu::memset(static_cast<char*>(this->_memory_address) + vTempLength, _Char, _Length);
		return true;
	}
	return false;
}

/// Append memory
bool XAllocator::MemoryAppend(const void* _Memory, int64U _Length) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Memory, false);
	XANADU_CHECK_RETURN(_Length == 0, false);

	/// Save the original length
	auto		vTempLength = this->_memory_length;
	if(MemoryAppend(_Length))
	{
		/// Write the incoming value from the original length
		Xanadu::memcpy(static_cast<char*>(this->_memory_address) + vTempLength, _Memory, _Length);
		return true;
	}
	return false;
}

/// Append memory
bool XAllocator::MemoryAppend(const XAllocator& _Allocator) XANADU_NOTHROW
{
	return MemoryAppend(_Allocator._memory_address, _Allocator._memory_length);
}

/// Reduce memory
bool XAllocator::MemoryReduce(int64U _Length) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Length == 0, false);

	/// If the reduced value is greater than the length, remove all
	if (_Length >= this->_memory_length)
	{
		MemoryRelease();
		return true;
	}

	/// Rebuild memory and move source
	auto		vTempLength = this->_memory_length - _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XANADU_NEW char[vTempCapacity];
	if (vTempAddress)
	{
		Xanadu::memcpy(vTempAddress, this->_memory_address, vTempLength);
		Xanadu::memset(vTempAddress + vTempLength, 0, vTempCapacity - vTempLength);

		XANADU_DELETE_ARR(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

/// Resize memory
bool XAllocator::MemoryResize(int64U _Length) XANADU_NOTHROW
{
	if (_Length > this->_memory_length)
	{
		return MemoryAppend(_Length - this->_memory_length);
	}
	else if(_Length < this->_memory_length)
	{
		return MemoryReduce(this->_memory_length - _Length);
	}
	else
	{
		return true;
	}
}

/// Insert memory
bool XAllocator::MemoryInsert(int64U _Pos, int64U _Length) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	/// When the position is greater than or equal to the length, add at the end
	if(_Pos >= this->_memory_length)
	{
		return MemoryAppend(_Length);
	}

	/// Build new memory and copy old data and incoming data
	auto		vTempLength = this->_memory_length + _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XANADU_NEW char[vTempCapacity];
	if (vTempAddress)
	{
		if (_Pos > 0)
		{
			Xanadu::memcpy(vTempAddress, this->_memory_address, _Pos);
		}
		Xanadu::memset(vTempAddress + _Pos, 0, _Length);
		Xanadu::memcpy(vTempAddress + _Pos + _Length, static_cast<char*>(this->_memory_address) + _Pos, this->_memory_length - _Pos);
		Xanadu::memset(vTempAddress + this->_memory_length + _Length, 0, vTempCapacity - this->_memory_length - _Length);

		XANADU_DELETE_ARR(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

/// Insert memory
bool XAllocator::MemoryInsert(int64U _Pos, const void* _Memory, int64U _Length) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	if(MemoryInsert(_Pos, _Length))
	{
		if(_Memory)
		{
			Xanadu::memcpy(static_cast<char*>(this->_memory_address) + _Pos, _Memory, _Length);
		}
		return true;
	}
	return false;
}

/// Remove memory
bool XAllocator::MemoryRemove(int64U _Pos, int64U _Length) XANADU_NOTHROW
{
	/// If it is removed from the end, the MemoryReduce function is called
	if (this->_memory_length - _Pos <= _Length)
	{
		return MemoryReduce(this->_memory_length - _Pos);
	}

	/// Build new memory and copy the rest
	auto		vTempLength = this->_memory_length - _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XANADU_NEW char[vTempCapacity];
	if (vTempAddress)
	{
		Xanadu::memcpy(vTempAddress, this->_memory_address, vTempLength);
		Xanadu::memset(vTempAddress + vTempLength, 0, vTempCapacity - vTempLength);

		XANADU_DELETE_ARR(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

/// Copy Memory
bool XAllocator::MemoryCopy(const void* _Memory, int64U _Length) XANADU_NOTHROW
{
	this->MemoryRelease();
	return this->MemoryAllocator(_Memory, _Length);
}

/// Copy Memory
bool XAllocator::MemoryCopy(const XAllocator& _Allocator) XANADU_NOTHROW
{
	this->MemoryRelease();
	return this->MemoryAllocator(_Allocator._memory_address, _Allocator._memory_length);
}

/// Move Memory
bool XAllocator::MemoryMove(XAllocator& _Allocator) XANADU_NOTHROW
{
	XANADU_DELETE_ARR(this->_memory_address);

	this->_memory_address = _Allocator._memory_address;
	this->_memory_length = _Allocator._memory_length;
	this->_memory_capacity = _Allocator._memory_capacity;
	_Allocator.MemoryRelease();
	return true;
}


/// Get the address of the memory
void* XAllocator::MemoryAddress() XANADU_NOTHROW
{
	return _memory_address;
}

/// Get the address of the memory
const void* XAllocator::MemoryAddress() const XANADU_NOTHROW
{
	return _memory_address;
}

/// Get the length of the memory
int64U XAllocator::MemoryLength() const XANADU_NOTHROW
{
	return _memory_length;
}

/// Get the capacity of the memory
int64U XAllocator::MemoryCapacity() const XANADU_NOTHROW
{
	return _memory_capacity;
}
