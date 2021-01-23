//
// Created by Administrator on 2021/1/20.
//

#include <XanaduCore/XanaduCoreSystem.h>
#include <XanaduCore/XanaduCoreHash.h>
#include <XanaduCore/XanaduCoreLibrary.h>
#ifndef XANADU_SYSTEM_WINDOWS
#include <sys/utsname.h>
#endif /// XANADU_SYSTEM_WINDOWS


//static system version value
static int64S					_StaticSystemVersion = 0;

//initialize
XSystem::XSystem() XANADU_NOTHROW
{
}

//release
XSystem::~XSystem() XANADU_NOTHROW
{
}

/// The current version of the operating system
int64S XSystem::SystemVersion() XANADU_NOTHROW
{
	if(!_StaticSystemVersion)
	{
#ifdef XANADU_SYSTEM_WINDOWS
		typedef void(WINAPI* _Function_GetVersionNumbers)(short*, short*, short*);
		auto		vVersion_1 = static_cast<short>(0);
		auto		vVersion_2 = static_cast<short>(0);
		auto		vValue3 = static_cast<short>(0);
		auto		vIsServer = IsServer();
		auto		vModule = XLibrary::Open(L"ntdll.dll");
		if(vModule)
		{
			auto		GetVersionNumbers = (_Function_GetVersionNumbers)XLibrary::Find(vModule, "RtlGetNtVersionNumbers");
			if(GetVersionNumbers)
			{
				GetVersionNumbers(&vVersion_1, &vVersion_2, &vValue3);
				switch(vVersion_1)
				{
					case 10:
						_StaticSystemVersion = vIsServer ? XANADU_OS_VERSION_WINDOWS_2016 : XANADU_OS_VERSION_WINDOWS_10;
						break;
					case 6:
						switch(vVersion_2)
						{
							case 0:
								_StaticSystemVersion = vIsServer ? XANADU_OS_VERSION_WINDOWS_2008 : XANADU_OS_VERSION_WINDOWS_VISTA;
								break;
							case 1:
								_StaticSystemVersion = vIsServer ? XANADU_OS_VERSION_WINDOWS_2008_R2 : XANADU_OS_VERSION_WINDOWS_7;
								break;
							case 2:
								_StaticSystemVersion = vIsServer ? XANADU_OS_VERSION_WINDOWS_2012 : XANADU_OS_VERSION_WINDOWS_8;
								break;
							case 3:
								_StaticSystemVersion = vIsServer ? XANADU_OS_VERSION_WINDOWS_2012_R2 : XANADU_OS_VERSION_WINDOWS_8_1;
								break;
							default:
								break;
						}
						break;
					default:
						_StaticSystemVersion = XANADU_OS_VERSION_UNKNOWN;
						break;
				}
			}
			XLibrary::Close(vModule);
		}
#endif//XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
		//XANADU_PLATFORM_NOSUPPORT;
#endif//XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
		struct utsname		vVersion;
		if(0 == uname(&vVersion))
		{
			auto	vValue1 = Xanadu::atoi(vVersion.release);
			switch(vValue1)
			{
				case 12:
					_StaticSystemVersion = XANADU_OS_VERSION_MACOS_1012;
					break;
				case 13:
					_StaticSystemVersion = XANADU_OS_VERSION_MACOS_1013;
					break;
				case 14:
					_StaticSystemVersion = XANADU_OS_VERSION_MACOS_1014;
					break;
				case 15:
					_StaticSystemVersion = XANADU_OS_VERSION_MACOS_1015;
					break;
				case 16:
					_StaticSystemVersion = XANADU_OS_VERSION_MACOS_1100;
					break;
				default:
					_StaticSystemVersion = XANADU_OS_VERSION_UNKNOWN;
					break;
			}
		}
#endif//XANADU_SYSTEM_MACOS
	}
	return _StaticSystemVersion;
}

/// The name of the user who is now logged in
XString XSystem::CurrentUser() XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	wchar_t		vUserName[XANADU_SIZE_KB] = { 0 };
	DWORD		vUserLength = XANADU_SIZE_KB - 1;
	GetUserNameW(vUserName, &vUserLength);
	return XString(vUserName);
#else
	return XString::FromUString(getlogin());
#endif /// XANADU_SYSTEM_WINDOWS
}

/// Computer name
XString XSystem::HostName() XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	wchar_t		vHostName[XANADU_PATH] = { 0 };
	DWORD		vLength = XANADU_PATH;
	GetComputerNameW(vHostName, &vLength);
	return XString(vHostName);
#else
	char		vHostName[XANADU_PATH] = { 0 };
	gethostname(vHostName, XANADU_PATH);
	return XString::FromUString(vHostName);
#endif//XANADU_SYSTEM_WINDOWS
}

