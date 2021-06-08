#include <XanaduRuntime/Mmap.h>

#ifndef FILE_MAP_EXECUTE
#define FILE_MAP_EXECUTE    0x0020
#endif // FILE_MAP_EXECUTE

#ifdef XANADU_COMPILE_MSVC
static int __map_mman_error(const DWORD _Error, const int _Default)
{
	XANADU_UNPARAMETER(_Default);
	if(_Error == 0)
	{
		return 0;
	}
	return _Error;
}

static DWORD __map_mmap_prot_page(const int _Prot)
{
	auto		vProtect = DWORD(0);
	if(_Prot == PROT_NONE)
	{
		return vProtect;
	}
	if((_Prot & PROT_EXEC) != 0)
	{
		vProtect = ((_Prot & PROT_WRITE) != 0) ? PAGE_EXECUTE_READWRITE : PAGE_EXECUTE_READ;
	}
	else
	{
		vProtect = ((_Prot & PROT_WRITE) != 0) ? PAGE_READWRITE : PAGE_READONLY;
	}
	return vProtect;
}

static DWORD __map_mmap_prot_file(const int _Prot)
{
	auto		vDesiredAccess = DWORD(0);
	if(_Prot == PROT_NONE)
	{
		return vDesiredAccess;
	}
	if((_Prot & PROT_READ) != 0)
	{
		vDesiredAccess |= FILE_MAP_READ;
	}
	if((_Prot & PROT_WRITE) != 0)
	{
		vDesiredAccess |= FILE_MAP_WRITE;
	}
	if((_Prot & PROT_EXEC) != 0)
	{
		vDesiredAccess |= FILE_MAP_EXECUTE;
	}
	return vDesiredAccess;
}
#endif // XANADU_COMPILE_MSVC



XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::mmap(void* _Addr, size_t _Length, int _Prot, int _Flags, int _Fildes, off_t _Off) noexcept
{
#ifdef XANADU_COMPILE_MSVC
	XANADU_UNPARAMETER(_Addr);

	auto		vFileMap = static_cast<HANDLE>(INVALID_HANDLE_VALUE);
	auto		vHandle = static_cast<HANDLE>(INVALID_HANDLE_VALUE);
	auto		vMap = MAP_FAILED;
	auto		vFileOffsetLow = static_cast<DWORD>(_Off);
	auto		vFileOffsetHigh = static_cast<DWORD>(0);
	auto		vProtect = __map_mmap_prot_page(_Prot);
	auto		vDesiredAccess = __map_mmap_prot_file(_Prot);
	auto		vMaxSize = _Off + (off_t)_Length;
	auto		vMaxSizeLow = static_cast<DWORD>(vMaxSize);
	auto		vMaxSizeHigh = static_cast<DWORD>(0);

	errno = 0;

	if(_Length == 0 || (_Flags & MAP_FIXED) != 0/* Unsupported flag combinations */ || _Prot == PROT_EXEC/* Usupported protection combinations */)
	{
		errno = EINVAL;
		return MAP_FAILED;
	}

	vHandle = ((_Flags & MAP_ANONYMOUS) == 0) ? (HANDLE)_get_osfhandle(_Fildes) : INVALID_HANDLE_VALUE;

	if((_Flags & MAP_ANONYMOUS) == 0 && vHandle == INVALID_HANDLE_VALUE)
	{
		errno = EBADF;
		return MAP_FAILED;
	}

	vFileMap = CreateFileMappingA(vHandle, nullptr, vProtect, vMaxSizeHigh, vMaxSizeLow, nullptr);

	if(vFileMap == nullptr)
	{
		errno = __map_mman_error(GetLastError(), EPERM);
		return MAP_FAILED;
	}

	vMap = MapViewOfFile(vFileMap, vDesiredAccess, vFileOffsetHigh, vFileOffsetLow, _Length);

	CloseHandle(vFileMap);

	if(vMap == nullptr)
	{
		errno = __map_mman_error(GetLastError(), EPERM);
		return MAP_FAILED;
	}
	return vMap;
#else
	return ::mmap(_Addr, _Length, _Prot, _Flags, _Fildes, _Off);
#endif // XANADU_COMPILE_MSVC
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::munmap(void* _Addr, size_t _Length) noexcept
{
#ifdef XANADU_COMPILE_MSVC
	XANADU_UNPARAMETER(_Length);

	if(UnmapViewOfFile(_Addr))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::munmap(_Addr, _Length);
#endif // XANADU_COMPILE_MSVC
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::mprotect(void* _Addr, size_t _Length, int _Prot) noexcept
{
#ifdef XANADU_COMPILE_MSVC
	auto		vNewProtect = __map_mmap_prot_page(_Prot);
	auto		vOldProtect = DWORD(0);

	if(VirtualProtect(_Addr, _Length, vNewProtect, &vOldProtect))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::mprotect(_Addr, _Length, _Prot);
#endif // XANADU_COMPILE_MSVC
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::msync(void* _Addr, size_t _Length, int _Flags) noexcept
{
#ifdef XANADU_COMPILE_MSVC
	XANADU_UNPARAMETER(_Flags);

	if(FlushViewOfFile(_Addr, _Length))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::msync(_Addr, _Length, _Flags);
#endif // XANADU_COMPILE_MSVC
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::mlock(const void* _Addr, size_t _Length) noexcept
{
#ifdef XANADU_COMPILE_MSVC
	if(VirtualLock((LPVOID)_Addr, _Length))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::mlock(_Addr, _Length);
#endif // XANADU_COMPILE_MSVC
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::munlock(const void* _Addr, size_t _Length) noexcept
{
#ifdef XANADU_COMPILE_MSVC
	if(VirtualUnlock((LPVOID)_Addr, _Length))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::munlock(_Addr, _Length);
#endif // XANADU_COMPILE_MSVC
}
