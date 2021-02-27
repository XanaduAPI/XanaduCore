#include <XanaduCore/XanaduCoreVariant.h>


/// The XVariant object copies the macro function
#define XANADU_VARIANT_OBJECT_CREATE(_Type, _Value)	{ \
								this->_variant_data._VObject = XANADU_NEW _Type(); \
								if(this->_variant_data._VObject) \
								{ \
									*(static_cast<_Type*>(this->_variant_data._VObject)) = _Value; \
								} \
							}

#define XANADU_VARIANT_OBJECT_COPY(_Type)		{ \
								this->_variant_data._VObject = XANADU_NEW _Type(); \
								if(this->_variant_data._VObject) \
								{ \
									*(static_cast<_Type*>(this->_variant_data._VObject)) = *(static_cast<_Type*>(_Other._variant_data._VObject)); \
								} \
							}

#define XANADU_VARIANT_OBJECT_RELEASE(_Type)		{ \
								if(this->_variant_data._VObject)        \
								{                                       \
									delete static_cast<_Type*>(this->_variant_data._VObject); \
									this->_variant_data._VObject = nullptr;\
								}                                       \
							}



/// Structure
XVariant::XVariant() XANADU_NOTHROW
{
	this->_variant_type = XVariant::EINVALID;
	this->_variant_data._VNull = 0LL;
}

/// Overloading structure
XVariant::XVariant(Type _Type) XANADU_NOTHROW
{
	this->_variant_type = _Type;
	this->_variant_data._VNull = 0LL;
}

/// Overloading structure
XVariant::XVariant(const XVariant& _Other) XANADU_NOTHROW
{
	this->Initialize(_Other);
}

/// Overloading structure
XVariant::XVariant(bool _Value) XANADU_NOTHROW
{
	this->_variant_type = EBOOL;
	this->_variant_data._VBool = _Value;
}

/// Overloading structure
XVariant::XVariant(int8S _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT8S;
	this->_variant_data._VInt8S = _Value;
}

/// Overloading structure
XVariant::XVariant(int8U _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT8U;
	this->_variant_data._VInt8U = _Value;
}

/// Overloading structure
XVariant::XVariant(int16S _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT16S;
	this->_variant_data._VInt16S = _Value;
}

/// Overloading structure
XVariant::XVariant(int16U _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT16U;
	this->_variant_data._VInt16U = _Value;
}

/// Overloading structure
XVariant::XVariant(int32S _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT32S;
	this->_variant_data._VInt32S = _Value;
}

/// Overloading structure
XVariant::XVariant(int32U _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT32U;
	this->_variant_data._VInt32U = _Value;
}

/// Overloading structure
XVariant::XVariant(int64S _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT64S;
	this->_variant_data._VInt64S = _Value;
}

/// Overloading structure
XVariant::XVariant(int64U _Value) XANADU_NOTHROW
{
	this->_variant_type = EINT64U;
	this->_variant_data._VInt64U = _Value;
}

/// Overloading structure
XVariant::XVariant(float _Value) XANADU_NOTHROW
{
	this->_variant_type = EFLOAT;
	this->_variant_data._VFloat = _Value;
}

/// Overloading structure
XVariant::XVariant(double _Value) XANADU_NOTHROW
{
	this->_variant_type = EDOUBLE;
	this->_variant_data._VDouble = _Value;
}

/// Overloading structure
XVariant::XVariant(const wchar_t* _Value) XANADU_NOTHROW
{
	this->_variant_type = ESTRING;
	XANADU_VARIANT_OBJECT_CREATE(XString, _Value ? _Value : L"");
}

/// Overloading structure
XVariant::XVariant(const XString& _Value) XANADU_NOTHROW
{
	this->_variant_type = ESTRING;
	XANADU_VARIANT_OBJECT_CREATE(XString, _Value);
}

/// Overloading structure
XVariant::XVariant(const char* _Value) XANADU_NOTHROW
{
	this->_variant_type = EBYTEARRAY;
	XANADU_VARIANT_OBJECT_CREATE(XByteArray, _Value ? _Value : "");
}

/// Overloading structure
XVariant::XVariant(const XByteArray& _Value) XANADU_NOTHROW
{
	this->_variant_type = EBYTEARRAY;
	XANADU_VARIANT_OBJECT_CREATE(XByteArray, _Value);
}

/// Overloading structure
XVariant::XVariant(XVariant&& _Other) XANADU_NOTHROW
{
	this->_variant_type = _Other._variant_type;
	this->_variant_data = _Other._variant_data;

	_Other._variant_type = EINVALID;
	_Other._variant_data._VObject = nullptr;
}

/// Virtual destructor
XVariant::~XVariant() XANADU_NOTHROW
{
	this->Release();
}



/// Overload Operator =
XVariant& XVariant::operator = (const XVariant& _Other) XANADU_NOTHROW
{
	this->Initialize(_Other);
	return *this;
}

