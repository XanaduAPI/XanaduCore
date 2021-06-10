#include <XanaduCore/exception.h>


// constructor
Xanadu::exception::exception() noexcept
{
	this->_explain = L"";
}

// constructor
Xanadu::exception::exception(const wchar_t* _Explain) noexcept
{
	this->_explain = _Explain;
}

// constructor
Xanadu::exception::exception(const XString& _Explain) noexcept
{
	this->_explain = _Explain;
}

// constructor
Xanadu::exception::exception(const exception& _Exception) noexcept
{
	this->_explain = _Exception._explain;
}

// destructor
Xanadu::exception::~exception() noexcept
{
}





// Operator overloading =
Xanadu::exception& Xanadu::exception::operator = (const wchar_t* _Explain) noexcept
{
	this->_explain = _Explain;
	return *this;
}

// Operator overloading =
Xanadu::exception& Xanadu::exception::operator = (const XString& _Explain) noexcept
{
	this->_explain = _Explain;
	return *this;
}

// Operator overloading =
Xanadu::exception& Xanadu::exception::operator = (const exception& _Exception) noexcept
{
	this->_explain = _Exception._explain;
	return *this;
}





// Get exception description
const wchar_t* Xanadu::exception::what() const noexcept
{
	return this->_explain.data();
}
