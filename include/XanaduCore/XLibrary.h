#ifndef			__XANADU_CORE_BUILD_SHAREDRARY_H_
#define			__XANADU_CORE_BUILD_SHAREDRARY_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

// Xanadu Class Library
class XANADU_CORE_EXPORT XLibrary
{
public:
	XLibrary() noexcept;

	virtual ~XLibrary() noexcept;

public:
	static HANDLE open(const XString& _Dynamic) noexcept;

	static void* find(HANDLE _Handle, const NString& _Function) noexcept;

	static void close(HANDLE _Handle) noexcept;
};

#endif // __XANADU_CORE_BUILD_SHAREDRARY_H_
