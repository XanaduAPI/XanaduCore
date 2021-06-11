#ifndef			_XANADU_CORE_LIBRARY_H_
#define			_XANADU_CORE_LIBRARY_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

///  <summary>
///  Implementation of a dynamic loading external library
///  </summary>
class XANADU_CORE_EXPORT XLibrary
{
public:
	// constructor
	XLibrary() noexcept;

	// destructor
	virtual ~XLibrary() noexcept;

public:
	// Open a dynamic XLibrary
	static HANDLE open(const XString& _Dynamic) noexcept;

	// Finds a specified function address from the dynamic library handle
	static void* find(HANDLE _Handle, const NString& _Function) noexcept;

	// Close dynamic XLibrary handle
	static int close(HANDLE _Handle) noexcept;
};

#endif
