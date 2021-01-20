//
// Created by Administrator on 2021/1/20.
//

#include <XanaduCore/XanaduCoreBase64.h>


/// Structure
XCryptoBase64::XCryptoBase64() XANADU_NOTHROW
{
}

/// Virtual destructor
XCryptoBase64::~XCryptoBase64() XANADU_NOTHROW
{
}




/// Encoded in BASE64
XByteArray XCryptoBase64::Encode(const void* _Buffer, int64S _Length) XANADU_NOTHROW
{
	return XCryptoBase64::Encode(XByteArray((const char*)_Buffer, _Length));
}

/// Encoded in BASE64
XByteArray XCryptoBase64::Encode(const XByteArray& _Buffer) XANADU_NOTHROW
{
	return _Buffer.ToBase64();
}

/// Decoded in BASE64
XByteArray XCryptoBase64::Decode(const void* _Buffer, int64S _Length) XANADU_NOTHROW
{
	return XCryptoBase64::Decode(XByteArray((const char*)_Buffer, _Length));
}

/// Decoded in BASE64
XByteArray XCryptoBase64::Decode(const XByteArray& _Buffer) XANADU_NOTHROW
{
	return XByteArray::FromBase64(_Buffer);
}
