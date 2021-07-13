#include <XanaduCore/XAllocator.h>
#include <XanaduCore/XRuntime.h>


#define XANADU_ALLOCATOR_DELETE(_Address)			if((_Address)){ delete[] static_cast<char*>(_Address); _Address = nullptr;}

// 根据输入长度计算合适的容量
XAllocator::size_type XanaduAllocatorCalculateCapacity(XAllocator::size_type _Length)
{
	// 缺省情况下，长度增加128个字节
	return _Length + 128;
};

// Xanadu内存分配器请求内存
char* XanaduAllocatorMallocMemory(XAllocator::size_type _Size)
{
	auto		vSize = static_cast<size_t>(_Size);
	return XANADU_NEW char[vSize];
}

// constructor
XAllocator::XAllocator() noexcept
{
	this->memoryAllocator(0);
}

// constructor
XAllocator::XAllocator(size_type _Length) noexcept
{
	this->memoryAllocator(_Length);
}

// constructor
XAllocator::XAllocator(size_type _Length, char _Char) noexcept
{
	this->memoryAllocator(_Length);
	Xanadu::memset(this->_memory_address, _Char, this->_memory_length);
}

// constructor
XAllocator::XAllocator(const void* _Memory, size_type _Length) noexcept
{
	this->memoryAllocator(_Memory, _Length);
}

// constructor
XAllocator::XAllocator(const XAllocator& _Allocator) noexcept
{
	this->memoryAllocator(_Allocator._memory_address, _Allocator._memory_length);
}

// Destructor
XAllocator::~XAllocator() noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);
	this->_memory_length = 0;
	this->_memory_capacity = 0;
}



// operators overload =
XAllocator& XAllocator::operator = (const XAllocator& _Allocator) noexcept
{
	this->memoryCopy(_Allocator);
	return *this;
}

// operators overload +
XAllocator XAllocator::operator + (const XAllocator& _Allocator) noexcept
{
	auto		vResult = *this;
	vResult.memoryAppend(_Allocator);
	return vResult;
}

// operators overload +=
XAllocator& XAllocator::operator += (const XAllocator& _Allocator) noexcept
{
	this->memoryAppend(_Allocator);
	return *this;
}





// Fix Pos
XAllocator::size_type XAllocator::memoryFixSize(size_type _Pos) const noexcept
{
	if (_Pos == XAllocator::npos)
	{
		return 0U;
	}
	else if(_Pos > this->_memory_length)
	{
		return this->_memory_length;
	}
	return _Pos;
}

// Check whether it is empty, and return true when the length is 0
bool XAllocator::memoryIsEmpty() const noexcept
{
	return this->_memory_length == 0;
}

// Check whether there is a value, and return true when the length is not 0
bool XAllocator::memoryIsExist() const noexcept
{
	return !this->memoryIsEmpty();
}







// Allocator memory
bool XAllocator::memoryAllocator(size_type _Length) noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);

	// 当传入的值不是一个正确的大小时，分配一个默认的大小
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
		this->_memory_length = 0U;
		this->_memory_capacity = 0U;
		return false;
	}
}

// Allocator memory
bool XAllocator::memoryAllocator(const void* _Memory, size_type _Length) noexcept
{
	if(this->memoryAllocator(_Length))
	{
		if(_Length > 0 && _Memory)
		{
			Xanadu::memcpy(this->_memory_address, _Memory, _Length);
			return true;
		}
	}
	return false;
}

// _clear memory
void XAllocator::memoryRelease() noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);
	this->_memory_length = 0U;
	this->_memory_capacity = 0U;
	this->memoryAllocator(0);
}

// append memory
bool XAllocator::memoryAppend(size_type _Length) noexcept
{
	if(_Length > 0)
	{
		// 当剩余容量足够时，不会重新分配内存
		if(this->_memory_capacity - this->_memory_length > _Length)
		{
			this->_memory_length += _Length;
			return true;
		}

		// 重新分配内存并移动原始值
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
	}
	return false;
}

// append memory
bool XAllocator::memoryAppend(size_type _Length, char _Char) noexcept
{
	if(_Length > 0)
	{
		// 保留原始长度
		auto		vTempLength = this->_memory_length;
		if(this->memoryAppend(_Length))
		{
			// 从原始长度写入传入值
			Xanadu::memset(static_cast<char*>(this->_memory_address) + vTempLength, _Char, _Length);
			return true;
		}
	}
	return false;
}

