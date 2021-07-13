﻿#ifndef			_XANADU_CORE_PROCESS_H_
#define			_XANADU_CORE_PROCESS_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>
#include <XanaduCore/XProcessInfo.h>

// 卸载列表
typedef struct _XANADU_CORE_PROCESS_UNINSTALL
{
	bool					_IsX86;				// 是否32位
	bool					_IsX64;				// 是否64位
	XString					_Label;				// 标签
	XString					_Name;				// 名称
	XString					_Version;			// 版本
	XString					_Location;			// 安装位置
	XString					_Uninstall;			// 卸载命令行
}XANADU_CORE_PROCESS_UNINSTALL;

// Process
class XANADU_CORE_EXPORT XProcess
{
public:
	XProcess() noexcept;

	virtual ~XProcess() noexcept;

public:
	// Kills the process by the specified name
	static bool kill(const XString& _ProcessName) noexcept;

	// Kill the process with the specified process ID
	static bool kill(long long _ProcessID) noexcept;

public:
	// Gets the current process ID
	static int64U currentProcessID() noexcept;

public:
	// Traverses the list of currently running processes
	static bool traverse(std::function<bool(const XProcessInfo& _Info)> _Lambda) noexcept;

public:
	// Does the specified process name exist
	static bool isExist(const XString& _ProcessName) noexcept;

	// How many instances of the specified process name
	static int64U number(const XString& _ProcessName) noexcept;

public:
	// 运行并等待进程
	static int64U execute(const XString& _Application, const XString& _Param = XString(), const XString& _Directory = XString(), bool _Wait = true, bool _UI = false) noexcept;

public:
	// 枚举卸载列表
	static bool program(std::function<void(const XANADU_CORE_PROCESS_UNINSTALL* _Info)> _Lambda) noexcept;
};

#endif
