#include <XanaduRuntime/Library.h>
#include <XanaduRuntime/String.h>

XANADU_RUNTIME_EXPORT HANDLE XANADUAPI Xanadu::LoadLibraryA(const char* _LibraryFile) noexcept
{
	XANADU_CHECK_RETURN(_LibraryFile, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return (HANDLE)::LoadLibraryA(_LibraryFile);
#else
	return Xanadu::dlopen(_LibraryFile, RTLD_NOW);
#endif
}

XANADU_RUNTIME_EXPORT HANDLE XANADUAPI Xanadu::LoadLibraryW(const wchar_t* _LibraryFile) noexcept
{
	XANADU_CHECK_RETURN(_LibraryFile, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return (HANDLE)::LoadLibraryW(_LibraryFile);
#else
	auto 		vNLibraryFile = Xanadu::strwton(_LibraryFile);
	auto 		vResult = Xanadu::dlopen(vNLibraryFile, RTLD_NOW);
	Xanadu::strfree(vNLibraryFile);
	return vResult;
#endif
}

XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::GetProcAddress(HANDLE _Handle, const char* _ProcName) noexcept
{
	XANADU_CHECK_RETURN(_Handle, nullptr);
	XANADU_CHECK_RETURN(_ProcName, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return (void*)::GetProcAddress((HMODULE)_Handle, _ProcName);
#else
	return Xanadu::dlsym(_Handle, _ProcName);
#endif
}

XANADU_RUNTIME_EXPORT bool XANADUAPI Xanadu::FreeLibrary(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::FreeLibrary((HMODULE)_Handle) ? true : false;
#else
	return Xanadu::dlclose(_Handle) == 0 ? true : false;
#endif
}

XANADU_RUNTIME_EXPORT HANDLE XANADUAPI Xanadu::dlopen(const char* _LibraryFile, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_LibraryFile, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::LoadLibraryA(_LibraryFile);
#else
	return (HANDLE)::dlopen(_LibraryFile, _Mode);
#endif
}

XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::dlsym(HANDLE _Handle, const char* _ProcName) noexcept
{
	XANADU_CHECK_RETURN(_Handle, nullptr);
	XANADU_CHECK_RETURN(_ProcName, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::GetProcAddress(_Handle, _ProcName);
#else
	return (void*)::dlsym(_Handle, _ProcName);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::dlclose(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::FreeLibrary(_Handle) ? 0 : -1;
#else
	return ::dlclose(_Handle);
#endif
}






// Open a dynamic library
XANADU_RUNTIME_EXPORT HANDLE XANADUAPI Xanadu::LibraryOpen(const wchar_t* _LibraryFile) noexcept
{
	XANADU_CHECK_RETURN(_LibraryFile, nullptr);

	return Xanadu::LoadLibraryW(_LibraryFile);
}

// Finds the function address in the specified dynamic library
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::LibraryFind(HANDLE _Handle, const char* _ProcName) noexcept
{
	XANADU_CHECK_RETURN(_Handle, nullptr);
	XANADU_CHECK_RETURN(_ProcName, nullptr);

	return Xanadu::GetProcAddress(_Handle, _ProcName);
}

// Close a dynamic library
XANADU_RUNTIME_EXPORT bool XANADUAPI Xanadu::LibraryClose(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return Xanadu::FreeLibrary(_Handle);
}