// append memory
bool XAllocator::memoryAppend(const void* _Memory, size_type _Length) noexcept
{
	if(_Memory && _Length > 0)
	{
		// 保留原始长度
		auto		vTempLength = this->_memory_length;
		if(this->memoryAppend(_Length))
		{
			// 从原始长度写入传入值
			Xanadu::memcpy(static_cast<char*>(this->_memory_address) + vTempLength, _Memory, _Length);
			return true;
		}
	}
	return false;
}

// append memory
bool XAllocator::memoryAppend(const XAllocator& _Allocator) noexcept
{
	return this->memoryAppend(_Allocator._memory_address, _Allocator._memory_length);
}

// Reduce memory
bool XAllocator::memoryReduce(size_type _Length) noexcept
{
	if(_Length > 0U)
	{
		// 如果缩小后的值大于长度，则删除所有
		if (_Length >= this->_memory_length)
		{
			memoryRelease();
			return true;
		}

		// 重建内存并移动源
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
	}
	return false;
}

// Resize memory
bool XAllocator::memoryResize(size_type _Length) noexcept
{
	if (_Length > this->_memory_length)
	{
		return this->memoryAppend(_Length - this->_memory_length);
	}
	else if(_Length < this->_memory_length)
	{
		return this->memoryReduce(this->_memory_length - _Length);
	}
	else
	{
		return true;
	}
}

// truncate memory
void XAllocator::memoryTruncate(size_type _Pos) noexcept
{
	if (_Pos < this->_memory_length)
	{
		this->memoryResize(_Pos);
	}
}

// Insert memory
bool XAllocator::memoryInsert(size_type _Pos, size_type _Length) noexcept
{
	if(_Length > 0U)
	{
		_Pos = this->memoryFixSize(_Pos);

		// 当位置大于或等于长度时，在末尾添加
		if(_Pos >= this->_memory_length)
		{
			return this->memoryAppend(_Length);
		}

		// 构建新的内存并复制旧数据和传入数据
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
	}
	return false;
}

// Insert memory
bool XAllocator::memoryInsert(size_type _Pos, const void* _Memory, size_type _Length) noexcept
{
	if(_Length > 0U)
	{
		_Pos = this->memoryFixSize(_Pos);
		if(this->memoryInsert(_Pos, _Length))
		{
			if(_Memory)
			{
				Xanadu::memcpy(static_cast<char*>(this->_memory_address) + _Pos, _Memory, _Length);
			}
			return true;
		}
	}
	return false;
}

// remove memory
bool XAllocator::memoryRemove(size_type _Pos, size_type _Length) noexcept
{
	if(_Length > 0U)
	{
		_Pos = this->memoryFixSize(_Pos);
		// 如果从末尾删除，则调用MemoryReduce函数
		if (this->_memory_length - _Pos <= _Length)
		{
			return this->memoryReduce(this->_memory_length - _Pos);
		}

		// 构建新的内存并复制其余的内存
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
	}
	return false;
}

// Copy Memory
bool XAllocator::memoryCopy(const void* _Memory, size_type _Length) noexcept
{
	this->memoryRelease();

	if(_Length > 0U)
	{
		return this->memoryAllocator(_Memory, _Length);
	}
	return false;
}

// Copy Memory
bool XAllocator::memoryCopy(const XAllocator& _Allocator) noexcept
{
	return this->memoryCopy(_Allocator._memory_address, _Allocator._memory_length);
}

// Move Memory
bool XAllocator::memoryMove(XAllocator& _Allocator) noexcept
{
	XANADU_ALLOCATOR_DELETE(this->_memory_address);

	this->_memory_address = _Allocator._memory_address;
	this->_memory_length = _Allocator._memory_length;
	this->_memory_capacity = _Allocator._memory_capacity;

	_Allocator._memory_address = nullptr;
	_Allocator._memory_length = 0LL;
	_Allocator._memory_capacity = 0LL;
	return _Allocator.memoryAllocator(0);
}

