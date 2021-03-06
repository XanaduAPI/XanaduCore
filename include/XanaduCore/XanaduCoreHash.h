#ifndef			_XANADU_CORE_HASH_H_
#define			_XANADU_CORE_HASH_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreByteArray.h>
#include <XanaduCore/XanaduCoreString.h>

class XHashPrivate;

// A public class that evaluates the hash value.
// Contains common algorithm such as MD5, SHA1, SHA256.
class XANADU_CORE_EXPORT XHash
{
public:
	// Enumeration of common algorithms
	enum Algorithm
	{
		MD5 = 0,
		SHA1,
		CRC32,
	};

private:
	// Private structures
	XHashPrivate*				_Info;

public:
	// Structure
	XHash(Algorithm _Algorithm) noexcept;

	// Virtual destructor
	virtual ~XHash() noexcept;

public:
	// Empty data
	virtual void reset() noexcept;

	// Add Data
	virtual void append(const void* _Data, int64U _Length) noexcept;

	// Add Data
	virtual void append(const XByteArray& _Bytes) noexcept;

	// View the results
	virtual XByteArray result() const noexcept;

public:
	// Static method: Calculates the hash value
	static XByteArray hash(const void* _Buffer, int64U _Length, Algorithm _Algorithm) noexcept;

	// Static method: Calculates the hash value
	static XByteArray hash(const XByteArray& _Bytes, Algorithm _Algorithm) noexcept;

	// Static method: Calculates the hash value
	static XByteArray hash(const XString& _File, Algorithm _Algorithm) noexcept;

	// Static method: Gets the result length of the specified algorithm
	static int32S hashLength(Algorithm _Algorithm) noexcept;
};

#endif // _XANADU_CORE_HASH_H_