/// Gets the directory for the current user
XString XSystem::UserHome() XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	return XString(L"C:/Users/") + XSystem::CurrentUser();
#endif /// XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
	return XString(L"/home/") + XSystem::CurrentUser();
#endif /// XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return XString(L"/Users/") + XSystem::CurrentUser();
#endif /// XANADU_SYSTEM_MACOS
}

/// Whether the operating system is 32-bit
bool XSystem::IsX86() XANADU_NOTHROW
{
	return !XSystem::IsX64();
}

/// Whether the operating system is 64-bit
bool XSystem::IsX64() XANADU_NOTHROW
{
	static Xanadu::Boolean		vValue64Bit = Xanadu::VALUE_NULL;
	if(Xanadu::VALUE_NULL == vValue64Bit)
	{
#ifdef XANADU_SYSTEM_WINDOWS
		SYSTEM_INFO	vSystemInfo;
		GetNativeSystemInfo(&vSystemInfo);
		switch(vSystemInfo.wProcessorArchitecture)
		{
			case PROCESSOR_ARCHITECTURE_AMD64:
			case PROCESSOR_ARCHITECTURE_IA64:
			case PROCESSOR_ARCHITECTURE_ALPHA64:
				vValue64Bit = Xanadu::VALUE_TRUE;
				break;
			default:
				vValue64Bit = Xanadu::VALUE_FALSE;
				break;
		}
#else
		vValue64Bit = Xanadu::VALUE_TRUE;
#endif//XANADU_SYSTEM_WINDOWS
	}
	return Xanadu::VALUE_TRUE == vValue64Bit ? true : false;
}

/// Whether the operating system is a server version
bool XSystem::IsServer() XANADU_NOTHROW
{
	static Xanadu::Boolean		vValueServer = Xanadu::VALUE_NULL;
	if(Xanadu::VALUE_NULL == vValueServer)
	{
#ifdef XANADU_SYSTEM_WINDOWS
		typedef BOOL(WINAPI* _Function_IsWindowsServer)();
		auto		vHandle = XLibrary::Open(L"Kernel32.dll");
		if(vHandle)
		{
			auto	vIsWindowsServer = (_Function_IsWindowsServer)XLibrary::Find(vHandle, "IsWindowsServer");
			if(vIsWindowsServer)
			{
				vValueServer = vIsWindowsServer() ? Xanadu::VALUE_TRUE : Xanadu::VALUE_FALSE;
			}
			XLibrary::Close(vHandle);
		}
#else
		vValueServer = Xanadu::VALUE_FALSE;
#endif//XANADU_SYSTEM_WINDOWS
	}
	return Xanadu::VALUE_TRUE == vValueServer ? true : false;
}

/// Whether the operating system is a desktop version
bool XSystem::IsDesktop() XANADU_NOTHROW
{
	return !XSystem::IsServer();
}

