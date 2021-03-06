﻿#include <XanaduCore/XShell.h>
#include <XanaduCore/XProcess.h>
#include <XanaduCore/XRuntime.h>


XShell::XShell() noexcept
{
}

XShell::~XShell() noexcept
{
}



// Async run shell
int XShell::run(const XString& _Shell) noexcept
{
	XANADU_CHECK_RETURN(_Shell.exist(), -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return static_cast<int>(XProcess::execute(L"cmd.exe", _Shell));
#else
#if defined(_XANADU_SYSTEM_ARM)
	return static_cast<int>(XProcess::execute(L"/bin/sh", XString(L"-c ") + _Shell));
#else
	return static_cast<int>(XProcess::execute(L"/bin/bash", XString(L"-c ") + _Shell));
#endif
#endif
}

// Sync run shell
int XShell::run(const XString& _Shell, const std::function<bool(const XString& _Output)>& _Lambda) noexcept
{
	XANADU_CHECK_RETURN(_Shell.exist(), -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	SECURITY_ATTRIBUTES	sa;
	HANDLE			vRHandle = nullptr;
	HANDLE			vWHandle = nullptr;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = nullptr;
	sa.bInheritHandle = TRUE;

	// 创建匿名管道
	if (::CreatePipe(&vRHandle, &vWHandle, &sa, 0))
	{
		STARTUPINFOW		si;
		PROCESS_INFORMATION	pi;
		Xanadu::memset(&si, 0, sizeof(STARTUPINFOW));
		si.cb = sizeof(STARTUPINFO);
		::GetStartupInfoW(&si);
		si.hStdError = vWHandle;
		si.hStdOutput = vWHandle;
		si.wShowWindow = SW_HIDE;
		si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

		wchar_t 	vApplication[XANADU_PATH] = {0};
		auto		vCommandLine = XANADU_NEW wchar_t[static_cast<size_t>(_Shell.size()) + 100];
		if(vCommandLine)
		{
			Xanadu::wmemset(vCommandLine, 0, static_cast<size_t>(_Shell.size()) + 100);
			auto		vPos = XString::npos;
			if(_Shell[0] == L'\"')
			{
				vPos = _Shell.find(L'\"', 1U);
				if(vPos != XString::npos)
				{
					vPos += 1;
				}
			}
			else
			{
				vPos = _Shell.find(L' ');
			}
			if(vPos == XString::npos)
			{
				vPos = 0;
				Xanadu::wmemcpy(vApplication, _Shell.data(), vPos);
			}
			else
			{
				Xanadu::wmemcpy(vApplication, _Shell.data(), vPos);
				vPos += 1;
			}
			Xanadu::wmemcpy(vCommandLine, _Shell.data() + vPos, static_cast<size_t>(_Shell.size() - vPos));

			// 修复 CreateProcess GetLastError = 123 的错误
			if(vApplication[0] == L'\"' && vApplication[Xanadu::wcslen(vApplication) - 1] == L'\"')
			{
				vApplication[Xanadu::wcslen(vApplication) - 1] = L'\0';
				Xanadu::wmemmove(vApplication, vApplication + 1, Xanadu::wcslen(vApplication) - 1);
				vApplication[Xanadu::wcslen(vApplication) - 1] = L'\0';
			}
			// 创建子进程
			if (::CreateProcessW(vApplication, vCommandLine, nullptr, nullptr, TRUE, NULL, nullptr, nullptr, &si, &pi))
			{
				::CloseHandle(vWHandle);

				auto		vBuffer = XANADU_NEW char[XANADU_SIZE_KB];
				auto		vBytes = XByteArray();
				auto		vSync = static_cast<DWORD>(0);
				for(; vBuffer;)
				{
					Xanadu::memset(vBuffer, 0, XANADU_SIZE_KB);
					auto		vSuccess = (::ReadFile(vRHandle, vBuffer, XANADU_SIZE_KB, &vSync, nullptr) == TRUE);
					if(vSync > 0)
					{
						vBytes += XByteArray(vBuffer, Xanadu::strlen(vBuffer));
					}
					// Loop detection here to prevent multiple messages from merging together.
					do{
						auto		vFind = vBytes.find('\n');
						if(vFind == XByteArray::npos)
						{
							break;
						}
						else
						{
							if(_Lambda)
							{
								_Lambda(XString::fromBytes(vBytes.left(vFind)));
							}
							vBytes.remove(static_cast<XByteArray::size_type>(0U), vFind + 1);
						}
					}while(true);
					if(!vSuccess)
					{
						if(ERROR_BROKEN_PIPE == ::GetLastError())
						{
							break;
						}
					}
				}
				if(_Lambda)
				{
					_Lambda(XString::fromBytes(vBytes));
				}
				if(vBuffer)
				{
					XANADU_DELETE_ARR(vBuffer);
				}

				::CloseHandle(vRHandle);

				// 等待进程结束
				::WaitForSingleObject(pi.hProcess, INFINITE);
				auto		vExitCode = static_cast<DWORD>(STILL_ACTIVE);
				::GetExitCodeProcess(pi.hProcess, &vExitCode);
				// ::CloseHandle(pi.hProcess);
				XANADU_DELETE_ARR(vCommandLine);
				return vExitCode;
			}
			else
			{
				XANADU_DELETE_ARR(vCommandLine);
				return GetLastError();
			}

		}
	}
#else
	auto		vHandle = Xanadu::popen(_Shell.toNString().data(), "r");
	if(vHandle)
	{
		auto		vBuffer = XANADU_NEW char[XANADU_SIZE_KB];
		auto		vBytes = XByteArray();
		for(; vBuffer;)
		{
			Xanadu::memset(vBuffer, 0, XANADU_SIZE_KB);
			auto		vSync = Xanadu::fgets(vBuffer, XANADU_SIZE_KB, vHandle);
			vBytes += XByteArray(vBuffer, Xanadu::strlen(vBuffer));
			// Loop detection here to prevent multiple messages from merging together.
			do{
				auto		vFind = vBytes.find('\n');
				if(vFind == XByteArray::npos)
				{
					break;
				}
				else
				{
					if(_Lambda)
					{
						_Lambda(XString::fromBytes(vBytes.left(vFind)));
					}
					vBytes.remove(static_cast<XByteArray::size_type>(0U), vFind + 1);
				}
			}while(true);
			if(vSync == nullptr)
			{
				if(0 != Xanadu::ferror(vHandle) || 0 != Xanadu::feof(vHandle))
				{
					break;
				}
			}
		}
		if(_Lambda)
		{
			_Lambda(XString::fromBytes(vBytes));
		}
		if(vBuffer)
		{
			XANADU_DELETE_ARR(vBuffer);
		}
		return Xanadu::pclose(vHandle);
	}
#endif
	return -1;
}

// Native system
int XShell::system(const XString& _Command) noexcept
{
	XANADU_CHECK_RETURN(_Command.size(), -1);

	return Xanadu::wsystem(_Command.data());
}
