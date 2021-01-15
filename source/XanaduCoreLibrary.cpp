//
// Created by Administrator on 2021/1/14.
//

#include <XanaduCore/XanaduCoreLibrary.h>


XLibrary::XLibrary() XANADU_NOTHROW
{
}

XLibrary::~XLibrary() XANADU_NOTHROW
{
}

HANDLE XLibrary::Open(const XString& _Dynamic) XANADU_NOTHROW
{
	return Xanadu::LibraryOpen(_Dynamic.data());
}

void* XLibrary::Find(HANDLE _Handle, const NString& _Function) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Handle, nullptr);
	XANADU_CHECK_RETURN(_Function.size(), nullptr);

	return Xanadu::LibraryFind(_Handle, _Function.data());
}

void XLibrary::Close(HANDLE _Handle) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Handle);

	Xanadu::LibraryClose(_Handle);
}