/// Overload Operator =
XVariant& XVariant::operator = (XVariant&& _Other) XANADU_NOTHROW
{
	this->_variant_type = _Other._variant_type;
	this->_variant_data = _Other._variant_data;

	_Other._variant_type = EINVALID;
	_Other._variant_data._VObject = nullptr;
	return *this;
}





/// Data to construct
void XVariant::Initialize(const XVariant& _Other) XANADU_NOTHROW
{
	this->Release();

	this->_variant_type = _Other._variant_type;
	this->_variant_data._VNull = 0LL;
	switch (this->_variant_type)
	{
		case EBOOL:
		case EINT8S:
		case EINT8U:
		case EINT16S:
		case EINT16U:
		case EINT32S:
		case EINT32U:
		case EINT64S:
		case EINT64U:
		case EFLOAT:
		case EDOUBLE:
			this->_variant_data = _Other._variant_data;
			break;
		case ESTRING:
			XANADU_VARIANT_OBJECT_COPY(XString);
			break;
		case EBYTEARRAY:
			XANADU_VARIANT_OBJECT_COPY(XByteArray);
			break;
		default:
			this->_variant_data._VNull = 0LL;
			break;
	};
}

/// Data released
void XVariant::Release() XANADU_NOTHROW
{
	switch (this->_variant_type)
	{
		case EBOOL:
		case EINT8S:
		case EINT8U:
		case EINT16S:
		case EINT16U:
		case EINT32S:
		case EINT32U:
		case EINT64S:
		case EINT64U:
		case EFLOAT:
		case EDOUBLE:
			this->_variant_data._VNull = 0LL;
			break;
		case ESTRING:
			XANADU_VARIANT_OBJECT_RELEASE(XString);
			break;
		case EBYTEARRAY:
			XANADU_VARIANT_OBJECT_RELEASE(XByteArray);
			break;
		default:
			this->_variant_data._VNull = 0LL;
			break;
	};
	this->_variant_type = EINVALID;
	this->_variant_data._VNull = 0LL;
}




/// Get the current type
XVariant::Type XVariant::type() const XANADU_NOTHROW
{
	return this->_variant_type;
}

/// Clear current content
void XVariant::clear() XANADU_NOTHROW
{
	this->Release();
}





/// Convert to bool
bool XVariant::toBool() const XANADU_NOTHROW
{
	switch (this->_variant_type)
	{
		case EBOOL:
			return this->_variant_data._VBool;
		case EINT8S:
			return this->_variant_data._VInt8S;
		case EINT8U:
			return this->_variant_data._VInt8U;
		case EINT16S:
			return this->_variant_data._VInt16S;
		case EINT16U:
			return this->_variant_data._VInt16U;
		case EINT32S:
			return this->_variant_data._VInt32S;
		case EINT32U:
			return this->_variant_data._VInt32U;
		case EINT64S:
			return this->_variant_data._VInt64S;
		case EINT64U:
			return this->_variant_data._VInt64U;
		case EFLOAT:
			return this->_variant_data._VFloat;
		case EDOUBLE:
			return this->_variant_data._VDouble;
		case ESTRING:
			return (0 == this->toString().compare(L"1")) ? true : false;
		case EBYTEARRAY:
			return (0 == this->toByteArray().compare("1")) ? true : false;
		default:
			return this->_variant_data._VNull;
	};
}

/// Convert to int8S
int8S XVariant::toInt8S() const XANADU_NOTHROW
{
	return static_cast<int8S>(this->toInt64S());
}

/// Convert to int8U
int8U XVariant::toInt8U() const XANADU_NOTHROW
{
	return static_cast<int8U>(this->toInt64S());
}

/// Convert to int16S
int16S XVariant::toInt16S() const XANADU_NOTHROW
{
	return static_cast<int16S>(this->toInt64S());
}

/// Convert to int16U
int16U XVariant::toInt16U() const XANADU_NOTHROW
{
	return static_cast<int16U>(this->toInt64S());
}

/// Convert to int32S
int32S XVariant::toInt32S() const XANADU_NOTHROW
{
	return static_cast<int32S>(this->toInt64S());
}

/// Convert to int32U
int32U XVariant::toInt32U() const XANADU_NOTHROW
{
	return static_cast<int32U>(this->toInt64S());
}

/// Convert to int64S
int64S XVariant::toInt64S() const XANADU_NOTHROW
{
	switch (this->_variant_type)
	{
		case EBOOL:
			return this->_variant_data._VBool ? 1LL : 0LL;
		case EINT8S:
			return this->_variant_data._VInt8S;
		case EINT8U:
			return this->_variant_data._VInt8U;
		case EINT16S:
			return this->_variant_data._VInt16S;
		case EINT16U:
			return this->_variant_data._VInt16U;
		case EINT32S:
			return this->_variant_data._VInt32S;
		case EINT32U:
			return this->_variant_data._VInt32U;
		case EINT64S:
			return this->_variant_data._VInt64S;
		case EINT64U:
			return this->_variant_data._VInt64U;
		case EFLOAT:
			return static_cast<int64S>(this->_variant_data._VFloat);
		case EDOUBLE:
			return static_cast<int64S>(this->_variant_data._VDouble);
		case ESTRING:
			return Xanadu::wtoll(this->toString().data());
		case EBYTEARRAY:
			return Xanadu::atoll(this->toByteArray().data());
		default:
			return this->_variant_data._VNull;
	};
}

