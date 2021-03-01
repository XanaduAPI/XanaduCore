#ifndef			_XANADU_CORE_HASH_H_
#define			_XANADU_CORE_HASH_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreByteArray.h>
#include <XanaduCore/XanaduCoreString.h>

class XCryptoHashPrivate;

/// A public class that evaluates the hash value.
/// Contains common algorithm such as MD5, SHA1, SHA256.
class XANADU_CORE_EXPORT XCryptoHash
{
public:
	/// Enumeration of common algorithms
	enum Algorithm
	{
		MD5 = 0,
		SHA1,
		CRC32,
	};

private:
	/// Private structures
	XCryptoHashPrivate*			_Info;

public:
	/// Structure
	XCryptoHash(Algorithm _Algorithm) XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XCryptoHash() XANADU_NOTHROW;

public:
	/// Empty data
	virtual void reset() XANADU_NOTHROW;

	/// Add Data
	virtual void append(const void* _Data, int64U _Length) XANADU_NOTHROW;

	/// Add Data
	virtual void append(const XByteArray& _Bytes) XANADU_NOTHROW;

	/// View the results
	virtual XByteArray result() const XANADU_NOTHROW;

public:
	/// Static method: Calculates the hash value
	static XByteArray hash(const XByteArray& _Bytes, Algorithm _Algorithm) XANADU_NOTHROW;

	/// Static method: Calculates the hash value
	static XByteArray hash(const XString& _File, Algorithm _Algorithm) XANADU_NOTHROW;

	/// Static method: Gets the result length of the specified algorithm
	static int32S hashLength(Algorithm _Algorithm) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_HASH_H_
