#ifndef			_XANADU_CORE_VARIANT_H_
#define			_XANADU_CORE_VARIANT_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XByteArray.h>
#include <XanaduCore/XString.h>

// Xanadu Class Variant
class XANADU_CORE_EXPORT XVariant
{
public:
	enum Type
	{
		kINVALID = 0,				// Unknown Type
		kBOOLEAN,				// true / false
		kCHAR,					// char
		kUCHAR,					// unsigned char
		kSHORT,					// short
		kUSHORT,				// unsigned short
		kINT,					// int
		kUINT,					// unsigned int
		kLONG,					// long
		kULONG,					// unsigned long
		kLLONG,					// long long
		kULLONG,				// unsigned long long
		kFLOAT,					// float
		kDOUBLE,				// double
		kSTRING,				// XString
		kBYTES,					// XByteArray
	};

private:
	union Data
	{
		bool					_VBool;
		long long				_VInt64S;
		unsigned long long			_VInt64U;
		double 					_VDouble;
		void*					_VObject;
		long long				_VNull;
	}_variant_data;

	Type						_variant_type;

public:
	// constructor
	XVariant() noexcept;

	// constructor
	XVariant(Type _Type) noexcept;

	// constructor
	XVariant(bool _Value) noexcept;

	// constructor
	XVariant(char _Value) noexcept;

	// constructor
	XVariant(unsigned char _Value) noexcept;

	// constructor
	XVariant(short _Value) noexcept;

	// constructor
	XVariant(unsigned short _Value) noexcept;

	// constructor
	XVariant(int _Value) noexcept;

	// constructor
	XVariant(unsigned int _Value) noexcept;

	// constructor
	XVariant(long _Value) noexcept;

	// constructor
	XVariant(unsigned long _Value) noexcept;

	// constructor
	XVariant(long long _Value) noexcept;

	// constructor
	XVariant(unsigned long long _Value) noexcept;

	// constructor
	XVariant(float _Value) noexcept;

	// constructor
	XVariant(double _Value) noexcept;

	// constructor
	XVariant(const wchar_t* _Value) noexcept;

	// constructor
	XVariant(const XString& _Value) noexcept;

	// constructor
	XVariant(const char* _Value) noexcept;

	// constructor
	XVariant(const XByteArray& _Value) noexcept;

	// constructor
	XVariant(const XVariant& _Other) noexcept;

	// constructor
	XVariant(XVariant&& _Other) noexcept;

	// destructor
	virtual ~XVariant() noexcept;

public:
	// Operator overload =
	XVariant& operator = (bool _Value) noexcept;

	// Operator overload =
	XVariant& operator = (char _Value) noexcept;

	// Operator overload =
	XVariant& operator = (unsigned char _Value) noexcept;

	// Operator overload =
	XVariant& operator = (short _Value) noexcept;

	// Operator overload =
	XVariant& operator = (unsigned short _Value) noexcept;

	// Operator overload =
	XVariant& operator = (int _Value) noexcept;

	// Operator overload =
	XVariant& operator = (unsigned int _Value) noexcept;

	// Operator overload =
	XVariant& operator = (long _Value) noexcept;

	// Operator overload =
	XVariant& operator = (unsigned long _Value) noexcept;

	// Operator overload =
	XVariant& operator = (long long _Value) noexcept;

	// Operator overload =
	XVariant& operator = (unsigned long long _Value) noexcept;

	// Operator overload =
	XVariant& operator = (float _Value) noexcept;

	// Operator overload =
	XVariant& operator = (double _Value) noexcept;

	// Operator overload =
	XVariant& operator = (const wchar_t* _Value) noexcept;

	// Operator overload =
	XVariant& operator = (const XString& _Value) noexcept;

	// Operator overload =
	XVariant& operator = (const char* _Value) noexcept;

	// Operator overload =
	XVariant& operator = (const XByteArray& _Value) noexcept;

	// Operator overload =
	XVariant& operator = (const XVariant& _Other) noexcept;

	// Operator overload =
	XVariant& operator = (XVariant&& _Other) noexcept;

private:
	// Data copy
	void _copy(const XVariant& _Other) noexcept;

	// Data released
	void _clear() noexcept;

public:
	// Get the current type
	virtual Type type() const noexcept;

	// Clear current content
	virtual void clear() noexcept;

public:
	// Convert to bool
	virtual bool toBool() const noexcept;

	// Convert to char
	virtual char toChar() const noexcept;

	// Convert to unsigned char
	virtual unsigned char toUChar() const noexcept;

	// Convert to short
	virtual short toShort() const noexcept;

	// Convert to unsigned short
	virtual unsigned short toUShort() const noexcept;

	// Convert to int
	virtual int toInt() const noexcept;

	// Convert to unsigned int
	virtual unsigned int toUInt() const noexcept;

	// Convert to long
	virtual long toLong() const noexcept;

	// Convert to unsigned long
	virtual unsigned long toULong() const noexcept;

	// Convert to long long
	virtual long long toLLong() const noexcept;

	// Convert to unsigned long long
	virtual unsigned long long toULLong() const noexcept;

	// Convert to float
	virtual float toFloat() const noexcept;

	// Convert to double
	virtual double toDouble() const noexcept;

	// Convert to XString
	virtual XString toString() const noexcept;

	// Convert to XByteArray
	virtual XByteArray toBytes() const noexcept;
};

#endif
