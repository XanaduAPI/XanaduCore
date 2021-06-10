#include <XanaduCore/endian.h>


// constructor
Xanadu::endian::endian() noexcept
{
}

// destructor
Xanadu::endian::~endian() noexcept
{
}





// Check whether the operating system is in big-endian order
bool Xanadu::endian::is_big() noexcept
{
	return !Xanadu::endian::is_little();
}

// Check whether the operating system is in little-endian order
bool Xanadu::endian::is_little() noexcept
{
	union UCheck_Little
	{
		int		_VALUE4;
		char		_VALUE1;
	}_ValueLittle{};
	_ValueLittle._VALUE4 = 1;
	// The big-endian returns 0 and the little-endian returns 1
	return _ValueLittle._VALUE1 == 1;
}





// reverse : memory
void Xanadu::endian::reverse(void* _Memory, std::size_t _Size) noexcept
{
	if(_Memory != nullptr && _Size > 0)
	{
		auto		vBuffer = (char*)_Memory;
		char		vTemp = 0;
		for(std::size_t vIndex = 0; vIndex < _Size / 2; ++vIndex)
		{
			vTemp = vBuffer[vIndex];
			vBuffer[vIndex] = vBuffer[_Size - vIndex - 1];
			vBuffer[_Size - vIndex - 1] = vTemp;
		}
	}
}





// reverse : short
short Xanadu::endian::reverse(short _Number) noexcept
{
	return (short)Xanadu::endian::reverse((unsigned short)_Number);
}

// reverse : unsigned short
unsigned short Xanadu::endian::reverse(unsigned short _Number) noexcept
{
	return (((_Number & 0x00FF) << 8) | ((_Number & 0xFF00) >> 8));
}

// reverse : int
int Xanadu::endian::reverse(int _Number) noexcept
{
	return (int)Xanadu::endian::reverse((unsigned int)_Number);
}

// reverse : unsigned int
unsigned int Xanadu::endian::reverse(unsigned int _Number) noexcept
{
	return (((_Number & 0xFF000000) >> 24) | ((_Number & 0x00FF0000) >> 8) | ((_Number & 0x0000FF00) << 8) | ((_Number & 0x000000FF) << 24));
}

// reverse : long
long Xanadu::endian::reverse(long _Number) noexcept
{
	return (long)Xanadu::endian::reverse((unsigned long)_Number);
}

// reverse : unsigned long
unsigned long Xanadu::endian::reverse(unsigned long _Number) noexcept
{
	if(sizeof(unsigned long) == 4)
	{
		return (unsigned long)Xanadu::endian::reverse((unsigned int)_Number);
	}
	else
	{
		return (unsigned long)Xanadu::endian::reverse((unsigned long long)_Number);
	}
}

// reverse : long long
long long Xanadu::endian::reverse(long long _Number) noexcept
{
	return (long long)Xanadu::endian::reverse((unsigned long long)_Number);
}

// reverse : unsigned short
unsigned long long Xanadu::endian::reverse(unsigned long long _Number) noexcept
{
	return (((_Number & 0x00000000000000FFUL) << 56) | ((_Number & 0x000000000000FF00UL) << 40) |
	((_Number & 0x0000000000FF0000UL) << 24) | ((_Number & 0x00000000FF000000UL) << 8) |
	((_Number & 0x000000FF00000000UL) >> 8) | ((_Number & 0x0000FF0000000000UL) >> 24) |
	((_Number & 0x00FF000000000000UL) >> 40) | ((_Number & 0xFF00000000000000UL) >> 56));
}





// Conversion from native byte order to network byte order : short
short Xanadu::endian::host_to_network(short _Number) noexcept
{
	return (short)Xanadu::endian::host_to_network((unsigned short)_Number);
}

// Conversion from native byte order to network byte order : unsigned short
unsigned short Xanadu::endian::host_to_network(unsigned short _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return (((_Number & 0x00FF) << 8) | ((_Number & 0xFF00) >> 8));
	}
	return _Number;
}

