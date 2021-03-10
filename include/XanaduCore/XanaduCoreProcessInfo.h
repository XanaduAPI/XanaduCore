#ifndef			_XANADU_CORE_PROCESS_INFO_H_
#define			_XANADU_CORE_PROCESS_INFO_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

// 进程信息私有块
class XProcessInfoPrivate;

// 进程信息
class XANADU_CORE_EXPORT XProcessInfo
{
private:
	XProcessInfoPrivate*			_private_info;

public:
	XProcessInfo() noexcept;

	XProcessInfo(int64U _ProcessID) noexcept;

	XProcessInfo(int64U _ProcessID, const XString& _ProcessName) noexcept;

	XProcessInfo(const XProcessInfo& _Other) noexcept;

	virtual ~XProcessInfo() noexcept;

public:
	virtual XProcessInfo& operator = (const XProcessInfo& _Other) noexcept;

public:
	// 获取进程ID
	virtual int64U getProcessID() const noexcept;

	// 获取进程名称
	virtual XString getProcessName() const noexcept;

public:
	// 结束进程
	virtual bool terminate() const noexcept;
};

#endif // _XANADU_CORE_PROCESS_INFO_H_
