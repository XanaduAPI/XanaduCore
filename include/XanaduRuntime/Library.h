#ifndef			__XANADU_RUNTIME_BUILD_SHAREDRARY_H_
#define			__XANADU_RUNTIME_BUILD_SHAREDRARY_H_

#include <XanaduRuntime/Header.h>

namespace Xanadu
{
	XANADU_RUNTIME_EXPORT HANDLE XANADUAPI LoadLibraryA(const char* _LibraryFile) noexcept;

	XANADU_RUNTIME_EXPORT HANDLE XANADUAPI LoadLibraryW(const wchar_t* _LibraryFile) noexcept;

	XANADU_RUNTIME_EXPORT void* XANADUAPI GetProcAddress(HANDLE _Handle, const char* _ProcName) noexcept;

	XANADU_RUNTIME_EXPORT bool XANADUAPI FreeLibrary(HANDLE _Handle) noexcept;

	XANADU_RUNTIME_EXPORT HANDLE XANADUAPI dlopen(const char* _LibraryFile, int _Mode) noexcept;

	XANADU_RUNTIME_EXPORT void* XANADUAPI dlsym(HANDLE _Handle, const char* _ProcName) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI dlclose(HANDLE _Handle) noexcept;

	// <summary>
	// Open a dynamic library
	// </summary>
	// <param name="_LibraryFile">The name of the function</param>
	// <returns>Returns the dynamic library handle, or null on failure</returns>
	XANADU_RUNTIME_EXPORT HANDLE XANADUAPI LibraryOpen(const wchar_t* _LibraryFile) noexcept;

	// <summary>
	// Finds the function address in the specified dynamic library
	// </summary>
	// <param name="_Handle">Dynamic library handle</param>
	// <param name="_ProcName">Full path to the dynamic library</param>
	// <returns>Returns the function address, or null on failure</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI LibraryFind(HANDLE _Handle, const char* _ProcName) noexcept;

	// <summary>
	// Close a dynamic library
	// </summary>
	// <param name="_Handle">Dynamic library handle</param>
	// <returns>Returns the true, or false on failure</returns>
	XANADU_RUNTIME_EXPORT bool XANADUAPI LibraryClose(HANDLE _Handle) noexcept;
};

#endif
