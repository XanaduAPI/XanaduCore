#ifndef			_XANADU_CORE_PROCESS_H_
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
	XProcessInfo() XANADU_NOTHROW;

	XProcessInfo(int64U _ID, const XString& _Name) XANADU_NOTHROW;

	virtual ~XProcessInfo() XANADU_NOTHROW;

public:
	/// 进程ID
	virtual int64U GetID() const XANADU_NOTHROW;

	/// 进程名称
	virtual XString GetName() const XANADU_NOTHROW;

public:
	/// 结束进程
	virtual bool Terminate() const XANADU_NOTHROW;
};

/// Process
class XANADU_CORE_EXPORT XProcess
{
public:
	XProcess() XANADU_NOTHROW;

	virtual ~XProcess() XANADU_NOTHROW;

public:
	/// 结束进程
	static bool Terminate(XString _ProcessName) XANADU_NOTHROW;

	/// 结束进程
	static bool Terminate(int64U _ProcessID) XANADU_NOTHROW;

public:
	/// 当前进程ID
	static int64U ProcessID() XANADU_NOTHROW;

public:
	/// 遍历
	static bool Traverse(std::function<bool(const XProcessInfo& _Info)> _Lambda) XANADU_NOTHROW;

	/// 进程是否存在
	static bool IsExist(const XString& _ProcessName) XANADU_NOTHROW;

	/// 同进程名的数量
	static int32S Number(const XString& _ProcessName) XANADU_NOTHROW;

	/// 运行并等待进程
	static int64U Execute(const XString& _Application, const XString& _Param = XString(), const XString& _Directory = XString(), bool _Wait = true, bool _UI = false) XANADU_NOTHROW;

	/// 枚举卸载列表
	static bool Program(std::function<void(const XANADU_CORE_PROCESS_UNINSTALL* _Info)> _Lambda) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_PROCESS_H_
