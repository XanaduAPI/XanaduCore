#include <XanaduRuntime/System.h>
#include <XanaduRuntime/String.h>
#include <XanaduRuntime/Memory.h>


// 执行命令。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::system(const char* _Command) noexcept
{
	XANADU_CHECK_RETURN(_Command, -1);

	return ::system(_Command);
}

// 执行命令。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wsystem(const wchar_t* _Command) noexcept
{
	XANADU_CHECK_RETURN(_Command, -1);

	auto 		vNCommand = Xanadu::strwton(_Command);
	auto 		vResult = Xanadu::system(vNCommand);
	Xanadu::strfree(vNCommand);
	return vResult;
}

// 获取系统错误消息字符串
XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strerror(int _Error) noexcept
{
	return ::strerror(_Error);
}

// 获取系统错误消息字符串
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcserror(int _Error) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wcserror(_Error);
#else
	static wchar_t*		_staticStringError = nullptr;
	auto		vMessage = ::strerror(_Error);
	if(vMessage)
	{
		if(_staticStringError)
		{
			Xanadu::wcsfree(_staticStringError);
			_staticStringError = nullptr;
		}
		_staticStringError = Xanadu::strntow(vMessage);
		return _staticStringError;
	}
	return nullptr;
#endif
}

// 强制将块缓存区中修改写入磁盘。
XANADU_RUNTIME_EXPORT void XANADUAPI Xanadu::sync() noexcept
{
#if !defined(XANADU_SYSTEM_WINDOWS)
	::sync();
#endif
}

// 获取本机的HostID
XANADU_RUNTIME_EXPORT long long XANADUAPI Xanadu::gethostid() noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	auto		vHostID = 0ULL;
	auto 		vLength = (ULONG)(sizeof(IP_ADAPTER_ADDRESSES));
	auto 		vAddresses = (IP_ADAPTER_ADDRESSES*)Xanadu::malloc(vLength);
	if(vAddresses)
	{
		// 对GetAdaptersAddresses进行初始调用，以获得所需要的内存大小
		if(GetAdaptersAddresses(AF_UNSPEC, 0, nullptr, vAddresses, &vLength) == ERROR_BUFFER_OVERFLOW)
		{
			Xanadu::free(vAddresses);
			vAddresses = (IP_ADAPTER_ADDRESSES*)Xanadu::malloc(vLength);
			if(vAddresses)
			{
				if(GetAdaptersAddresses(AF_UNSPEC, 0, nullptr, vAddresses, &vLength) == NO_ERROR)
				{
					// 如果成功，从接收到的数据中取出第一个网卡，并转换为HostID
					for(auto vIterator = vAddresses; vIterator && vHostID == 0ULL; vIterator = vIterator->Next)
					{
						// 确保MAC地址的长度为 00-00-00-00-00-00
						if(vIterator->PhysicalAddressLength == 6)
						{
							for(auto vIndex = 0; vIndex < 6; ++vIndex)
							{
								vHostID = vHostID << 8;
								vHostID += vIterator->PhysicalAddress[vIndex];
							}
						}
					}
				}
				Xanadu::free(vAddresses);
			}
		}
		else
		{
			Xanadu::free(vAddresses);
		}
	}
	return vHostID;
#else
	return static_cast<int64S>(gethostid());
#endif
}




// 检索当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::getcwd(char* _Buffer, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_getcwd(_Buffer, _Size);
#else
	return ::getcwd(_Buffer, _Size);
#endif
}

// 检索当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wgetcwd(wchar_t* _Buffer, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wgetcwd(_Buffer, _Size);
#else
	auto		vSync = static_cast<wchar_t*>(nullptr);
	auto		vNChar = (char*)Xanadu::malloc(_Size);
	if(vNChar)
	{
		if(::getcwd(vNChar, _Size))
		{
			auto		vWChar = Xanadu::strntow(vNChar);
			if(vWChar)
			{
				Xanadu::wmemcpy(_Buffer, vWChar, _Size);
				vSync = _Buffer;
				Xanadu::wcsfree(vWChar);
			}
		}
		Xanadu::free(vNChar);
	}
	// errno = ENOMEM;
	return vSync;
#endif
}

// 更改当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::chdir(const char* _Dirname) noexcept
{
	XANADU_CHECK_RETURN(_Dirname, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::SetCurrentDirectoryA(_Dirname) ? 0 : -1;
#else
	return ::chdir(_Dirname);
#endif
}

// 更改当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wchdir(const wchar_t* _Dirname) noexcept
{
	XANADU_CHECK_RETURN(_Dirname, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::SetCurrentDirectoryW(_Dirname) ? 0 : -1;
#else
	auto		vNDirname = Xanadu::strwton(_Dirname);
	if(vNDirname)
	{
		auto		vChdir = ::chdir(vNDirname);
		Xanadu::strfree(vNDirname);
		return vChdir;
	}
	return ENOMEM;
#endif
}

// 检索当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentDirectoryA(unsigned long _Length, char* _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, 0);
	XANADU_CHECK_RETURN(_Length, 0);

	Xanadu::memset(_Buffer, 0, _Length);
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::GetCurrentDirectoryA(_Length, _Buffer);
#else
	if(Xanadu::getcwd(_Buffer, _Length))
	{
		return Xanadu::strlen(_Buffer);
	}
	return 0;
#endif
}

// 检索当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentDirectoryW(unsigned long _Length, wchar_t* _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, 0);
	XANADU_CHECK_RETURN(_Length, 0);

	Xanadu::wmemset(_Buffer, 0, _Length);
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::GetCurrentDirectoryW(_Length, _Buffer);
#else
	char		vABuffer[XANADU_PATH] = {0};
	if(Xanadu::getcwd(vABuffer, XANADU_PATH))
	{
		auto	vWBuffer = Xanadu::strntow(vABuffer);
		if(vWBuffer)
		{
			Xanadu::wcsncpy(_Buffer, vWBuffer, _Length);
			Xanadu::wcsfree(vWBuffer);
			return Xanadu::wcslen(_Buffer);
		}
	}
	return 0;
#endif
}

// 更改当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::SetCurrentDirectoryA(const char* _PathName) noexcept
{
	XANADU_CHECK_RETURN(_PathName, 0);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::SetCurrentDirectoryA(_PathName);
#else
	return  Xanadu::chdir(_PathName) == 0 ? 1 : 0;
#endif
}

// 更改当前进程的当前工作目录。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::SetCurrentDirectoryW(const wchar_t* _PathName) noexcept
{
	XANADU_CHECK_RETURN(_PathName, 0);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::SetCurrentDirectoryW(_PathName);
#else
	return Xanadu::wchdir(_PathName) == 0 ? 1 : 0;
#endif
}
