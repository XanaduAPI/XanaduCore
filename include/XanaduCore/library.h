#ifndef			_XANADU_CORE_LIBRARY_H_
#define			_XANADU_CORE_LIBRARY_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

// Xanadu namespace
namespace Xanadu
{
	///  <summary>
	///  Implementation of a dynamic loading external library
	///  </summary>
	class XANADU_CORE_EXPORT library
	{
	public:
		// constructor
		library() noexcept;

		// destructor
		virtual ~library() noexcept;

	public:
		// Open a dynamic library
		static HANDLE open(const XString& _Dynamic) noexcept;

		// Finds a specified function address from the dynamic library handle
		static void* find(HANDLE _Handle, const NString& _Function) noexcept;

		// Close dynamic library handle
		static int close(HANDLE _Handle) noexcept;
	};
}

#endif
