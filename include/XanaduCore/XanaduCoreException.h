//
// Created by Administrator on 2021/1/12.
//

/*
 * This file is an exception declaration for the Xanadu family
 * */

#ifndef			_XANADU_CORE_EXCEPTION_H_
#define			_XANADU_CORE_EXCEPTION_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

/// Xanadu Class Exception
class XANADU_CORE_EXPORT XException
{
private:
	/// Exception Explain String
	XString				_exception_explain;

public:
	/// Overload Initialize
	XException() XANADU_NOTHROW;

	/// Overload Initialize
	XException(const wchar_t* _Explain) XANADU_NOTHROW;

	/// Overload Initialize
	XException(const XString& _Explain) XANADU_NOTHROW;

	/// Overload Initialize
	XException(const XException& _Exception) XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XException() XANADU_NOTHROW;

public:
	/// Overload Operator =
	XException& operator = (const wchar_t* _Explain) XANADU_NOTHROW;

	/// Overload Operator =
	XException& operator = (const XString& _Explain) XANADU_NOTHROW;

	/// Overload Operator =
	XException& operator = (const XException& _Exception) XANADU_NOTHROW;

public:
	/// Get Exception Info
	virtual const wchar_t* what() const XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_EXCEPTION_H_
