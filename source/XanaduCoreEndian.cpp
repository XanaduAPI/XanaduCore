//
// Created by Administrator on 2021/1/14.
//

#include <XanaduCore/XanaduCoreEndian.h>

XEndian::XEndian() noexcept
{
}

XEndian::~XEndian() noexcept
{
}





// 判断系统是否大端字节序
bool XEndian::IsBig() noexcept
{
	int		_Value = static_cast<int>(1);
	return ((*(char*)&_Value)) == static_cast<char>(1);
}

// 判断系统是否小端字节序
bool XEndian::IsLittle() noexcept
{
	int		_Value = static_cast<int>(1);
	return ((*(char*)&_Value)) == static_cast<char>(0);
}





// 倒序:int16S
int16S XEndian::Reverse(int16S _Value) noexcept
{
	return (((_Value & 0x00FF) << 8) | ((_Value & 0xFF00) >> 8));
}

// 倒序:int16U
int16U XEndian::Reverse(int16U _Value) noexcept
{
	return (((_Value & 0x00FFU) << 8) | ((_Value & 0xFF00U) >> 8));
}

// 倒序:int32S
int32S XEndian::Reverse(int32S _Value) noexcept
{
	return (((_Value & 0xFF000000) >> 24) | ((_Value & 0x00FF0000) >> 8) | ((_Value & 0x0000FF00) << 8) | ((_Value & 0x000000FF) << 24));
}

// 倒序:int32U
int32U XEndian::Reverse(int32U _Value) noexcept
{
	return (((_Value & 0xFF000000U) >> 24) | ((_Value & 0x00FF0000U) >> 8) | ((_Value & 0x0000FF00U) << 8) | ((_Value & 0x000000FFU) << 24));
}

// 倒序:int64S
int64S XEndian::Reverse(int64S _Value) noexcept
{
	return (((_Value & 0x00000000000000FFL) << 56) | ((_Value & 0x000000000000FF00L) << 40) | ((_Value & 0x0000000000FF0000L) << 24) | ((_Value & 0x00000000FF000000L) << 8) | ((_Value & 0x000000FF00000000L) >> 8) | ((_Value & 0x0000FF0000000000L) >> 24) | ((_Value & 0x00FF000000000000L) >> 40) | ((_Value & 0xFF00000000000000L) >> 56));
}

// 倒序:int64U
int64U XEndian::Reverse(int64U _Value) noexcept
{
	return (((_Value & 0x00000000000000FFUL) << 56) | ((_Value & 0x000000000000FF00UL) << 40) | ((_Value & 0x0000000000FF0000UL) << 24) | ((_Value & 0x00000000FF000000UL) << 8) | ((_Value & 0x000000FF00000000UL) >> 8) | ((_Value & 0x0000FF0000000000UL) >> 24) | ((_Value & 0x00FF000000000000UL) >> 40) | ((_Value & 0xFF00000000000000UL) >> 56));
}





// Local >> Network : int16S
int16S XEndian::LocalToNetwork(int16S _Value) noexcept
{
	if (XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Local >> Network : int16U
int16U XEndian::LocalToNetwork(int16U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Local >> Network : int32S
int32S XEndian::LocalToNetwork(int32S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Local >> Network : int32U
int32U XEndian::LocalToNetwork(int32U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Local >> Network : int64S
int64S XEndian::LocalToNetwork(int64S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Local >> Network : int64U
int64U XEndian::LocalToNetwork(int64U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}





// Network >> Local : int16S
int16S XEndian::NetworkToLocal(int16S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Network >> Local : int16U
int16U XEndian::NetworkToLocal(int16U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Network >> Local : int32S
int32S XEndian::NetworkToLocal(int32S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Network >> Local : int32U
int32U XEndian::NetworkToLocal(int32U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Network >> Local : int64S
int64S XEndian::NetworkToLocal(int64S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}

// Network >> Local : int64U
int64U XEndian::NetworkToLocal(int64U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return Reverse(_Value);
	}
}





// HOST >> Big Endian : int16S
int16S XEndian::HostToBig(int16S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Big Endian : int16U
int16U XEndian::HostToBig(int16U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Big Endian : int32S
int32S XEndian::HostToBig(int32S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Big Endian : int32U
int32U XEndian::HostToBig(int32U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Big Endian : int64S
int64S XEndian::HostToBig(int64S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Big Endian : int64U
int64U XEndian::HostToBig(int64U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}






// Big Endian >> HOST : int16S
int16S XEndian::BigToHost(int16S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Big Endian >> HOST : int16U
int16U XEndian::BigToHost(int16U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Big Endian >> HOST : int32S
int32S XEndian::BigToHost(int32S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Big Endian >> HOST : int32U
int32U XEndian::BigToHost(int32U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Big Endian >> HOST : int64S
int64S XEndian::BigToHost(int64S _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Big Endian >> HOST : int64U
int64U XEndian::BigToHost(int64U _Value) noexcept
{
	if(XEndian::IsBig())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}





// HOST >> Little Endian : int16S
int16S XEndian::HostToLittle(int16S _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Little Endian : int16U
int16U XEndian::HostToLittle(int16U _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Little Endian : int32S
int32S XEndian::HostToLittle(int32S _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Little Endian : int32U
int32U XEndian::HostToLittle(int32U _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Little Endian : int64S
int64S XEndian::HostToLittle(int64S _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// HOST >> Little Endian : int64U
int64U XEndian::HostToLittle(int64U _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}






// Little Endian >> HOST : int16S
int16S XEndian::LittleToHost(int16S _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Little Endian >> HOST : int16U
int16U XEndian::LittleToHost(int16U _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Little Endian >> HOST : int32S
int32S XEndian::LittleToHost(int32S _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Little Endian >> HOST : int32U
int32U XEndian::LittleToHost(int32U _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Little Endian >> HOST : int64S
int64S XEndian::LittleToHost(int64S _Value) noexcept
{
	if(XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}

// Little Endian >> HOST : int64U
int64U XEndian::LittleToHost(int64U _Value) noexcept
{
	if (XEndian::IsLittle())
	{
		return _Value;
	}
	else
	{
		return XEndian::Reverse(_Value);
	}
}
