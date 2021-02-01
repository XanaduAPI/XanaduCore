#ifndef			_XANADU_CORE_LIBRARY_H_
#define			_XANADU_CORE_LIBRARY_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

//Xanadu Class Library
class XANADU_CORE_EXPORT XLibrary
{
public:
	XLibrary() XANADU_NOTHROW;

	virtual ~XLibrary() XANADU_NOTHROW;

public:
	static HANDLE Open(const XString& _Dynamic) XANADU_NOTHROW;

	static void* Find(HANDLE _Handle, const NString& _Function) XANADU_NOTHROW;

	static void Close(HANDLE _Handle) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_LIBRARY_H_
