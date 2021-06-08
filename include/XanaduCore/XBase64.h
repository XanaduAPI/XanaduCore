#ifndef			_XANADU_CORE_BASE64_H_
#define			_XANADU_CORE_BASE64_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XByteArray.h>

// A Base64 codec library.
class XANADU_CORE_EXPORT XBase64
{
public:
	// Structure
	XBase64() noexcept;

	// Virtual destructor
	virtual ~XBase64() noexcept;

public:
	// Encoded in BASE64
	static XByteArray encode(const void* _Memory, int64U _Length) noexcept;

	// Encoded in BASE64
	static XByteArray encode(const XByteArray& _Bytes) noexcept;

	// Decoded in BASE64
	static XByteArray decode(const void* _Memory, int64U _Length) noexcept;

	// Decoded in BASE64
	static XByteArray decode(const XByteArray& _Bytes) noexcept;
};

#endif // _XANADU_CORE_BASE64_H_
