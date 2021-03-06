#ifndef			_XANADU_CORE_HASH_CRC32_H_
#define			_XANADU_CORE_HASH_CRC32_H_

#include <XanaduCore/XanaduCoreHeader.h>

// CRC32 context
typedef struct _XANADU_CORE_CRC32_CONTEXT
{
	int32U			hash;
}XANADU_CORE_CRC32_CONTEXT;

namespace Xanadu
{
	// CRC32 initialization
	XANADU_CORE_EXPORT void XANADUAPI CRC32_Init(XANADU_CORE_CRC32_CONTEXT* _Context) noexcept;

	// CRC32 updates the data
	XANADU_CORE_EXPORT void XANADUAPI CRC32_Update(XANADU_CORE_CRC32_CONTEXT* _Context, const void* _Data, int64U _Size) noexcept;

	// CRC32 retrieves the results
	XANADU_CORE_EXPORT void XANADUAPI CRC32_Final(unsigned char* _Result, XANADU_CORE_CRC32_CONTEXT* _Context) noexcept;
};

#endif // _XANADU_CORE_HASH_CRC32_H_
