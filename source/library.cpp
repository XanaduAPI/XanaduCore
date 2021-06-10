#include <XanaduCore/library.h>


// constructor
Xanadu::library::library() noexcept
{
}

// destructor
Xanadu::library::~library() noexcept
{
}





// Open a dynamic library
HANDLE Xanadu::library::open(const XString& _Dynamic) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return (HANDLE)::LoadLibraryW(_Dynamic.data());
#else
	auto		vDynamicU = _Dynamic.toUString();
	return (HANDLE)::dlopen(vDynamicU.data(), RTLD_NOW);
#endif
}

// Finds a specified function address from the dynamic library handle
void* Xanadu::library::find(HANDLE _Handle, const NString& _Function) noexcept
{
	if(_Handle == nullptr && _Function.empty())
	{
		return nullptr;
	}
#if defined(_XANADU_SYSTEM_WINDOWS)
	return Xanadu::GetProcAddress(_Handle, _Function.data());
#else
	return ::dlsym(_Handle, _Function.data());
#endif
}

// Close dynamic library handle
int Xanadu::library::close(HANDLE _Handle) noexcept
{
	if(_Handle == nullptr)
	{
		return -1;
	}
#if defined(_XANADU_SYSTEM_WINDOWS)
	return Xanadu::FreeLibrary(_Handle) ? 0 : -1;
#else
	return ::dlclose(_Handle);
#endif
}
