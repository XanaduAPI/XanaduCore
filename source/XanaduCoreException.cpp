#include <XanaduCore/XanaduCoreException.h>


/// Overload Initialize
XException::XException() XANADU_NOTHROW
{
	this->_exception_explain = L"";
}

/// Overload Initialize
XException::XException(const wchar_t* _Explain) XANADU_NOTHROW
{
	this->_exception_explain = _Explain;
}

/// Overload Initialize
XException::XException(const XString& _Explain) XANADU_NOTHROW
{
	this->_exception_explain = _Explain;
}

/// Overload Initialize
XException::XException(const XException& _Exception) XANADU_NOTHROW
{
	this->_exception_explain = _Exception._exception_explain;
}

/// Virtual destructor
XException::~XException() XANADU_NOTHROW
{
}



/// Overload Operator =
XException& XException::operator = (const wchar_t* _Explain) XANADU_NOTHROW
{
	this->_exception_explain = _Explain;
	return *this;
}

/// Overload Operator =
XException& XException::operator = (const XString& _Explain) XANADU_NOTHROW
{
	this->_exception_explain = _Explain;
	return *this;
}

/// Overload Operator =
XException& XException::operator=(const XException& _Exception) XANADU_NOTHROW
{
	this->_exception_explain = _Exception._exception_explain;
	return *this;
}




/// Get Exception Info
const wchar_t* XException::what() const XANADU_NOTHROW
{
	return this->_exception_explain.size() ? this->_exception_explain.data() : L"Xanadu Unknown Exception";
}
