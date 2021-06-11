#include <XanaduCore/XProcess.h>
#include <XanaduCore/XFileSystem.h>
#include <XanaduCore/XNative.h>
#include <XanaduCore/XSystem.h>
#if defined(_XANADU_SYSTEM_WINDOWS)
#include <tlhelp32.h>
#endif
#if defined(_XANADU_SYSTEM_MACOS)
#include <libproc.h>
#endif




// 获取子项值
XString RegisterKeyValue(HKEY _Key, XString _Guid, XString _Name)
{
	auto		vKeyValue = XString(L"");
#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vLocalKey = static_cast<HKEY>(nullptr);
	auto		vResult = RegOpenKeyExW(_Key, _Guid.data(), NULL, KEY_READ, &vLocalKey);
	if(vResult == ERROR_SUCCESS)
	{
		wchar_t		vBuffer[MAX_PATH] = { 0 };
		auto		vLength = DWORD(MAX_PATH);
		auto		vType = DWORD(REG_SZ);
		Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * MAX_PATH);
		auto		vQuery = RegQueryValueExW(vLocalKey, _Name.data(), NULL, &vType, (byte*)vBuffer, &vLength);
		if(vQuery == ERROR_SUCCESS)
		{
			vKeyValue = vBuffer;
		}
	}
#endif
	return vKeyValue;
}

XProcess::XProcess() noexcept
{
}

XProcess::~XProcess() noexcept
{
}

// 结束进程
bool XProcess::terminate(const XString& _ProcessName) noexcept
{
	XANADU_CHECK_RETURN(_ProcessName.exist(), false);

	auto			vResult = true;
	XProcess::traverse([&](const XProcessInfo& _ProcessInfo)->bool
	{
		if(_ProcessInfo.getProcessName() == _ProcessName)
		{
			vResult = _ProcessInfo.terminate();
		}
		return true;
	});
	return vResult;
}

// 结束进程
bool XProcess::terminate(int64U _ProcessID) noexcept
{
	auto		vResult = true;
#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, static_cast<DWORD>(_ProcessID));
	if(vProcess != nullptr)
	{
		vResult = ::TerminateProcess(vProcess, 0);
		::CloseHandle(vProcess);
	}
#endif
#if defined(_XANADU_SYSTEM_LINUX)
	vResult = (Xanadu::kill(_ProcessID, 9) == 0) ? true : false;
#endif
#if defined(_XANADU_SYSTEM_MACOS)
	vResult = (Xanadu::kill(_ProcessID, 9) == 0) ? true : false;
#endif
	return vResult;
}

// 当前进程ID
int64U XProcess::currentProcessID() noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return static_cast<int64U>(GetCurrentProcessId());
#else
	return static_cast<int64U>(getpid());
#endif
}

