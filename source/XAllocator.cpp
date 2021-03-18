#include <XanaduCore/XAllocator.h>

#define XANADU_ALLOCATOR_DELETE(_Address)			if((_Address)){ delete[] static_cast<char*>(_Address); _Address = nullptr;}

// Calculate the appropriate capacity according to the length of the input
XAllocator::size_type XanaduAllocatorCalculateCapacity(XAllocator::size_type _Length)
{
	// The default is to add 128 bytes to the length
	return _Length + 128;
};

// Xanadu memory allocator requests memory
char* XanaduAllocatorMallocMemory(XAllocator::size_type _Size)
{
	auto		vSize = static_cast<unsigned int>(_Size);
	return XANADU_NEW char[vSize];
}

// Constructors
XAllocator::XAllocator() noexcept
{
	MemoryAllocator(0);
}

// Constructors
XAllocator::XAllocator(size_type _Length) noexcept
{
	MemoryAllocator(_Length);
}

// Constructors
XAllocator::XAllocator(size_type _Length, char _Char) noexcept
{
	MemoryAllocator(_Length);
	Xanadu::memset(this->_memory_address, _Char, this->_memory_length);
}

// Constructors
XAllocator::XAllocator(const void* _Memory, size_type _Length) noexcept
{
	MemoryAllocator(_Memory, _Length);
}

// Constructors
XAllocator::XAllocator(const XAllocator& _Allocator) noexcept
{
	MemoryAllocator(_Allocator._memory_address, _Allocator._memory_length);
}

// Destructor
XAllocator::~XAllocator() noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);
	this->_memory_length = 0;
	this->_memory_capacity = 0;
}



// operator overload =
XAllocator& XAllocator::operator = (const XAllocator& _Allocator) noexcept
{
	this->MemoryCopy(_Allocator);
	return *this;
}

// operator overload +
XAllocator XAllocator::operator + (const XAllocator& _Allocator) noexcept
{
	auto		vResult = *this;
	vResult.MemoryAppend(_Allocator);
	return vResult;
}

// operator overload +=
XAllocator& XAllocator::operator += (const XAllocator& _Allocator) noexcept
{
	this->MemoryAppend(_Allocator);
	return *this;
}





// Fix Pos
XAllocator::size_type XAllocator::MemoryPosFix(size_type _Pos) const noexcept
{
	if (_Pos == XAllocator::npos)
	{
		return 0;
	}
	else if(_Pos > this->_memory_length)
	{
		return this->_memory_length;
	}
	return _Pos;
}

// Check for null values
bool XAllocator::MemoryIsEmpty() const noexcept
{
	return this->_memory_length <= 0;
}

// Check if there is a value
bool XAllocator::MemoryIsExist() const noexcept
{
	return this->_memory_length > 0;
}







// Allocator memory
bool XAllocator::MemoryAllocator(size_type _Length) noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);

	// When the value passed in is less than 0, the default size is assigned
	this->_memory_length = _Length == XAllocator::npos ? 0 : _Length;
	this->_memory_capacity = XanaduAllocatorCalculateCapacity(this->_memory_length);
	this->_memory_address = XanaduAllocatorMallocMemory(this->_memory_capacity);
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

// Allocator memory
bool XAllocator::MemoryAllocator(const void* _Memory, size_type _Length) noexcept
{
	if(this->MemoryAllocator(_Length))
	{
		if(_Length > 0 && _Memory)
		{
			// write the incoming value from the beginning
			Xanadu::memcpy(this->_memory_address, _Memory, _Length);
			return true;
		}
	}
	return false;
}

// Release memory
void XAllocator::MemoryRelease() noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);
	this->_memory_length = 0;
	this->_memory_capacity = 0;
	this->MemoryAllocator(0);
}