// find Memory
XAllocator::size_type XAllocator::memoryFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept
{
	_Pos = this->memoryFixSize(_Pos);
	if (_Memory && _Length > 0U && _Pos < this->_memory_length)
	{
		auto		vSourceMemory = static_cast<const char*>(this->_memory_address) + _Pos;
		auto		vSourceLength = this->_memory_length - _Pos;
		auto		vTargetMemory = static_cast<const char*>(_Memory);

		for (auto vSourceIndex = 0U; vSourceIndex < vSourceLength; ++vSourceIndex)
		{
			auto		vFind = true;
			for (auto vTargetIndex = 0U; vTargetIndex < _Length && vFind; ++vTargetIndex)
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
	return XAllocator::npos;
}

// find Memory
XAllocator::size_type XAllocator::memoryFind(size_type _Pos, const XAllocator& _Allocator) const noexcept
{
	_Pos = this->memoryFixSize(_Pos);
	return this->memoryFind(_Pos, _Allocator._memory_address, _Allocator._memory_length);
}

// Reverse find Memory
XAllocator::size_type XAllocator::memoryReverseFind(size_type _Pos, const void* _Memory, size_type _Length) const noexcept
{
	_Pos = this->memoryFixSize(_Pos);
	if (_Memory && _Length > 0U && _Pos < this->_memory_length)
	{
		auto		vSourceMemory = static_cast<const char*>(this->_memory_address) + _Pos;
		auto		vSourceBegin = this->_memory_length - _Length > _Pos ? _Pos : this->_memory_length - _Length;
		auto		vTargetMemory = static_cast<const char*>(_Memory);

		for (auto vSourceIndex = vSourceBegin; vSourceIndex != XAllocator::npos; --vSourceIndex)
		{
			auto		vFind = true;
			for (auto vTargetIndex = 0U; vTargetIndex < _Length && vFind; ++vTargetIndex)
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
	return XAllocator::npos;
}

// Reverse find Memory
XAllocator::size_type XAllocator::memoryReverseFind(size_type _Pos, const XAllocator& _Allocator) const noexcept
{
	_Pos = this->memoryFixSize(_Pos);
	return this->memoryReverseFind(_Pos, _Allocator._memory_address, _Allocator._memory_length);
}

// compare
int XAllocator::memoryCompare(const void* _Memory, size_type _Length) const noexcept
{
	if(this->_memory_address == _Memory)
	{
		return 0;
	}
	auto		vCompare = Xanadu::memcmp(this->_memory_address, _Memory, this->_memory_length > _Length ? _Length : this->_memory_length);
	if(vCompare == 0)
	{
		return this->_memory_length > _Length ? 1 : -1;
	}
	return vCompare;
}

// Replace Memory
bool XAllocator::memoryReplace(size_type _Pos, size_type _Length, const void* _Memory, size_type _Size) noexcept
{
	if(_Length > 0 && _Size != XAllocator::npos)
	{
		_Pos = this->memoryFixSize(_Pos);
		if(_Pos < this->_memory_length && (_Pos + _Length) < this->_memory_length && _Memory)
		{
			// 如果源和目标的长度相同，则不分配内存
			if (_Length == _Size)
			{
				Xanadu::memcpy(static_cast<char*>(this->_memory_address) + _Pos, _Memory, _Size);
				return true;
			}
			else
			{
				// 重新分配内存并复制源值和替换值
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
	}
	return false;
}

// Replace Memory
bool XAllocator::memoryReplace(size_type _Pos, size_type _Length, const XAllocator& _Allocator) noexcept
{
	_Pos = this->memoryFixSize(_Pos);
	return this->memoryReplace(_Pos, _Length, _Allocator._memory_address, _Allocator._memory_length);
}




// Get the address of the memory
char* XAllocator::memoryAddress() noexcept
{
	return this->_memory_address;
}

// Get the address of the memory
const char* XAllocator::memoryAddress() const noexcept
{
	return this->_memory_address;
}

// Get the length of the memory
XAllocator::size_type XAllocator::memoryLength() const noexcept
{
	return this->_memory_length;
}

// Get the capacity of the memory
XAllocator::size_type XAllocator::memoryCapacity() const noexcept
{
	return this->_memory_capacity;
}