// Conversion from native byte order to network byte order : int
int Xanadu::endian::host_to_network(int _Number) noexcept
{
	return (int)Xanadu::endian::host_to_network((unsigned int)_Number);
}

// Conversion from native byte order to network byte order : unsigned int
unsigned int Xanadu::endian::host_to_network(unsigned int _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return (((_Number & 0xFF000000) >> 24) | ((_Number & 0x00FF0000) >> 8) | ((_Number & 0x0000FF00) << 8) | ((_Number & 0x000000FF) << 24));
	}
	return _Number;
}

// Conversion from native byte order to network byte order : long
long Xanadu::endian::host_to_network(long _Number) noexcept
{
	return (long)Xanadu::endian::host_to_network((unsigned long)_Number);
}

// Conversion from native byte order to network byte order : unsigned long
unsigned long Xanadu::endian::host_to_network(unsigned long _Number) noexcept
{
	if(sizeof(unsigned long) == 4)
	{
		return (unsigned long)Xanadu::endian::host_to_network((unsigned int)_Number);
	}
	else
	{
		return (unsigned long)Xanadu::endian::host_to_network((unsigned long long)_Number);
	}
}

// Conversion from native byte order to network byte order : long long
long long Xanadu::endian::host_to_network(long long _Number) noexcept
{
	return (long long)Xanadu::endian::host_to_network((unsigned long long)_Number);
}

// Conversion from native byte order to network byte order : unsigned short
unsigned long long Xanadu::endian::host_to_network(unsigned long long _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return (((_Number & 0x00000000000000FFUL) << 56) | ((_Number & 0x000000000000FF00UL) << 40) |
			((_Number & 0x0000000000FF0000UL) << 24) | ((_Number & 0x00000000FF000000UL) << 8) |
			((_Number & 0x000000FF00000000UL) >> 8) | ((_Number & 0x0000FF0000000000UL) >> 24) |
			((_Number & 0x00FF000000000000UL) >> 40) | ((_Number & 0xFF00000000000000UL) >> 56));
	}
	return _Number;
}





// Conversion from network byte order to native byte order : short
short Xanadu::endian::network_to_host(short _Number) noexcept
{
	return (short)Xanadu::endian::network_to_host((unsigned short)_Number);
}

// Conversion from network byte order to native byte order : unsigned short
unsigned short Xanadu::endian::network_to_host(unsigned short _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return (((_Number & 0x00FF) << 8) | ((_Number & 0xFF00) >> 8));
	}
	return _Number;
}

// Conversion from network byte order to native byte order : int
int Xanadu::endian::network_to_host(int _Number) noexcept
{
	return (int)Xanadu::endian::network_to_host((unsigned int)_Number);
}

// Conversion from network byte order to native byte order : unsigned int
unsigned int Xanadu::endian::network_to_host(unsigned int _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return (((_Number & 0xFF000000) >> 24) | ((_Number & 0x00FF0000) >> 8) | ((_Number & 0x0000FF00) << 8) | ((_Number & 0x000000FF) << 24));
	}
	return _Number;
}

// Conversion from network byte order to native byte order : long
long Xanadu::endian::network_to_host(long _Number) noexcept
{
	return (long)Xanadu::endian::network_to_host((unsigned long)_Number);
}

// Conversion from network byte order to native byte order : unsigned long
unsigned long Xanadu::endian::network_to_host(unsigned long _Number) noexcept
{
	if(sizeof(unsigned long) == 4)
	{
		return (unsigned long)Xanadu::endian::network_to_host((unsigned int)_Number);
	}
	else
	{
		return (unsigned long)Xanadu::endian::network_to_host((unsigned long long)_Number);
	}
}

// Conversion from network byte order to native byte order : long long
long long Xanadu::endian::network_to_host(long long _Number) noexcept
{
	return (long long)Xanadu::endian::network_to_host((unsigned long long)_Number);
}