/// Native System String
XString XSystem::NativeString() XANADU_NOTHROW
{
	static XString			_StaticNativeString;
	if (_StaticNativeString.empty())
	{
#ifdef XANADU_SYSTEM_WINDOWS
		auto		vSystemString = XString(L"Microsoft Windows ");
#endif//XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
		auto		vSystemString = XString(L"Linux ");
#endif//XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
		auto		vSystemString = XString(L"Mac OS ");
#endif//XANADU_SYSTEM_MACOS
		//拼接系统版本
		switch(XSystem::SystemVersion())
		{
#ifdef XANADU_SYSTEM_WINDOWS
			case XANADU_OS_VERSION_WINDOWS_VISTA:
				vSystemString += L"Vista";
				break;
			case XANADU_OS_VERSION_WINDOWS_2008:
				vSystemString += L"Server 2008";
				break;
			case XANADU_OS_VERSION_WINDOWS_7:
				vSystemString += L"7";
				break;
			case XANADU_OS_VERSION_WINDOWS_2008_R2:
				vSystemString += L"Server 2008 R2";
				break;
			case XANADU_OS_VERSION_WINDOWS_8:
				vSystemString += L"8";
				break;
			case XANADU_OS_VERSION_WINDOWS_2012:
				vSystemString += L"Server 2012";
				break;
			case XANADU_OS_VERSION_WINDOWS_8_1:
				vSystemString += L"8.1";
				break;
			case XANADU_OS_VERSION_WINDOWS_2012_R2:
				vSystemString += L"Server 2012 R2";
				break;
			case XANADU_OS_VERSION_WINDOWS_10:
				vSystemString += L"10";
				break;
			case XANADU_OS_VERSION_WINDOWS_2016:
				vSystemString += L"Server 2016";
				break;
#endif//XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
				case XANADU_OS_VERSION_LINUX_1404:
				vSystemString += L"Linux 14.04";
				break;
			case XANADU_OS_VERSION_LINUX_1410:
				vSystemString += L"Linux 14.10";
				break;
			case XANADU_OS_VERSION_LINUX_1504:
				vSystemString += L"Linux 15.04";
				break;
			case XANADU_OS_VERSION_LINUX_1510:
				vSystemString += L"Linux 15.10";
				break;
			case XANADU_OS_VERSION_LINUX_1604:
				vSystemString += L"Linux 16.04";
				break;
			case XANADU_OS_VERSION_LINUX_1610:
				vSystemString += L"Linux 16.10";
				break;
			case XANADU_OS_VERSION_LINUX_1704:
				vSystemString += L"Linux 17.04";
				break;
			case XANADU_OS_VERSION_LINUX_1710:
				vSystemString += L"Linux 17.10";
				break;
			case XANADU_OS_VERSION_LINUX_1804:
				vSystemString += L"Linux 18.04";
				break;
			case XANADU_OS_VERSION_LINUX_1810:
				vSystemString += L"Linux 18.10";
				break;
			case XANADU_OS_VERSION_LINUX_1904:
				vSystemString += L"Linux 19.04";
				break;
			case XANADU_OS_VERSION_LINUX_1910:
				vSystemString += L"Linux 19.10";
				break;
			case XANADU_OS_VERSION_LINUX_2004:
				vSystemString += L"Linux 2004";
				break;
			case XANADU_OS_VERSION_LINUX_2010:
				vSystemString += L"Linux 2010";
				break;
			case XANADU_OS_VERSION_LINUX_2104:
				vSystemString += L"Linux 2104";
				break;
			case XANADU_OS_VERSION_LINUX_2110:
				vSystemString += L"Linux 2110";
				break;
#endif//XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
				case XANADU_OS_VERSION_MACOS_1012:
				vSystemString += L"10.12 Sierra";
				break;
			case XANADU_OS_VERSION_MACOS_1013:
				vSystemString += L"10.13 High Sierra";
				break;
			case XANADU_OS_VERSION_MACOS_1014:
				vSystemString += L"10.14 Mojave";
				break;
			case XANADU_OS_VERSION_MACOS_1015:
				vSystemString += L"10.15 Catalina";
				break;
			case XANADU_OS_VERSION_MACOS_1100:
				vSystemString += L"11.00 Big Sur";
				break;
			case XANADU_OS_VERSION_MACOS_1101:
				vSystemString += L"11.01 Big Sur";
				break;
#endif//XANADU_SYSTEM_MACOS
			default:
				vSystemString += L"Unknown";
				break;
		}
		//拼接编译版本
		vSystemString += L" (build ";
		vSystemString += XSystem::BuildVersion();
		vSystemString += L")";

		//拼接系统位数
		if(XSystem::IsX64())
		{
			vSystemString += L",64-Bit";
		}
		else
		{
			vSystemString += L",32-Bit";
		}
		_StaticNativeString = vSystemString;
	}
	return _StaticNativeString;
}

/// Native Build Version
XString XSystem::BuildVersion() XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	auto		vBuildVersion = XString();
	auto		vModule = XLibrary::Open(L"ntdll.dll");
	if(vModule)
	{
		int16S		vValue1 = 0;
		int16S		vValue2 = 0;
		int16S		vValue3 = 0;
		typedef void(WINAPI* LP_GetVersionNumbers)(int16S*, int16S*, int16S*);
		LP_GetVersionNumbers	GetVersionNumbers = (LP_GetVersionNumbers)XLibrary::Find(vModule, "RtlGetNtVersionNumbers");
		if(GetVersionNumbers)
		{
			GetVersionNumbers(&vValue1, &vValue2, &vValue3);
			vBuildVersion = XString::Format(L"%d", vValue3);

		}
		XLibrary::Close(vModule);
	}
	return vBuildVersion;
#endif//XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
	return XString(L"Unknown");
#endif//XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return XString(L"Unknown");
#endif//XANADU_SYSTEM_MACOS
}

/// The CPUID of the current computer
XString XSystem::CPUID() XANADU_NOTHROW
{
	static wchar_t			_StaticCpuID[XANADU_PATH] = { 0 };
	if(!Xanadu::wcslen(_StaticCpuID))
	{
		unsigned long		vValue1 = 0;
		unsigned long		vValue2 = 0;

#ifdef XANADU_SYSTEM_WINDOWS
		__asm {
			mov eax, 01h;
			xor edx, edx;
			cpuid;
			mov vValue1, edx;
			mov vValue2, eax;
		}
#else
		asm volatile
			(
				"movl $0x01, %%eax; \n\t"
				"xorl %%edx, %%edx; \n\t"
				"cpuid; \n\t"
				"movl %%edx, %0; \n\t"
				"movl %%eax, %1; \n\t"
				: "=m"(vValue1), "=m"(vValue2)
				);
#endif//XANADU_SYSTEM_WINDOWS
		swprintf(_StaticCpuID, XANADU_PATH, L"%08X%08X", vValue1, vValue2);
	}
	return XString(_StaticCpuID);
}

