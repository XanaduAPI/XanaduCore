//
// Created by Administrator on 2021/1/14.
//

#ifndef			_XANADU_CORE_ENDIAN_H_
#define			_XANADU_CORE_ENDIAN_H_

#include <XanaduCore/XanaduCoreHeader.h>

/// Endian
class XANADU_CORE_EXPORT XEndian
{
public:
	XEndian() XANADU_NOTHROW;

	virtual ~XEndian() XANADU_NOTHROW;

public:
	/// 判断系统是否大端字节序
	static bool IsBig() XANADU_NOTHROW;

	/// 判断系统是否小端字节序
	static bool IsLittle() XANADU_NOTHROW;

public:
	/// 倒序:int16S
	static int16S Reverse(int16S _Value) XANADU_NOTHROW;

	/// 倒序:int16U
	static int16U Reverse(int16U _Value) XANADU_NOTHROW;

	/// 倒序:int32S
	static int32S Reverse(int32S _Value) XANADU_NOTHROW;

	/// 倒序:int32U
	static int32U Reverse(int32U _Value) XANADU_NOTHROW;

	/// 倒序:int64S
	static int64S Reverse(int64S _Value) XANADU_NOTHROW;

	/// 倒序:int64U
	static int64U Reverse(int64U _Value) XANADU_NOTHROW;

public:
	/// Local >> Network : int16S
	static int16S LocalToNetwork(int16S _Value) XANADU_NOTHROW;

	/// Local >> Network : int16U
	static int16U LocalToNetwork(int16U _Value) XANADU_NOTHROW;

	/// Local >> Network : int32S
	static int32S LocalToNetwork(int32S _Value) XANADU_NOTHROW;

	/// Local >> Network : int32U
	static int32U LocalToNetwork(int32U _Value) XANADU_NOTHROW;

	/// Local >> Network : int64S
	static int64S LocalToNetwork(int64S _Value) XANADU_NOTHROW;

	/// Local >> Network : int64U
	static int64U LocalToNetwork(int64U _Value) XANADU_NOTHROW;

public:
	/// Network >> Local : int16S
	static int16S NetworkToLocal(int16S _Value) XANADU_NOTHROW;

	/// Network >> Local : int16U
	static int16U NetworkToLocal(int16U _Value) XANADU_NOTHROW;

	/// Network >> Local : int32S
	static int32S NetworkToLocal(int32S _Value) XANADU_NOTHROW;

	/// Network >> Local : int32U
	static int32U NetworkToLocal(int32U _Value) XANADU_NOTHROW;

	/// Network >> Local : int64S
	static int64S NetworkToLocal(int64S _Value) XANADU_NOTHROW;

	/// Network >> Local : int64U
	static int64U NetworkToLocal(int64U _Value) XANADU_NOTHROW;

public:
	/// HOST >> Big Endian : int16S
	static int16S HostToBig(int16S _Value) XANADU_NOTHROW;

	/// HOST >> Big Endian : int16U
	static int16U HostToBig(int16U _Value) XANADU_NOTHROW;

	/// HOST >> Big Endian : int32S
	static int32S HostToBig(int32S _Value) XANADU_NOTHROW;

	/// HOST >> Big Endian : int32U
	static int32U HostToBig(int32U _Value) XANADU_NOTHROW;

	/// HOST >> Big Endian : int64S
	static int64S HostToBig(int64S _Value) XANADU_NOTHROW;

	/// HOST >> Big Endian : int64U
	static int64U HostToBig(int64U _Value) XANADU_NOTHROW;

public:
	/// Big Endian >> HOST : int16S
	static int16S BigToHost(int16S _Value) XANADU_NOTHROW;

	/// Big Endian >> HOST : int16U
	static int16U BigToHost(int16U _Value) XANADU_NOTHROW;

	/// Big Endian >> HOST : int32S
	static int32S BigToHost(int32S _Value) XANADU_NOTHROW;

	/// Big Endian >> HOST : int32U
	static int32U BigToHost(int32U _Value) XANADU_NOTHROW;

	/// Big Endian >> HOST : int64S
	static int64S BigToHost(int64S _Value) XANADU_NOTHROW;

	/// Big Endian >> HOST : int64U
	static int64U BigToHost(int64U _Value) XANADU_NOTHROW;

public:
	/// HOST >> Little Endian : int16S
	static int16S HostToLittle(int16S _Value) XANADU_NOTHROW;

	/// HOST >> Little Endian : int16U
	static int16U HostToLittle(int16U _Value) XANADU_NOTHROW;

	/// HOST >> Little Endian : int32S
	static int32S HostToLittle(int32S _Value) XANADU_NOTHROW;

	/// HOST >> Little Endian : int32U
	static int32U HostToLittle(int32U _Value) XANADU_NOTHROW;

	/// HOST >> Little Endian : int64S
	static int64S HostToLittle(int64S _Value) XANADU_NOTHROW;

	/// HOST >> Little Endian : int64U
	static int64U HostToLittle(int64U _Value) XANADU_NOTHROW;

public:
	/// Little Endian >> HOST : int16S
	static int16S LittleToHost(int16S _Value) XANADU_NOTHROW;

	/// Little Endian >> HOST : int16U
	static int16U LittleToHost(int16U _Value) XANADU_NOTHROW;

	/// Little Endian >> HOST : int32S
	static int32S LittleToHost(int32S _Value) XANADU_NOTHROW;

	/// Little Endian >> HOST : int32U
	static int32U LittleToHost(int32U _Value) XANADU_NOTHROW;

	/// Little Endian >> HOST : int64S
	static int64S LittleToHost(int64S _Value) XANADU_NOTHROW;

	/// Little Endian >> HOST : int64U
	static int64U LittleToHost(int64U _Value) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_ENDIAN_H_
