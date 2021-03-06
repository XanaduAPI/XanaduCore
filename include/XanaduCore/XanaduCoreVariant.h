#ifndef			_XANADU_CORE_VARIANT_H_
#define			_XANADU_CORE_VARIANT_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreByteArray.h>
#include <XanaduCore/XanaduCoreString.h>

// Xanadu Class Variant
class XANADU_CORE_EXPORT XVariant
{
public:
	enum Type
	{
		EINVALID = 0,			// Unknown Type
		EBOOL,				// true / false
		EINT8S,				// char
		EINT8U,				// unsigned char
		EINT16S,			// short
		EINT16U,			// unsigned short
		EINT32S,			// int
		EINT32U,			// unsigned int
		EINT64S,			// long long
		EINT64U,			// unsigned long long
		EFLOAT,				// float
		EDOUBLE,			// double
		ESTRING,			// XString
		EBYTEARRAY,			// XByteArray
	};

private:
	union Data
	{
		bool		_VBool;
		int8S		_VInt8S;
		int8U		_VInt8U;
		int16S		_VInt16S;
		int16U		_VInt16U;
		int32S		_VInt32S;
		int32U		_VInt32U;
		int64S		_VInt64S;
		int64U		_VInt64U;
		float 		_VFloat;
		double 		_VDouble;
		void*		_VObject;
		int64S		_VNull;
	}_variant_data;

	Type			_variant_type;

public:
	// Structure
	XVariant() noexcept;

	// Overloading structure
	XVariant(Type _Type) noexcept;

	// Overloading structure
	XVariant(const XVariant& _Other) noexcept;

	// Overloading structure
	XVariant(bool _Value) noexcept;

	// Overloading structure
	XVariant(int8S _Value) noexcept;

	// Overloading structure
	XVariant(int8U _Value) noexcept;

	// Overloading structure
	XVariant(int16S _Value) noexcept;

	// Overloading structure
	XVariant(int16U _Value) noexcept;

	// Overloading structure
	XVariant(int32S _Value) noexcept;

	// Overloading structure
	XVariant(int32U _Value) noexcept;

	// Overloading structure
	XVariant(int64S _Value) noexcept;

	// Overloading structure
	XVariant(int64U _Value) noexcept;

	// Overloading structure
	XVariant(float _Value) noexcept;

	// Overloading structure
	XVariant(double _Value) noexcept;

	// Overloading structure
	XVariant(const wchar_t* _Value) noexcept;

	// Overloading structure
	XVariant(const XString& _Value) noexcept;

	// Overloading structure
	XVariant(const char* _Value) noexcept;

	// Overloading structure
	XVariant(const XByteArray& _Value) noexcept;

	// Overloading structure
	XVariant(XVariant&& _Other) noexcept;

	// Virtual destructor
	virtual ~XVariant() noexcept;

public:
	// Overload Operator =
	virtual XVariant& operator = (const XVariant& _Other) noexcept;

	// Overload Operator =
	virtual XVariant& operator = (XVariant&& _Other) noexcept;

private:
	// Data to construct
	virtual void Initialize(const XVariant& _Other) noexcept;

	// Data released
	virtual void Release() noexcept;

public:
	// Get the current type
	virtual Type type() const noexcept;

	// Clear current content
	virtual void clear() noexcept;

public:
	// Convert to bool
	virtual bool toBool() const noexcept;

	// Convert to int8S
	virtual int8S toInt8S() const noexcept;

	// Convert to int8U
	virtual int8U toInt8U() const noexcept;

	// Convert to int16S
	virtual int16S toInt16S() const noexcept;

	// Convert to int16U
	virtual int16U toInt16U() const noexcept;

	// Convert to int32S
	virtual int32S toInt32S() const noexcept;

	// Convert to int32U
	virtual int32U toInt32U() const noexcept;

	// Convert to int64S
	virtual int64S toInt64S() const noexcept;

	// Convert to int64U
	virtual int64U toInt64U() const noexcept;

	// Convert to float
	virtual float toFloat() const noexcept;

	// Convert to double
	virtual double toDouble() const noexcept;

	// Convert to XString
	virtual XString toString() const noexcept;

	// Convert to XByteArray
	virtual XByteArray toByteArray() const noexcept;
};

#endif // _XANADU_CORE_VARIANT_H_
