#include <XanaduCore/XanaduCoreVariant.h>


/// Structure
XVariant::XVariant() XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(Type _Type) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(const XVariant& _Other) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(bool _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int8S _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int8U _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int16S _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int16U _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int32S _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int32U _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int64S _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(int64U _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(float _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(double _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(const std::map<XString, XVariant>& _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(const std::list<XVariant>& _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(const XString& _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(const XByteArray& _Value) XANADU_NOTHROW
{
}

/// Overloading structure
XVariant::XVariant(XVariant&& _Other) XANADU_NOTHROW
{
}

/// Virtual destructor
XVariant::~XVariant() XANADU_NOTHROW
{
}



/// Overload Operator =
XVariant& XVariant::operator = (const XVariant& _Other) XANADU_NOTHROW
{
	return *this;
}

/// Overload Operator =
XVariant& XVariant::operator = (XVariant&& _Other) XANADU_NOTHROW
{
	return *this;
}




/// Get the current type
XVariant::Type XVariant::type() const XANADU_NOTHROW
{
	return XVariant::EINVALID;
}

/// Clear current content
void XVariant::clear() const XANADU_NOTHROW
{
}
