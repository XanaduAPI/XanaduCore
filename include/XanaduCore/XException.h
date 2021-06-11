#ifndef			_XANADU_CORE_EXCEPTION_H_
#define			_XANADU_CORE_EXCEPTION_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

///  <summary>
///  Exception handling class of Xanadu
///  </summary>
class XANADU_CORE_EXPORT XException
{
private:
	// Exception description
	XString				_explain;

public:
	// constructor
	XException() noexcept;

	// constructor
	explicit XException(const wchar_t* _Explain) noexcept;

	// constructor
	explicit XException(const XString& _Explain) noexcept;

	// constructor
	XException(const XException& _Exception) noexcept;

	// destructor
	virtual ~XException() noexcept;

public:
	// Operator overloading =
	XException& operator = (const wchar_t* _Explain) noexcept;

	// Operator overloading =
	XException& operator = (const XString& _Explain) noexcept;

	// Operator overloading =
	XException& operator = (const XException& _Exception) noexcept;

public:
	// Get exception description
	virtual const wchar_t* what() const noexcept;
};

#endif
