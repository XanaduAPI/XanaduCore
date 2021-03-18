#ifndef			_XANADU_CORE_EXCEPTION_H_
#define			_XANADU_CORE_EXCEPTION_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

// Xanadu Class Exception
class XANADU_CORE_EXPORT XException
{
private:
	// Exception Explain String
	XString				_exception_explain;

public:
	// Overload Initialize
	XException() noexcept;

	// Overload Initialize
	XException(const wchar_t* _Explain) noexcept;

	// Overload Initialize
	XException(const XString& _Explain) noexcept;

	// Overload Initialize
	XException(const XException& _Exception) noexcept;

	// Virtual destructor
	virtual ~XException() noexcept;

public:
	// Overload Operator =
	XException& operator = (const wchar_t* _Explain) noexcept;

	// Overload Operator =
	XException& operator = (const XString& _Explain) noexcept;

	// Overload Operator =
	XException& operator = (const XException& _Exception) noexcept;

public:
	// Get Exception Info
	virtual const wchar_t* what() const noexcept;
};

#endif // _XANADU_CORE_EXCEPTION_H_
