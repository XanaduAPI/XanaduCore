#ifndef			_XANADU_CORE_BASE64_H_
#define			_XANADU_CORE_BASE64_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreByteArray.h>

/// A Base64 codec library.
class XANADU_CORE_EXPORT XCryptoBase64
{
public:
	/// Structure
	XCryptoBase64() XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XCryptoBase64() XANADU_NOTHROW;

public:
	/// Encoded in BASE64
	static XByteArray Encode(const void* _Memory, int64U _Length) XANADU_NOTHROW;

	/// Encoded in BASE64
	static XByteArray Encode(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// Decoded in BASE64
	static XByteArray Decode(const void* _Memory, int64U _Length) XANADU_NOTHROW;

	/// Decoded in BASE64
	static XByteArray Decode(const XByteArray& _Bytes) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_BASE64_H_