// 遍历
bool XProcess::traverse(std::function<bool(const XProcessInfo& _Info)> _Lambda) noexcept
{
	XANADU_CHECK_RETURN(_Lambda, false);

	auto		vResult = false;

#if defined(_XANADU_SYSTEM_WINDOWS)
	// 给系统内的所有进程拍一个快照--改函数用于获取系统指定进程的快照，也可以传入不同参数获取被这些进程使用的堆、模块和线程的快照
	auto		vProcessEntry32 = PROCESSENTRY32W();
	vProcessEntry32.dwSize = sizeof(vProcessEntry32);
	auto		vSnapshotHandle = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(vSnapshotHandle != INVALID_HANDLE_VALUE)
	{
		vResult = true;
		// 遍历进程快照，轮流显示每个进程的信息
		auto		vMore = ::Process32FirstW(vSnapshotHandle, &vProcessEntry32);
		while(vMore)
		{
			if(!_Lambda(XProcessInfo(static_cast<int64U>(vProcessEntry32.th32ProcessID), vProcessEntry32.szExeFile)))
			{
				// 当取消时返回false
				break;
			}
			vMore = ::Process32NextW(vSnapshotHandle, &vProcessEntry32);
		};
		// 清除hProcessSnap对象
		::CloseHandle(vSnapshotHandle);
	}
#endif//
#if defined(_XANADU_SYSTEM_LINUX)
	vResult = XFileSystem::DirectoryList(L"/proc", [&](const XFileInfo& _Info)->bool
	{
		if(_Info.isDir())
		{
			auto		vExepath = XString::format(L"/proc/%ls/exe", _Info.fileName().data());
			auto		vApplication = vExepath.toUString();
			char		vDirectory[XANADU_PATH] = { 0 };
			auto		vCount = readlink(vApplication.data(), vDirectory, XANADU_PATH);
			if(0 <= vCount || vCount <= XANADU_PATH)
			{
				if(Xanadu::strlen(vDirectory))
				{
					auto	vName = Xanadu::strrchr(vDirectory, '/') + 1;
					if(vName && Xanadu::strlen(vName))
					{
						if(false == _Lambda(XProcessInfo(static_cast<int64U>(_Info.fileName().toLLong()), XString::fromUString(vName))))
						{
							//当取消时返回false
							return false;
						}
					}
				}
			}
		}
		return true;
	});
#endif
#if defined(_XANADU_SYSTEM_MACOS)
	auto		vProcessNumber = proc_listpids(PROC_ALL_PIDS, 0, NULL, 0) * 2;
	if(vProcessNumber)
	{
		auto	vProcessArray = (pid_t*)Xanadu::malloc(sizeof(pid_t) * vProcessNumber);
		if(vProcessArray)
		{
			vProcessNumber = proc_listpids(PROC_ALL_PIDS, 0, vProcessArray, sizeof(pid_t) * vProcessNumber);
			if(vProcessNumber)
			{
				vResult = true;
				for(auto vIndex = 0; vIndex < vProcessNumber; ++vIndex)
				{
					pid_t           vProcessID = vProcessArray[vIndex];
					if(vProcessID == 0)
					{
						continue;
					}
					char			vProcessNAME[1024] = { 0 };
					//char			vProcessPATH[2048] = { 0 };
					//struct proc_bsdinfo     vProcessINFO;
					proc_name(vProcessID, vProcessNAME, 1024);
					//proc_pidpath(vProcessID, vProcessPATH, 2048);
					//proc_pidinfo(vProcessID, PROC_PIDTBSDINFO, 0, &vProcessINFO, PROC_PIDTBSDINFO_SIZE);
					if(false == _Lambda(XProcessInfo(static_cast<int64U>(vProcessID), XString::fromUString(vProcessNAME))))
					{
						//当取消时返回false
						break;
					}
				}
			}
			Xanadu::free(vProcessArray);
		}
	}
#endif
	return vResult;
}

// 进程是否存在
bool XProcess::isExist(const XString& _ProcessName) noexcept
{
	XANADU_CHECK_RETURN(_ProcessName.exist(), false);

	if(XProcess::number(_ProcessName) > 0)
	{
		return true;
	}
	return false;
}

// 同进程名的数量
int64U XProcess::number(const XString& _ProcessName) noexcept
{
	XANADU_CHECK_RETURN(_ProcessName.exist(), 0);

	auto		vNumber = 0;
	XProcess::traverse([&](const XProcessInfo& _ProcessInfo)->bool
	{
		if(_ProcessInfo.getProcessName() == _ProcessName)
		{
			++vNumber;
		}
		return true;
	});
	return vNumber;
}

// 运行并等待进程
int64U XProcess::execute(const XString& _Application, const XString& _Param, const XString& _Directory, bool _Wait, bool _UI) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	DWORD			vExitCode = STATUS_INVALID_HANDLE;
	SHELLEXECUTEINFOW	vInfo = { sizeof(SHELLEXECUTEINFOW) };
	if (_UI)
	{
		vInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	}
	else
	{
		vInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;
	}
	vInfo.lpFile = _Application.data();
	vInfo.lpParameters = _Param.data();
	vInfo.lpDirectory = _Directory.data();
	vInfo.nShow = _UI ? SW_SHOW : SW_HIDE;
	if(ShellExecuteExW(&vInfo))
	{
		auto	vHandle = vInfo.hProcess;
		if(vHandle)
		{
			if(_Wait)
			{
				WaitForSingleObject(vHandle, INFINITE);
				vExitCode = STILL_ACTIVE;
				GetExitCodeProcess(vHandle, &vExitCode);
				CloseHandle(vHandle);
			}
			else
			{
				vExitCode = 0;
			}
		}
	}
	else
	{
		// STATUS_INVALID_HANDLE
		vExitCode = GetLastError();
	}
	return vExitCode;