/// The hard disk ID of the current computer
XString XSystem::DiskID() XANADU_NOTHROW
{
	static wchar_t				_StaticDiskID[XANADU_PATH] = { 0 };
	if(0LL == Xanadu::wcslen(_StaticDiskID))
	{
#ifdef XANADU_SYSTEM_WINDOWS
		auto		vHandle = ::CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
		if(!vHandle)
		{
			vHandle = ::CreateFileA("\\\\.\\Scsi0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
		}
		if(vHandle)
		{
			DWORD			dwBytesReturned = 0;
			GETVERSIONINPARAMS	gVersionParsams;
			Xanadu::memset(&gVersionParsams, 0, sizeof(GETVERSIONINPARAMS));

			if(DeviceIoControl(vHandle, SMART_GET_VERSION, NULL, NULL, &gVersionParsams, sizeof(GETVERSIONINPARAMS), &dwBytesReturned, NULL))
			{
				if(dwBytesReturned != 0 && gVersionParsams.bIDEDeviceMap > 0)
				{
					SENDCMDINPARAMS		scip;
					Xanadu::memset(&scip, 0, sizeof(SENDCMDINPARAMS));
					scip.cBufferSize = IDENTIFY_BUFFER_SIZE;
					scip.irDriveRegs.bSectorCountReg = 1;
					scip.irDriveRegs.bSectorNumberReg = 1;
					scip.irDriveRegs.bDriveHeadReg = 0xA0;
					scip.irDriveRegs.bCommandReg = 0xEC;

					BYTE btBuffer[1024] = { 0 };

					if(DeviceIoControl(vHandle, SMART_RCV_DRIVE_DATA, &scip, sizeof(SENDCMDINPARAMS), btBuffer, 1024, &dwBytesReturned, NULL))
					{
						//序列号的开始位置,具体请参考SENDCMDOUTPARAMS与IDSECTOR结构
						auto		vSerialPos = 0x24;
						auto		vLocalPos = 0;
						while(btBuffer[vSerialPos] < 128)
						{
							_StaticDiskID[vLocalPos++] = btBuffer[vSerialPos++];
						}
					}
				}
			}
			::CloseHandle(vHandle);
		}
#endif//XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
#endif//XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
		//system_profiler SPSerialATADataType | grep Serial
		/*
		XShell::Run(L"system_profiler SPSerialATADataType | grep Serial", [&](XString _Output)->bool
		{
			_Output.remove(L"Serial Number:");
			_Output.simplified();
			if(!_Output.empty())
			{
				Xanadu::wcscpy(_StaticDiskID, _Output.data());
			}
		});
		 */
#endif//XANADU_SYSTEM_MACOS
	}
	return XString(_StaticDiskID);
}

/// A string unique to the current computer
XString XSystem::OnlyString() XANADU_NOTHROW
{
	static XString			_StaticOnlyString;
	if(_StaticOnlyString.empty())
	{
		auto		vTempOnlyString = XSystem::NativeString() + L"_CPU[" + XSystem::CPUID() + L"]_DISK[" + XSystem::DiskID() + L"]_MachineGuid[";
#ifdef XANADU_SYSTEM_WINDOWS
		/// 获取MachineGuid(重装系统后改变)
		HKEY		vKey = NULL;
		LSTATUS		vResult = ERROR_SUCCESS;
		if(XSystem::IsX64())
		{
			vResult = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Cryptography", NULL, KEY_READ | KEY_WOW64_64KEY, &vKey);
		}
		else
		{
			vResult = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Cryptography", NULL, KEY_READ, &vKey);
		}
		if(ERROR_SUCCESS == vResult)
		{
			wchar_t		vBuffer[MAX_PATH] = { 0 };
			DWORD		vLength = MAX_PATH;
			DWORD		vType = REG_SZ;
			Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * MAX_PATH);
			LSTATUS		vQuery = RegQueryValueExW(vKey, L"MachineGuid", NULL, &vType, (byte*)vBuffer, &vLength);
			if(vQuery == ERROR_SUCCESS)
			{
				vTempOnlyString += vBuffer;
			}
			RegCloseKey(vKey);
		}
#else
		vTempOnlyString += XString::Format(L"%lld", gethostid());
#endif /// XANADU_SYSTEM_WINDOWS
		vTempOnlyString += L"]";
		_StaticOnlyString = XString::FromBytes(XCryptoHash::Hash(vTempOnlyString.ToBytes(), XCryptoHash::MD5).ToHex().toUpper());
	}
	return _StaticOnlyString;
}