// append memory
bool XAllocator::MemoryAppend(size_type _Length) noexcept
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	// When the remaining capacity is sufficient, memory is not reallocated
	if(this->_memory_capacity - this->_memory_length > _Length)
	{
		this->_memory_length += _Length;
		return true;
	}

	// Reallocate memory and move the original value
	auto		vTempLength = this->_memory_length + _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XanaduAllocatorMallocMemory(vTempCapacity);
	if (vTempAddress)
	{
		Xanadu::memcpy(vTempAddress, this->_memory_address, this->_memory_length);
		Xanadu::memset(vTempAddress + this->_memory_length, 0, vTempCapacity - this->_memory_length);

		XANADU_ALLOCATOR_DELETE(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

// append memory
bool XAllocator::MemoryAppend(size_type _Length, char _Char) noexcept
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	// save the original length
	auto		vTempLength = this->_memory_length;
	if(this->MemoryAppend(_Length))
	{
		// write the incoming value from the original length
		Xanadu::memset(static_cast<char*>(this->_memory_address) + vTempLength, _Char, _Length);
		return true;
	}
	return false;
}

// append memory
bool XAllocator::MemoryAppend(const void* _Memory, size_type _Length) noexcept
{
	XANADU_CHECK_RETURN(_Memory, false);
	XANADU_CHECK_RETURN(_Length > 0, false);

	// save the original length
	auto		vTempLength = this->_memory_length;
	if(this->MemoryAppend(_Length))
	{
		// write the incoming value from the original length
		Xanadu::memcpy(static_cast<char*>(this->_memory_address) + vTempLength, _Memory, _Length);
		return true;
	}
	return false;
}

// append memory
bool XAllocator::MemoryAppend(const XAllocator& _Allocator) noexcept
{
	return this->MemoryAppend(_Allocator._memory_address, _Allocator._memory_length);
}

// Reduce memory
bool XAllocator::MemoryReduce(size_type _Length) noexcept
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	// If the reduced value is greater than the length, remove all
	if (_Length >= this->_memory_length)
	{
		MemoryRelease();
		return true;
	}

	// Rebuild memory and move source
	auto		vTempLength = this->_memory_length - _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XanaduAllocatorMallocMemory(vTempCapacity);
	if (vTempAddress)
	{
		Xanadu::memcpy(vTempAddress, this->_memory_address, vTempLength);
		Xanadu::memset(vTempAddress + vTempLength, 0, vTempCapacity - vTempLength);

		XANADU_ALLOCATOR_DELETE(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

// Resize memory
bool XAllocator::MemoryResize(size_type _Length) noexcept
{
	if (_Length > this->_memory_length)
	{
		return this->MemoryAppend(_Length - this->_memory_length);
	}
	else if(_Length < this->_memory_length)
	{
		return this->MemoryReduce(this->_memory_length - _Length);
	}
	else
	{
		return true;
	}
}

// truncate memory
void XAllocator::MemoryTruncate(size_type _Pos) noexcept
{
	if (_Pos < this->_memory_length)
	{
		this->MemoryResize(_Pos);
	}
}

// Insert memory
bool XAllocator::MemoryInsert(size_type _Pos, size_type _Length) noexcept
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	_Pos = this->MemoryPosFix(_Pos);

	// When the position is greater than or equal to the length, add at the end
	if(_Pos >= this->_memory_length)
	{
		return this->MemoryAppend(_Length);
	}

	// Build new memory and copy old data and incoming data
	auto		vTempLength = this->_memory_length + _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XanaduAllocatorMallocMemory(vTempCapacity);
	if (vTempAddress)
	{
		Xanadu::memcpy(vTempAddress, this->_memory_address, _Pos);
		Xanadu::memset(vTempAddress + _Pos, 0, _Length);
		Xanadu::memcpy(vTempAddress + _Pos + _Length, static_cast<char*>(this->_memory_address) + _Pos, this->_memory_length - _Pos);
		Xanadu::memset(vTempAddress + this->_memory_length + _Length, 0, vTempCapacity - this->_memory_length - _Length);

		XANADU_ALLOCATOR_DELETE(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

// Insert memory
bool XAllocator::MemoryInsert(size_type _Pos, const void* _Memory, size_type _Length) noexcept
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	_Pos = this->MemoryPosFix(_Pos);
	if(this->MemoryInsert(_Pos, _Length))
	{
		if(_Memory)
		{
			Xanadu::memcpy(static_cast<char*>(this->_memory_address) + _Pos, _Memory, _Length);
		}
		return true;
	}
	return false;
}

// remove memory
bool XAllocator::MemoryRemove(size_type _Pos, size_type _Length) noexcept
{
	XANADU_CHECK_RETURN(_Length > 0, false);

	_Pos = this->MemoryPosFix(_Pos);
	// If it is removed from the end, the MemoryReduce function is called
	if (this->_memory_length - _Pos <= _Length)
	{
		return this->MemoryReduce(this->_memory_length - _Pos);
	}

	// Build new memory and copy the rest
	auto		vTempLength = this->_memory_length - _Length;
	auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
	auto		vTempAddress = XanaduAllocatorMallocMemory(vTempCapacity);
	if (vTempAddress)
	{
		Xanadu::memcpy(vTempAddress, this->_memory_address, _Pos);
		Xanadu::memcpy(vTempAddress + _Pos, static_cast<const char*>(this->_memory_address) + _Pos + _Length, this->_memory_length - _Pos - _Length);
		Xanadu::memset(vTempAddress + vTempLength, 0, vTempCapacity - vTempLength);

		XANADU_ALLOCATOR_DELETE(this->_memory_address);
		this->_memory_address = vTempAddress;
		this->_memory_length = vTempLength;
		this->_memory_capacity = vTempCapacity;
		return true;
	}
	return false;
}

// Copy Memory
bool XAllocator::MemoryCopy(const void* _Memory, size_type _Length) noexcept
{
	this->MemoryRelease();

	XANADU_CHECK_RETURN(_Length > 0, false);

	return this->MemoryAllocator(_Memory, _Length);
}

// Copy Memory
bool XAllocator::MemoryCopy(const XAllocator& _Allocator) noexcept
{
	return this->MemoryCopy(_Allocator._memory_address, _Allocator._memory_length);
}

// Move Memory
bool XAllocator::MemoryMove(XAllocator& _Allocator) noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);

	this->_memory_address = _Allocator._memory_address;
	this->_memory_length = _Allocator._memory_length;
	this->_memory_capacity = _Allocator._memory_capacity;

	_Allocator._memory_address = nullptr;
	_Allocator._memory_length = 0LL;
	_Allocator._memory_capacity = 0LL;
	_Allocator.MemoryAllocator(0);
	return true;
}

// find Memory
XAllocator::size_type XAllocator::MemoryFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept
{
	_Pos = this->MemoryPosFix(_Pos);
	auto		vPos = XAllocator::npos;
	if (_Memory && _Length > 0 && _Pos < this->_memory_length)
	{
		auto		vSourceMemory = static_cast<const char*>(this->_memory_address) + _Pos;
		auto		vSourceLength = this->_memory_length - _Pos;
		auto		vTargetMemory = static_cast<const char*>(_Memory);

		for (auto vSourceIndex = 0; vSourceIndex < vSourceLength; ++vSourceIndex)
		{
			auto		vFind = true;
			for (auto vTargetIndex = 0; vTargetIndex < _Length && vFind; ++vTargetIndex)
			{
				if(vSourceIndex + vTargetIndex >= vSourceLength)
				{
					vFind = false;
				}
				else if(vSourceMemory[vSourceIndex + vTargetIndex] != vTargetMemory[vTargetIndex])
				{
					vFind = false;
				}
			}
			if (vFind)
			{
				return _Pos + vSourceIndex;
			}
		}
	}
	return vPos;
}

// find Memory
XAllocator::size_type XAllocator::MemoryFind(size_type _Pos, const XAllocator& _Allocator) const noexcept
{
	_Pos = this->MemoryPosFix(_Pos);
	return this->MemoryFind(_Pos, _Allocator._memory_address, _Allocator._memory_length);
}

// Reverse find Memory
XAllocator::size_type XAllocator::MemoryReverseFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept
{
	_Pos = this->MemoryPosFix(_Pos);
	auto		vPos = XAllocator::npos;
	if (_Memory && _Length > 0 && _Pos < this->_memory_length)
	{
		auto		vSourceMemory = static_cast<const char*>(this->_memory_address) + _Pos;
		auto		vSourceBegin = this->_memory_length - _Length > _Pos ? _Pos : this->_memory_length - _Length;
		auto		vTargetMemory = static_cast<const char*>(_Memory);

		for (auto vSourceIndex = vSourceBegin; vSourceIndex != XAllocator::npos; --vSourceIndex)
		{
			auto		vFind = true;
			for (auto vTargetIndex = 0; vTargetIndex < _Length && vFind; ++vTargetIndex)
			{
				if(vSourceIndex + vTargetIndex >= this->_memory_length)
				{
					vFind = false;
				}
				else if(vSourceMemory[vSourceIndex + vTargetIndex] != vTargetMemory[vTargetIndex])
				{
					vFind = false;
				}
			}
			if (vFind)
			{
				return vSourceIndex;
			}
		}
	}
	return vPos;
}

// Reverse find Memory
XAllocator::size_type XAllocator::MemoryReverseFind(size_type _Pos, const XAllocator& _Allocator) const noexcept
{
	_Pos = this->MemoryPosFix(_Pos);
	return this->MemoryReverseFind(_Pos, _Allocator._memory_address, _Allocator._memory_length);
}

// Replace Memory
bool XAllocator::MemoryReplace(size_type _Pos, size_type _Length, const void* _Memory, size_type _Size) noexcept
{
	XANADU_CHECK_RETURN(_Length > 0, false);
	XANADU_CHECK_RETURN(_Size >= 0, false);

	_Pos = this->MemoryPosFix(_Pos);
	if(_Pos < this->_memory_length && (_Pos + _Length) < this->_memory_length && _Memory)
	{
		// If the source and target are of the same length, no memory is allocated
		if (_Length == _Size)
		{
			Xanadu::memcpy(static_cast<char*>(this->_memory_address) + _Pos, _Memory, _Size);
			return true;
		}
		else
		{
			// Reallocate memory and copy the source and replacement values
			auto		vTempLength = this->_memory_length - _Length + _Size;
			auto		vTempCapacity = XanaduAllocatorCalculateCapacity(vTempLength);
			auto		vTempAddress = XanaduAllocatorMallocMemory(vTempCapacity);
			if (vTempAddress)
			{
				Xanadu::memcpy(vTempAddress, this->_memory_address, _Pos);
				Xanadu::memcpy(vTempAddress + _Pos, _Memory, _Size);
				Xanadu::memcpy(vTempAddress + _Pos + _Size, static_cast<const char*>(this->_memory_address) + _Pos + _Length, this->_memory_length - _Pos - _Length);
				Xanadu::memset(vTempAddress + vTempLength, 0, vTempCapacity - vTempLength);

				XANADU_ALLOCATOR_DELETE(this->_memory_address);
				this->_memory_address = vTempAddress;
				this->_memory_length = vTempLength;
				this->_memory_capacity = vTempCapacity;
				return true;
			}
		}
	}
	return false;
}

// Replace Memory
bool XAllocator::MemoryReplace(size_type _Pos, size_type _Length, const XAllocator& _Allocator) noexcept
{
	_Pos = this->MemoryPosFix(_Pos);
	return this->MemoryReplace(_Pos, _Length, _Allocator._memory_address, _Allocator._memory_length);
}




// Get the address of the memory
void* XAllocator::MemoryAddress() noexcept
{
	return this->_memory_address;
}

// Get the address of the memory
const void* XAllocator::MemoryAddress() const noexcept
{
	return this->_memory_address;
}

// Get the length of the memory
XAllocator::size_type XAllocator::MemoryLength() const noexcept
{
	return this->_memory_length;
}

// Get the capacity of the memory
XAllocator::size_type XAllocator::MemoryCapacity() const noexcept
{
	return this->_memory_capacity;
}
