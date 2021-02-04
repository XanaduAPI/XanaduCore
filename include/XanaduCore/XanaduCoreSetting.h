#ifndef			_XANADU_CORE_SETTING_H_
#define			_XANADU_CORE_SETTING_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>
#include <XanaduCore/XanaduCoreVariant.h>

/// Xanadu Setting Private
class XSettingPrivate;

/// Xanadu Class Setting
class XANADU_CORE_EXPORT XSetting
{
private:
	XSettingPrivate*		_Info;

public:
	/// Overload Initialize
	XSetting() XANADU_NOTHROW;

	/// Overload Initialize
	XSetting(const XSetting& _Setting) XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XSetting() XANADU_NOTHROW;

public:
	/// Overload Operator =
	XSetting& operator = (const XSetting& _Setting) XANADU_NOTHROW;

private:
	virtual void _clear() XANADU_NOTHROW;

	virtual void _copy(const XSetting& _Setting) XANADU_NOTHROW;

	virtual XSettingPrivate* _format(const XByteArray& _Bytes) const XANADU_NOTHROW;

	virtual void _append(XSettingPrivate* _Node) XANADU_NOTHROW;

	virtual XSettingPrivate* _find(const XString& _Section, const XString& _Key) const XANADU_NOTHROW;

	virtual void _remove(XSettingPrivate* _Node) XANADU_NOTHROW;

	virtual XSettingPrivate* _section_end(const XString& _Section) XANADU_NOTHROW;

private:
	virtual XByteArray _section(const XSettingPrivate* _Node) const XANADU_NOTHROW;

	virtual XByteArray _left(const XSettingPrivate* _Node) const XANADU_NOTHROW;

	virtual XByteArray _right(const XSettingPrivate* _Node) const XANADU_NOTHROW;

public:
	///加载
	virtual bool Load(const XString& _File) XANADU_NOTHROW;

	/// 保存
	virtual bool Save(const XString& _File) const XANADU_NOTHROW;

public:
	/// 增
	virtual bool Append(const XString& _Section, const XString& _Key, const XVariant& _Value) XANADU_NOTHROW;

	/// 删
	virtual bool Remove(const XString& _Section, const XString& _Key) XANADU_NOTHROW;

	/// 改
	virtual bool Modify(const XString& _Section, const XString& _Key, const XVariant& _Value) XANADU_NOTHROW;

	/// 查
	virtual XVariant Select(const XString& _Section, const XString& _Key, const XVariant& _Default = XVariant()) const XANADU_NOTHROW;

public:
	/// 写入
	static bool Write(const XString& _File, const XString& _Section, const XString& _Key, const XVariant& _Value) XANADU_NOTHROW;

	/// 读取
	static XVariant Read(const XString& _File, const XString& _Section, const XString& _Key, const XVariant& _Default = XVariant()) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_SETTING_H_