#else
	auto		vSync = fork();
	if(vSync > 0)
	{
		if(_Wait)
		{
			int 	vStatus = 0;
			::waitpid(vSync, &vStatus, 0);
			if(WIFEXITED(vStatus))
			{
				return WEXITSTATUS(vStatus);
			}
			else
			{
				return WTERMSIG(vStatus);
			}
		}
		return 0;
	}
	else if(vSync == 0)
	{
		auto		vNApplication = _Application.toNString();
		auto		vNDirectory = _Directory.toNString();
		auto		vNParam = _Param.toNString();
		if(-1 == Xanadu::execds(vNApplication.data(), vNDirectory.data(), vNParam.data()))
		{
			Xanadu::exit(0);
		}
	}
	return -1;
#endif
}

// 枚举卸载列表
bool XProcess::program(std::function<void(const XANADU_CORE_PROCESS_UNINSTALL* _Info)> _Lambda) noexcept
{
	auto		vResult = false;
#if defined(_XANADU_SYSTEM_WINDOWS)
	XANADU_CHECK_RETURN(_Lambda, vResult);
	auto		FunctionEnumItem = [&](HKEY _Key, bool _X86)
	{
		LONG		vResult = 0;
		DWORD		vIndex = 0;
		do
		{
			wchar_t		vBuffer[MAX_PATH] = { 0 };
			DWORD		vLength = MAX_PATH;
			Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * MAX_PATH);
			vResult = RegEnumKeyExW(_Key, vIndex, vBuffer, &vLength, NULL, NULL, NULL, NULL);
			if(vResult == ERROR_SUCCESS)
			{
				auto	vInfo = XANADU_NEW XANADU_CORE_PROCESS_UNINSTALL();
				if(vInfo)
				{
					vInfo->_IsX86 = _X86;
					vInfo->_IsX64 = !_X86;
					vInfo->_Label = vBuffer;
					vInfo->_Location = RegisterKeyValue(_Key, vBuffer, L"InstallLocation");
					vInfo->_Name = RegisterKeyValue(_Key, vBuffer, L"DisplayName");
					vInfo->_Uninstall = RegisterKeyValue(_Key, vBuffer, L"UninstallString");
					vInfo->_Version = RegisterKeyValue(_Key, vBuffer, L"DisplayVersion");
					_Lambda(vInfo);
					XANADU_DELETE_PTR(vInfo);
				}
			}
			++vIndex;
		} while(vResult != ERROR_NO_MORE_ITEMS);
	};

	//获取32位
	{
		HKEY		vKey = NULL;
		LONG		vRegedit = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", NULL, KEY_READ, &vKey);
		if(ERROR_SUCCESS == vRegedit)
		{
			FunctionEnumItem(vKey, true);
			RegCloseKey(vKey);
			vResult = true;
		}
	}
	//获取64位
	if(XSystem::IsX64())
	{
		HKEY		vKey = NULL;
		LONG		vRegedit = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", NULL, KEY_READ | KEY_WOW64_64KEY, &vKey);
		if(ERROR_SUCCESS == vRegedit)
		{
			FunctionEnumItem(vKey, false);
			RegCloseKey(vKey);
			vResult = true;
		}
	}
#endif
#if defined(_XANADU_SYSTEM_LINUX)
#endif
#if defined(_XANADU_SYSTEM_MACOS)
	/*
	XFileSystem::DirectoryList(L"/Applications", [&](const XFileInfo& _Info)->bool
	{
		if(_Info.isDir())
		{
			auto	vUninstall = Dynamic::plist_from_file(_Info.filePath() + QString("/Contents/Info.plist"));
			if(vUninstall)
			{
				auto	vInfo = XANADU_NEW XANADU_CORE_PROCESS_UNINSTALL();
				if(vInfo)
				{
					vInfo->_IsX86 = false;
					vInfo->_IsX64 = true;
					vInfo->_Label = Dynamic::plist_node_get_string(Dynamic::plist_dict_get_item(vUninstall, "CFBundleExecutable"));
					vInfo->_Location = L"";
					vInfo->_Name = Dynamic::plist_node_get_string(Dynamic::plist_dict_get_item(vUninstall, "CFBundleDisplayName"));
					vInfo->_Uninstall = L"";
					vInfo->_Version = Dynamic::plist_node_get_string(Dynamic::plist_dict_get_item(vUninstall, "CFBundleShortVersionString"));
					_Lambda(vInfo);
					XANADU_DELETE_PTR(vInfo);
				}
				Dynamic::plist_free(vUninstall);
			}
		}
		return true;
	});
	*/
#endif
	return vResult;
}
