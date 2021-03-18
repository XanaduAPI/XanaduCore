#ifndef			_XANADU_CORE_LIBRARY_H_
#define			_XANADU_CORE_LIBRARY_H_

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

#endif // _XANADU_CORE_LIBRARY_H_
