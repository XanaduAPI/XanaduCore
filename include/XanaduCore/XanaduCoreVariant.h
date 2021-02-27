/*
 * Variant Class for the Xanadu series
 * */

#ifndef			_XANADU_CORE_VARIANT_H_
#define			_XANADU_CORE_VARIANT_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreByteArray.h>
#include <XanaduCore/XanaduCoreString.h>

/// Xanadu Class Variant
class XANADU_CORE_EXPORT XVariant
{
public:
	enum Type
	{
		EINVALID = 0,			/// Unknown Type
		EBOOL,				/// true / false
		EINT8S,				/// char
		EINT8U,				/// unsigned char
		EINT16S,			/// short
		EINT16U,			/// unsigned short
		EINT32S,			/// int
		EINT32U,			/// unsigned int
		EINT64S,			/// long long
		EINT64U,			/// unsigned long long
		EFLOAT,				/// float
		EDOUBLE,			/// double
		ESTRING,			/// XString
		EBYTEARRAY,			/// XByteArray
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
	/// Structure
	XVariant() XANADU_NOTHROW;

	/// Overloading structure
	XVariant(Type _Type) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(const XVariant& _Other) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(bool _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int8S _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int8U _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int16S _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int16U _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int32S _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int32U _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int64S _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(int64U _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(float _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(double _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(const wchar_t* _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(const XString& _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(const char* _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(const XByteArray& _Value) XANADU_NOTHROW;

	/// Overloading structure
	XVariant(XVariant&& _Other) XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XVariant() XANADU_NOTHROW;

public:
	/// Overload Operator =
	virtual XVariant& operator = (const XVariant& _Other) XANADU_NOTHROW;

	/// Overload Operator =
	virtual XVariant& operator = (XVariant&& _Other) XANADU_NOTHROW;

private:
	/// Data to construct
	virtual void Initialize(const XVariant& _Other) XANADU_NOTHROW;

	/// Data released
	virtual void Release() XANADU_NOTHROW;

public:
	/// Get the current type
	virtual Type type() const XANADU_NOTHROW;

	/// Clear current content
	virtual void clear() XANADU_NOTHROW;

public:
	/// Convert to bool
	virtual bool toBool() const XANADU_NOTHROW;

	/// Convert to int8S
	virtual int8S toInt8S() const XANADU_NOTHROW;

	/// Convert to int8U
	virtual int8U toInt8U() const XANADU_NOTHROW;

	/// Convert to int16S
	virtual int16S toInt16S() const XANADU_NOTHROW;

	/// Convert to int16U
	virtual int16U toInt16U() const XANADU_NOTHROW;

	/// Convert to int32S
	virtual int32S toInt32S() const XANADU_NOTHROW;

	/// Convert to int32U
	virtual int32U toInt32U() const XANADU_NOTHROW;

	/// Convert to int64S
	virtual int64S toInt64S() const XANADU_NOTHROW;

	/// Convert to int64U
	virtual int64U toInt64U() const XANADU_NOTHROW;

	/// Convert to float
	virtual float toFloat() const XANADU_NOTHROW;

	/// Convert to double
	virtual double toDouble() const XANADU_NOTHROW;

	/// Convert to XString
	virtual XString toString() const XANADU_NOTHROW;

	/// Convert to XByteArray
	virtual XByteArray toByteArray() const XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_VARIANT_H_
