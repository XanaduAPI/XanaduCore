#ifndef			_XANADU_CORE_PROCESS_H_
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
	// 结束进程
	static bool terminate(const XString& _ProcessName) noexcept;

	// 结束进程
	static bool terminate(int64U _ProcessID) noexcept;

public:
	// 当前进程ID
	static int64U currentProcessID() noexcept;

public:
	// 遍历
	static bool traverse(std::function<bool(const XProcessInfo& _Info)> _Lambda) noexcept;

	// 进程是否存在
	static bool isExist(const XString& _ProcessName) noexcept;

	// 同进程名的数量
	static int64U number(const XString& _ProcessName) noexcept;

	// 运行并等待进程
	static int64U execute(const XString& _Application, const XString& _Param = XString(), const XString& _Directory = XString(), bool _Wait = true, bool _UI = false) noexcept;

	// 枚举卸载列表
	static bool program(std::function<void(const XANADU_CORE_PROCESS_UNINSTALL* _Info)> _Lambda) noexcept;
};

#endif // _XANADU_CORE_PROCESS_H_
