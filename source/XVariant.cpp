#include <XanaduCore/XVariant.h>


// Structure
XVariant::XVariant() noexcept
{
	this->_variant_type = XVariant::kINVALID;
	this->_variant_data._VNull = 0LL;
}

// constructor
XVariant::XVariant(Type _Type) noexcept
{
	this->_variant_type = _Type;
	this->_variant_data._VNull = 0LL;
}

// constructor
XVariant::XVariant(bool _Value) noexcept
{
	this->_variant_type = kBOOLEAN;
	this->_variant_data._VBool = _Value;
}

// constructor
XVariant::XVariant(char _Value) noexcept
{
	this->_variant_type = kCHAR;
	this->_variant_data._VInt64S = _Value;
}

// constructor
XVariant::XVariant(unsigned char _Value) noexcept
{
	this->_variant_type = kUCHAR;
	this->_variant_data._VInt64U = _Value;
}

// constructor
XVariant::XVariant(short _Value) noexcept
{
	this->_variant_type = kSHORT;
	this->_variant_data._VInt64S = _Value;
}

// constructor
XVariant::XVariant(unsigned short _Value) noexcept
{
	this->_variant_type = kUSHORT;
	this->_variant_data._VInt64U = _Value;
}

// constructor
XVariant::XVariant(int _Value) noexcept
{
	this->_variant_type = kINT;
	this->_variant_data._VInt64S = _Value;
}

// constructor
XVariant::XVariant(unsigned int _Value) noexcept
{
	this->_variant_type = kUINT;
	this->_variant_data._VInt64U = _Value;
}

// constructor
XVariant::XVariant(long _Value) noexcept
{
	this->_variant_type = kLONG;
	this->_variant_data._VInt64S = _Value;
}

// constructor
XVariant::XVariant(unsigned long _Value) noexcept
{
	this->_variant_type = kULONG;
	this->_variant_data._VInt64U = _Value;
}

// constructor
XVariant::XVariant(long long _Value) noexcept
{
	this->_variant_type = kLLONG;
	this->_variant_data._VInt64S = _Value;
}

// constructor
XVariant::XVariant(unsigned long long _Value) noexcept
{
	this->_variant_type = kULLONG;
	this->_variant_data._VInt64U = _Value;
}

// constructor
XVariant::XVariant(float _Value) noexcept
{
	this->_variant_type = kFLOAT;
	this->_variant_data._VDouble = _Value;
}

// constructor
XVariant::XVariant(double _Value) noexcept
{
	this->_variant_type = kDOUBLE;
	this->_variant_data._VDouble = _Value;
}

// constructor
XVariant::XVariant(const wchar_t* _Value) noexcept
{
	this->_variant_type = kSTRING;
	this->_variant_data._VObject = XANADU_NEW XString(_Value);
}

// constructor
XVariant::XVariant(const XString& _Value) noexcept
{
	this->_variant_type = kSTRING;
	this->_variant_data._VObject = XANADU_NEW XString(_Value);
}

// constructor
XVariant::XVariant(const char* _Value) noexcept
{
	this->_variant_type = kBYTES;
	this->_variant_data._VObject = XANADU_NEW XByteArray(_Value);
}

// constructor
XVariant::XVariant(const XByteArray& _Value) noexcept
{
	this->_variant_type = kBYTES;
	this->_variant_data._VObject = XANADU_NEW XByteArray(_Value);
}

// constructor
XVariant::XVariant(const XVariant& _Other) noexcept
{
	this->_copy(_Other);
}

// constructor
XVariant::XVariant(XVariant&& _Other) noexcept
{
	this->_variant_type = _Other._variant_type;
	this->_variant_data = _Other._variant_data;

	_Other._variant_type = kINVALID;
	_Other._variant_data._VObject = nullptr;
}

// Virtual destructor
XVariant::~XVariant() noexcept
{
	this->_clear();
}





