﻿#include <XanaduCore/XanaduCoreProcessInfo.h>
#include <XanaduCore/XanaduCoreProcess.h>

// 进程信息私有块
class XProcessInfoPrivate
{
public:
	int64U				_ProcessID;
	XString				_ProcessName;

public:
	XProcessInfoPrivate()
	{
		this->_ProcessID = 0ULL;
		this->_ProcessName = L"";
	};

	static void copy(XProcessInfoPrivate* _Target, const XProcessInfoPrivate* _Source)
	{
		_Target->_ProcessID = _Source->_ProcessID;
		_Target->_ProcessName = _Source->_ProcessName;
	};
};

XProcessInfo::XProcessInfo() noexcept
{
	this->_private_info = XANADU_NEW XProcessInfoPrivate();
}

XProcessInfo::XProcessInfo(int64U _ProcessID) noexcept
{
	this->_private_info = XANADU_NEW XProcessInfoPrivate();
	this->_private_info->_ProcessID = _ProcessID;
	this->_private_info->_ProcessName = L"";
}

XProcessInfo::XProcessInfo(int64U _ProcessID, const XString& _ProcessName) noexcept
{
	this->_private_info = XANADU_NEW XProcessInfoPrivate();
	this->_private_info->_ProcessID = _ProcessID;
	this->_private_info->_ProcessName = _ProcessName;
}

XProcessInfo::XProcessInfo(const XProcessInfo& _Other) noexcept
{
	this->_private_info = XANADU_NEW XProcessInfoPrivate();
	XProcessInfoPrivate::copy(this->_private_info, _Other._private_info);
}

XProcessInfo::~XProcessInfo() noexcept
{
	XANADU_DELETE_PTR(this->_private_info);
}




XProcessInfo& XProcessInfo::operator = (const XProcessInfo& _Other) noexcept
{
	XProcessInfoPrivate::copy(this->_private_info, _Other._private_info);
	return *this;
}




// 获取进程ID
int64U XProcessInfo::getProcessID() const noexcept
{
	return this->_private_info->_ProcessID;
}

// 获取进程名称
XString XProcessInfo::getProcessName() const noexcept
{
	return this->_private_info->_ProcessName;
}

// 结束进程
bool XProcessInfo::terminate() const noexcept
{
	return XProcess::terminate(this->getProcessID());
}