/// Convert to int64U
int64U XVariant::toInt64U() const XANADU_NOTHROW
{
	switch (this->_variant_type)
	{
		case EBOOL:
			return this->_variant_data._VBool ? 1ULL : 0ULL;
		case EINT8S:
			return this->_variant_data._VInt8S;
		case EINT8U:
			return this->_variant_data._VInt8U;
		case EINT16S:
			return this->_variant_data._VInt16S;
		case EINT16U:
			return this->_variant_data._VInt16U;
		case EINT32S:
			return this->_variant_data._VInt32S;
		case EINT32U:
			return this->_variant_data._VInt32U;
		case EINT64S:
			return this->_variant_data._VInt64S;
		case EINT64U:
			return this->_variant_data._VInt64U;
		case EFLOAT:
			return static_cast<int64U>(this->_variant_data._VFloat);
		case EDOUBLE:
			return static_cast<int64U>(this->_variant_data._VDouble);
		case ESTRING:
			return Xanadu::wtoll(this->toString().data());
		case EBYTEARRAY:
			return Xanadu::atoll(this->toByteArray().data());
		default:
			return this->_variant_data._VNull;
	};
}

/// Convert to float
float XVariant::toFloat() const XANADU_NOTHROW
{
	return static_cast<float>(this->toDouble());
}

/// Convert to double
double XVariant::toDouble() const XANADU_NOTHROW
{
	switch (this->_variant_type)
	{
		case EBOOL:
			return 0.0f;
		case EINT8S:
			return this->_variant_data._VInt8S;
		case EINT8U:
			return this->_variant_data._VInt8U;
		case EINT16S:
			return this->_variant_data._VInt16S;
		case EINT16U:
			return this->_variant_data._VInt16U;
		case EINT32S:
			return this->_variant_data._VInt32S;
		case EINT32U:
			return this->_variant_data._VInt32U;
		case EINT64S:
			return static_cast<double>(this->_variant_data._VInt64S);
		case EINT64U:
			return static_cast<double>(this->_variant_data._VInt64U);
		case EFLOAT:
			return this->_variant_data._VFloat;
		case EDOUBLE:
			return this->_variant_data._VDouble;
		case ESTRING:
			return Xanadu::wtof(this->toString().data());
		case EBYTEARRAY:
			return Xanadu::atof(this->toByteArray().data());
		default:
			return static_cast<double>(this->_variant_data._VNull);
	};
}

/// Convert to XString
XString XVariant::toString() const XANADU_NOTHROW
{
	switch (this->_variant_type)
	{
		case EBOOL:
			return XString::format(L"%ls", this->_variant_data._VBool ? L"1" : L"0");
		case EINT8S:
			return XString::format(L"%d", this->_variant_data._VInt8S);
		case EINT8U:
			return XString::format(L"%u", this->_variant_data._VInt8U);
		case EINT16S:
			return XString::format(L"%d", this->_variant_data._VInt16S);
		case EINT16U:
			return XString::format(L"%u", this->_variant_data._VInt16U);
		case EINT32S:
			return XString::format(L"%d", this->_variant_data._VInt32S);
		case EINT32U:
			return XString::format(L"%u", this->_variant_data._VInt32U);
		case EINT64S:
			return XString::format(L"%lld", this->_variant_data._VInt64S);
		case EINT64U:
			return XString::format(L"%llu", this->_variant_data._VInt64U);
		case EFLOAT:
			return XString::format(L"%f", this->_variant_data._VFloat);
		case EDOUBLE:
			return XString::format(L"%f", this->_variant_data._VDouble);
		case ESTRING:
			return *(static_cast<XString*>(this->_variant_data._VObject));
		case EBYTEARRAY:
			return XString::fromBytes(this->toByteArray());
		default:
			return L"";
	};
}

/// Convert to XByteArray
XByteArray XVariant::toByteArray() const XANADU_NOTHROW
{
	switch (this->_variant_type)
	{
		case EBOOL:
		case EINT8S:
		case EINT8U:
		case EINT16S:
		case EINT16U:
		case EINT32S:
		case EINT32U:
		case EINT64S:
		case EINT64U:
		case EFLOAT:
		case EDOUBLE:
		case ESTRING:
			return this->toString().toBytes();
		case EBYTEARRAY:
			return *(static_cast<XByteArray*>(this->_variant_data._VObject));
		default:
			return XByteArray();
	};
}
