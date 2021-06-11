#include <XanaduCore/XException.h>


// constructor
XException::XException() noexcept
{
	this->_explain = L"";
}

// constructor
XException::XException(const wchar_t* _Explain) noexcept
{
	this->_explain = _Explain;
}

// constructor
XException::XException(const XString& _Explain) noexcept
{
	this->_explain = _Explain;
}

// constructor
XException::XException(const XException& _Exception) noexcept
{
	this->_explain = _Exception._explain;
}

// destructor
XException::~XException() noexcept
{
}





// Operator overloading =
XException& XException::operator = (const wchar_t* _Explain) noexcept
{
	this->_explain = _Explain;
	return *this;
}

// Operator overloading =
XException& XException::operator = (const XString& _Explain) noexcept
{
	this->_explain = _Explain;
	return *this;
}

// Operator overloading =
XException& XException::operator = (const XException& _Exception) noexcept
{
	this->_explain = _Exception._explain;
	return *this;
}





// Get exception description
const wchar_t* XException::what() const noexcept
{
	return this->_explain.data();
}
