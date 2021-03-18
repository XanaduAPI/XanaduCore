#ifndef			_XANADU_CORE_SETTING_H_
#define			_XANADU_CORE_SETTING_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>
#include <XanaduCore/XVariant.h>

// Xanadu Setting Private
class XSettingPrivate;

// Xanadu Class Setting
class XANADU_CORE_EXPORT XSetting
{
private:
	XSettingPrivate*		_Info;

public:
	// Overload Initialize
	XSetting() noexcept;

	// Overload Initialize
	XSetting(const XSetting& _Setting) noexcept;

	// Virtual destructor
	virtual ~XSetting() noexcept;

public:
	// Overload Operator =
	XSetting& operator = (const XSetting& _Setting) noexcept;

private:
	virtual void _clear() noexcept;

	virtual void _copy(const XSetting& _Setting) noexcept;

	virtual XSettingPrivate* _format(const XByteArray& _Bytes) const noexcept;

	virtual void _append(XSettingPrivate* _Node) noexcept;

	virtual XSettingPrivate* _find(const XString& _Section, const XString& _Key) const noexcept;

	virtual void _remove(XSettingPrivate* _Node) noexcept;

	virtual XSettingPrivate* _section_end(const XString& _Section) noexcept;

private:
	virtual XByteArray _section(const XSettingPrivate* _Node) const noexcept;

	virtual XByteArray _left(const XSettingPrivate* _Node) const noexcept;

	virtual XByteArray _right(const XSettingPrivate* _Node) const noexcept;

public:
	///加载
	virtual bool load(const XString& _File) noexcept;

	// 保存
	virtual bool save(const XString& _File) const noexcept;

public:
	// 增
	virtual bool append(const XString& _Section, const XString& _Key, const XVariant& _Value) noexcept;

	// 删
	virtual bool remove(const XString& _Section, const XString& _Key) noexcept;

	// 改
	virtual bool modify(const XString& _Section, const XString& _Key, const XVariant& _Value) noexcept;

	// 查
	virtual XVariant select(const XString& _Section, const XString& _Key, const XVariant& _Default = XVariant()) const noexcept;

public:
	// 写入
	static bool write(const XString& _File, const XString& _Section, const XString& _Key, const XVariant& _Value) noexcept;

	// 读取
	static XVariant read(const XString& _File, const XString& _Section, const XString& _Key, const XVariant& _Default = XVariant()) noexcept;
};

#endif // _XANADU_CORE_SETTING_H_