// Conversion from network byte order to native byte order : unsigned short
unsigned long long Xanadu::endian::network_to_host(unsigned long long _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return (((_Number & 0x00000000000000FFUL) << 56) | ((_Number & 0x000000000000FF00UL) << 40) |
			((_Number & 0x0000000000FF0000UL) << 24) | ((_Number & 0x00000000FF000000UL) << 8) |
			((_Number & 0x000000FF00000000UL) >> 8) | ((_Number & 0x0000FF0000000000UL) >> 24) |
			((_Number & 0x00FF000000000000UL) >> 40) | ((_Number & 0xFF00000000000000UL) >> 56));
	}
	return _Number;
}





// Conversion from native byte order to big-endian order : short
short Xanadu::endian::host_to_big(short _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}

// Conversion from native byte order to big-endian order : unsigned short
unsigned short Xanadu::endian::host_to_big(unsigned short _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}

// Conversion from native byte order to big-endian order : int
int Xanadu::endian::host_to_big(int _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}

// Conversion from native byte order to big-endian order : unsigned int
unsigned int Xanadu::endian::host_to_big(unsigned int _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}

// Conversion from native byte order to big-endian order : long
long Xanadu::endian::host_to_big(long _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}

// Conversion from native byte order to big-endian order : unsigned long
unsigned long Xanadu::endian::host_to_big(unsigned long _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}

// Conversion from native byte order to big-endian order : long long
long long Xanadu::endian::host_to_big(long long _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}

// Conversion from native byte order to big-endian order : unsigned short
unsigned long long Xanadu::endian::host_to_big(unsigned long long _Number) noexcept
{
	return Xanadu::endian::host_to_network(_Number);
}





// Conversion from big-endian order to native byte order : short
short Xanadu::endian::big_to_host(short _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}

// Conversion from big-endian order to native byte order : unsigned short
unsigned short Xanadu::endian::big_to_host(unsigned short _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}

// Conversion from big-endian order to native byte order : int
int Xanadu::endian::big_to_host(int _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}

// Conversion from big-endian order to native byte order : unsigned int
unsigned int Xanadu::endian::big_to_host(unsigned int _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}

// Conversion from big-endian order to native byte order : long
long Xanadu::endian::big_to_host(long _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}

// Conversion from big-endian order to native byte order : unsigned long
unsigned long Xanadu::endian::big_to_host(unsigned long _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}

// Conversion from big-endian order to native byte order : long long
long long Xanadu::endian::big_to_host(long long _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}

// Conversion from big-endian order to native byte order : unsigned short
unsigned long long Xanadu::endian::big_to_host(unsigned long long _Number) noexcept
{
	return Xanadu::endian::network_to_host(_Number);
}




// Conversion from native byte order to little-endian order : short
short Xanadu::endian::host_to_little(short _Number) noexcept
{
	return (short)Xanadu::endian::host_to_little((unsigned short)_Number);
}

// Conversion from native byte order to little-endian order : unsigned short
unsigned short Xanadu::endian::host_to_little(unsigned short _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return _Number;
	}
	return (((_Number & 0x00FF) << 8) | ((_Number & 0xFF00) >> 8));
}

// Conversion from native byte order to little-endian order : int
int Xanadu::endian::host_to_little(int _Number) noexcept
{
	return (int)Xanadu::endian::host_to_little((unsigned int)_Number);
}

// Conversion from native byte order to little-endian order : unsigned int
unsigned int Xanadu::endian::host_to_little(unsigned int _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return _Number;
	}
	return (((_Number & 0xFF000000) >> 24) | ((_Number & 0x00FF0000) >> 8) | ((_Number & 0x0000FF00) << 8) | ((_Number & 0x000000FF) << 24));
}

// Conversion from native byte order to little-endian order : long
long Xanadu::endian::host_to_little(long _Number) noexcept
{
	return (long)Xanadu::endian::host_to_little((unsigned long)_Number);
}

