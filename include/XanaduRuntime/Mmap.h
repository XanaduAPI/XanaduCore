#ifndef			_XANADU_RUNTIME_MMAP_H_
#define			_XANADU_RUNTIME_MMAP_H_

#include <XanaduRuntime/Header.h>

// XANADU Runtime mman
namespace Xanadu
{
#ifdef XANADU_COMPILE_MSVC

#define PROT_NONE       0
#define PROT_READ       1
#define PROT_WRITE      2
#define PROT_EXEC       4

#define MAP_FILE        0
#define MAP_SHARED      1
#define MAP_PRIVATE     2
#define MAP_TYPE        0xf
#define MAP_FIXED       0x10
#define MAP_ANONYMOUS   0x20
#define MAP_ANON        MAP_ANONYMOUS

#define MAP_FAILED      ((void *)-1)

	/* Flags for msync. */
#define MS_ASYNC        1
#define MS_SYNC         2
#define MS_INVALIDATE   4

#endif

	XANADU_RUNTIME_EXPORT void* XANADUAPI mmap(void* _Addr, size_t _Length, int _Prot, int _Flags, int _Fildes, off_t _Off) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI munmap(void* _Addr, size_t _Length) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI mprotect(void* _Addr, size_t _Length, int _Prot) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI msync(void* _Addr, size_t _Length, int _Flags) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI mlock(const void* _Addr, size_t _Length) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI munlock(const void* _Addr, size_t _Length) noexcept;
};

#endif
