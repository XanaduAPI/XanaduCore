﻿#ifndef			_XANADU_CORE_PROCESS_H_
#define			_XANADU_CORE_PROCESS_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

/// 卸载列表
typedef struct _XANADU_CORE_PROCESS_UNINSTALL
{
	bool					_IsX86;				/// 是否32位
	bool					_IsX64;				/// 是否64位
	XString					_Label;				/// 标签
	XString					_Name;				/// 名称
	XString					_Version;			/// 版本
	XString					_Location;			/// 安装位置
	XString					_Uninstall;			/// 卸载命令行
}XANADU_CORE_PROCESS_UNINSTALL;

/// Process Info
class XANADU_CORE_EXPORT XProcessInfo
{
private:
	int64U				_process_id;
	XString				_process_name;

public:
	XProcessInfo() noexcept;

	XProcessInfo(int64U _ID, const XString& _Name) noexcept;

	virtual ~XProcessInfo() noexcept;

public:
	/// 进程ID
	virtual int64U GetID() const noexcept;

	/// 进程名称
	virtual XString GetName() const noexcept;

public:
	/// 结束进程
	virtual bool Terminate() const noexcept;
};

/// Process
class XANADU_CORE_EXPORT XProcess
{
public:
	XProcess() noexcept;

	virtual ~XProcess() noexcept;

public:
	/// 结束进程
	static bool Terminate(XString _ProcessName) noexcept;

	/// 结束进程
	static bool Terminate(int64U _ProcessID) noexcept;

public:
	/// 当前进程ID
	static int64U ProcessID() noexcept;

public:
	/// 遍历
	static bool Traverse(std::function<bool(const XProcessInfo& _Info)> _Lambda) noexcept;

	/// 进程是否存在
	static bool IsExist(const XString& _ProcessName) noexcept;

	/// 同进程名的数量
	static int32S Number(const XString& _ProcessName) noexcept;

	/// 运行并等待进程
	static int64U Execute(const XString& _Application, const XString& _Param = XString(), const XString& _Directory = XString(), bool _Wait = true, bool _UI = false) noexcept;

	/// 枚举卸载列表
	static bool Program(std::function<void(const XANADU_CORE_PROCESS_UNINSTALL* _Info)> _Lambda) noexcept;
};

#endif /// _XANADU_CORE_PROCESS_H_