// Conversion from native byte order to little-endian order : unsigned long
unsigned long Xanadu::endian::host_to_little(unsigned long _Number) noexcept
{
	if(sizeof(unsigned long) == 4)
	{
		return (unsigned long)Xanadu::endian::host_to_little((unsigned int)_Number);
	}
	else
	{
		return (unsigned long)Xanadu::endian::host_to_little((unsigned long long)_Number);
	}
}

// Conversion from native byte order to little-endian order : long long
long long Xanadu::endian::host_to_little(long long _Number) noexcept
{
	return (long long)Xanadu::endian::host_to_little((unsigned long long)_Number);
}

// Conversion from native byte order to little-endian order : unsigned short
unsigned long long Xanadu::endian::host_to_little(unsigned long long _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return _Number;
	}
	return (((_Number & 0x00000000000000FFUL) << 56) | ((_Number & 0x000000000000FF00UL) << 40) |
		((_Number & 0x0000000000FF0000UL) << 24) | ((_Number & 0x00000000FF000000UL) << 8) |
		((_Number & 0x000000FF00000000UL) >> 8) | ((_Number & 0x0000FF0000000000UL) >> 24) |
		((_Number & 0x00FF000000000000UL) >> 40) | ((_Number & 0xFF00000000000000UL) >> 56));
}





// Conversion from little-endian order to native byte order : short
short Xanadu::endian::little_to_host(short _Number) noexcept
{
	return (short)Xanadu::endian::little_to_host((unsigned short)_Number);
}

// Conversion from little-endian order to native byte order : unsigned short
unsigned short Xanadu::endian::little_to_host(unsigned short _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return _Number;
	}
	return (((_Number & 0x00FF) << 8) | ((_Number & 0xFF00) >> 8));
}

// Conversion from little-endian order to native byte order : int
int Xanadu::endian::little_to_host(int _Number) noexcept
{
	return (int)Xanadu::endian::little_to_host((unsigned int)_Number);
}

// Conversion from little-endian order to native byte order : unsigned int
unsigned int Xanadu::endian::little_to_host(unsigned int _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return _Number;
	}
	return (((_Number & 0xFF000000) >> 24) | ((_Number & 0x00FF0000) >> 8) | ((_Number & 0x0000FF00) << 8) | ((_Number & 0x000000FF) << 24));
}

// Conversion from little-endian order to native byte order : long
long Xanadu::endian::little_to_host(long _Number) noexcept
{
	return (long)Xanadu::endian::little_to_host((unsigned long)_Number);
}

// Conversion from little-endian order to native byte order : unsigned long
unsigned long Xanadu::endian::little_to_host(unsigned long _Number) noexcept
{
	if(sizeof(unsigned long) == 4)
	{
		return (unsigned long)Xanadu::endian::little_to_host((unsigned int)_Number);
	}
	else
	{
		return (unsigned long)Xanadu::endian::little_to_host((unsigned long long)_Number);
	}
}

// Conversion from little-endian order to native byte order : long long
long long Xanadu::endian::little_to_host(long long _Number) noexcept
{
	return (long long)Xanadu::endian::little_to_host((unsigned long long)_Number);
}

// Conversion from little-endian order to native byte order : unsigned short
unsigned long long Xanadu::endian::little_to_host(unsigned long long _Number) noexcept
{
	if(Xanadu::endian::is_little())
	{
		return _Number;
	}
	return (((_Number & 0x00000000000000FFUL) << 56) | ((_Number & 0x000000000000FF00UL) << 40) |
		((_Number & 0x0000000000FF0000UL) << 24) | ((_Number & 0x00000000FF000000UL) << 8) |
		((_Number & 0x000000FF00000000UL) >> 8) | ((_Number & 0x0000FF0000000000UL) >> 24) |
		((_Number & 0x00FF000000000000UL) >> 40) | ((_Number & 0xFF00000000000000UL) >> 56));
}