// Operator overload =
XVariant& XVariant::operator = (bool _Value) noexcept
{
	this->_clear();
	this->_variant_type = kBOOLEAN;
	this->_variant_data._VBool = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (char _Value) noexcept
{
	this->_clear();
	this->_variant_type = kCHAR;
	this->_variant_data._VInt64S = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (unsigned char _Value) noexcept
{
	this->_clear();
	this->_variant_type = kUCHAR;
	this->_variant_data._VInt64U = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (short _Value) noexcept
{
	this->_clear();
	this->_variant_type = kSHORT;
	this->_variant_data._VInt64S = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (unsigned short _Value) noexcept
{
	this->_clear();
	this->_variant_type = kUSHORT;
	this->_variant_data._VInt64U = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (int _Value) noexcept
{
	this->_clear();
	this->_variant_type = kINT;
	this->_variant_data._VInt64S = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (unsigned int _Value) noexcept
{
	this->_clear();
	this->_variant_type = kUINT;
	this->_variant_data._VInt64U = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (long _Value) noexcept
{
	this->_clear();
	this->_variant_type = kLONG;
	this->_variant_data._VInt64S = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (unsigned long _Value) noexcept
{
	this->_clear();
	this->_variant_type = kULONG;
	this->_variant_data._VInt64U = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (long long _Value) noexcept
{
	this->_clear();
	this->_variant_type = kLLONG;
	this->_variant_data._VInt64S = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (unsigned long long _Value) noexcept
{
	this->_clear();
	this->_variant_type = kULLONG;
	this->_variant_data._VInt64U = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (float _Value) noexcept
{
	this->_clear();
	this->_variant_type = kFLOAT;
	this->_variant_data._VDouble = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (double _Value) noexcept
{
	this->_clear();
	this->_variant_type = kDOUBLE;
	this->_variant_data._VDouble = _Value;
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (const wchar_t* _Value) noexcept
{
	this->_clear();
	this->_variant_type = kSTRING;
	this->_variant_data._VObject = XANADU_NEW XString(_Value);
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (const XString& _Value) noexcept
{
	this->_clear();
	this->_variant_type = kSTRING;
	this->_variant_data._VObject = XANADU_NEW XString(_Value);
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (const char* _Value) noexcept
{
	this->_clear();
	this->_variant_type = kBYTES;
	this->_variant_data._VObject = XANADU_NEW XByteArray(_Value);
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (const XByteArray& _Value) noexcept
{
	this->_clear();
	this->_variant_type = kBYTES;
	this->_variant_data._VObject = XANADU_NEW XByteArray(_Value);
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (const XVariant& _Other) noexcept
{
	this->_copy(_Other);
	return *this;
}

// Operator overload =
XVariant& XVariant::operator = (XVariant&& _Other) noexcept
{
	this->_variant_type = _Other._variant_type;
	this->_variant_data = _Other._variant_data;

	_Other._variant_type = kINVALID;
	_Other._variant_data._VObject = nullptr;
	return *this;
}





// Data copy
void XVariant::_copy(const XVariant& _Other) noexcept
{
	this->_clear();

	this->_variant_type = _Other._variant_type;
	this->_variant_data._VNull = 0LL;
	switch (this->_variant_type)
	{
		case kBOOLEAN:
		case kCHAR:
		case kUCHAR:
		case kSHORT:
		case kUSHORT:
		case kINT:
		case kUINT:
		case kLONG:
		case kULONG:
		case kLLONG:
		case kULLONG:
		case kFLOAT:
		case kDOUBLE:
			this->_variant_data = _Other._variant_data;
			break;
		case kSTRING:
		{
			this->_variant_data._VObject = XANADU_NEW XString();
			if(this->_variant_data._VObject)
			{
				*(static_cast<XString*>(this->_variant_data._VObject)) = *(static_cast<XString*>(_Other._variant_data._VObject));
			}
		}
			break;
		case kBYTES:
		{
			this->_variant_data._VObject = XANADU_NEW XByteArray();
			if(this->_variant_data._VObject)
			{
				*(static_cast<XByteArray*>(this->_variant_data._VObject)) = *(static_cast<XByteArray*>(_Other._variant_data._VObject));
			}
		}
			break;
		default:
			this->_variant_data._VNull = 0LL;
			break;
	};
}

// Data released
void XVariant::_clear() noexcept
{
	switch (this->_variant_type)
	{
		case kBOOLEAN:
		case kCHAR:
		case kUCHAR:
		case kSHORT:
		case kUSHORT:
		case kINT:
		case kUINT:
		case kLLONG:
		case kULLONG:
		case kFLOAT:
		case kDOUBLE:
			this->_variant_data._VNull = 0LL;
			break;
		case kSTRING:
		{
			auto		vString = static_cast<XString*>(this->_variant_data._VObject);
			if(vString)
			{
				XANADU_DELETE_PTR(vString);
				this->_variant_data._VObject = nullptr;
			}
		}
			break;
		case kBYTES:
		{
			auto		vBytes = static_cast<XByteArray*>(this->_variant_data._VObject);
			if(vBytes)
			{
				XANADU_DELETE_PTR(vBytes);
				this->_variant_data._VObject = nullptr;
			}
		}
			break;
		default:
			this->_variant_data._VNull = 0LL;
			break;
	};
	this->_variant_type = kINVALID;
	this->_variant_data._VNull = 0LL;
}




// Get the current type
XVariant::Type XVariant::type() const noexcept
{
	return this->_variant_type;
}

// Clear current content
void XVariant::clear() noexcept
{
	this->_clear();
}





// Convert to bool
bool XVariant::toBool() const noexcept
{
	switch (this->_variant_type)
	{
		case kBOOLEAN:
			return this->_variant_data._VBool;
		case kCHAR:
		case kUCHAR:
		case kSHORT:
		case kUSHORT:
		case kINT:
		case kUINT:
		case kLONG:
		case kULONG:
		case kLLONG:
		case kULLONG:
			return this->_variant_data._VInt64U;
		case kFLOAT:
		case kDOUBLE:
			return this->_variant_data._VDouble == 0.0f;
		case kSTRING:
			return 0 == this->toString().compare(L"1");
		case kBYTES:
			return 0 == this->toBytes().compare("1");
		default:
			return this->_variant_data._VNull;
	};
}

// Convert to char
char XVariant::toChar() const noexcept
{
	return static_cast<char>(this->toLLong());
}

// Convert to unsigned char
unsigned char XVariant::toUChar() const noexcept
{
	return static_cast<unsigned char>(this->toULLong());
}

// Convert to short
short XVariant::toShort() const noexcept
{
	return static_cast<short>(this->toLLong());
}

// Convert to unsigned short
unsigned short XVariant::toUShort() const noexcept
{
	return static_cast<unsigned short>(this->toULLong());
}

// Convert to int
int XVariant::toInt() const noexcept
{
	return static_cast<int>(this->toLLong());
}

// Convert to unsigned int
unsigned int XVariant::toUInt() const noexcept
{
	return static_cast<unsigned int>(this->toULLong());
}

// Convert to long
long XVariant::toLong() const noexcept
{
	return static_cast<long>(this->toLLong());
}

// Convert to unsigned long
unsigned long XVariant::toULong() const noexcept
{
	return static_cast<unsigned long>(this->toULLong());
}

// Convert to long long
long long XVariant::toLLong() const noexcept
{
	switch (this->_variant_type)
	{
		case kBOOLEAN:
			return this->_variant_data._VBool ? 1LL : 0LL;
		case kCHAR:
		case kSHORT:
		case kINT:
		case kLONG:
		case kLLONG:
			return this->_variant_data._VInt64S;
		case kUCHAR:
		case kUSHORT:
		case kUINT:
		case kULONG:
		case kULLONG:
			return static_cast<long long>(this->_variant_data._VInt64U);
		case kFLOAT:
		case kDOUBLE:
			return static_cast<long long>(this->_variant_data._VDouble);
		case kSTRING:
			return Xanadu::wtoll(this->toString().data());
		case kBYTES:
			return Xanadu::atoll(this->toBytes().data());
		default:
			return this->_variant_data._VNull;
	};
}

// Convert to unsigned long long
unsigned long long XVariant::toULLong() const noexcept
{
	switch (this->_variant_type)
	{
		case kBOOLEAN:
			return this->_variant_data._VBool ? 1ULL : 0ULL;
		case kCHAR:
		case kSHORT:
		case kINT:
		case kLONG:
		case kLLONG:
			return static_cast<unsigned long long>(this->_variant_data._VInt64S);
		case kUCHAR:
		case kUSHORT:
		case kUINT:
		case kULONG:
		case kULLONG:
			return this->_variant_data._VInt64U;
		case kFLOAT:
		case kDOUBLE:
			return static_cast<unsigned long long>(this->_variant_data._VDouble);
		case kSTRING:
			return Xanadu::wtoll(this->toString().data());
		case kBYTES:
			return Xanadu::atoll(this->toBytes().data());
		default:
			return this->_variant_data._VNull;
	};
}

// Convert to float
float XVariant::toFloat() const noexcept
{
	return static_cast<float>(this->toDouble());
}

// Convert to double
double XVariant::toDouble() const noexcept
{
	switch (this->_variant_type)
	{
		case kBOOLEAN:
			return 0.0f;
		case kCHAR:
		case kSHORT:
		case kINT:
		case kLONG:
		case kLLONG:
			return static_cast<double>(this->_variant_data._VInt64S);
		case kUCHAR:
		case kUSHORT:
		case kUINT:
		case kULONG:
		case kULLONG:
			return static_cast<double>(this->_variant_data._VInt64U);
		case kFLOAT:
		case kDOUBLE:
			return this->_variant_data._VDouble;
		case kSTRING:
			return Xanadu::wtof(this->toString().data());
		case kBYTES:
			return Xanadu::atof(this->toBytes().data());
		default:
			return static_cast<double>(this->_variant_data._VNull);
	};
}

// Convert to XString
XString XVariant::toString() const noexcept
{
	switch (this->_variant_type)
	{
		case kBOOLEAN:
			return this->_variant_data._VBool ? L"1" : L"0";
		case kCHAR:
		case kSHORT:
		case kINT:
		case kLONG:
		case kLLONG:
			return XString::number(this->_variant_data._VInt64S);
		case kUCHAR:
		case kUSHORT:
		case kUINT:
		case kULONG:
		case kULLONG:
			return XString::number(this->_variant_data._VInt64U);
		case kFLOAT:
		case kDOUBLE:
			return XString::number(this->_variant_data._VDouble);
		case kSTRING:
			return *(static_cast<XString*>(this->_variant_data._VObject));
		case kBYTES:
			return XString::fromBytes(this->toBytes());
		default:
			return L"";
	};
}

// Convert to XByteArray
XByteArray XVariant::toBytes() const noexcept
{
	switch (this->_variant_type)
	{
		case kBOOLEAN:
		case kCHAR:
		case kUCHAR:
		case kSHORT:
		case kUSHORT:
		case kINT:
		case kUINT:
		case kLLONG:
		case kULLONG:
		case kFLOAT:
		case kDOUBLE:
		case kSTRING:
			return this->toString().toBytes();
		case kBYTES:
			return *(static_cast<XByteArray*>(this->_variant_data._VObject));
		default:
			return XByteArray();
	};
}
