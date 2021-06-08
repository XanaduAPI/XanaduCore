#include <XanaduCore/XLibrary.h>


XLibrary::XLibrary() noexcept
{
}

XLibrary::~XLibrary() noexcept
{
}

HANDLE XLibrary::open(const XString& _Dynamic) noexcept
{
	return Xanadu::LibraryOpen(_Dynamic.data());
}

void* XLibrary::find(HANDLE _Handle, const NString& _Function) noexcept
{
	XANADU_CHECK_RETURN(_Handle, nullptr);
	XANADU_CHECK_RETURN(_Function.size(), nullptr);

	return Xanadu::LibraryFind(_Handle, _Function.data());
}

void XLibrary::close(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle);

	Xanadu::LibraryClose(_Handle);
}
