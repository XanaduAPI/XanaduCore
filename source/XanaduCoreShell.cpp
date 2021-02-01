#include <XanaduCore/XanaduCoreShell.h>
#include <XanaduCore/XanaduCoreProcess.h>

XShell::XShell() XANADU_NOTHROW
{
}

XShell::~XShell() XANADU_NOTHROW
{
}



/// Async run shell
int64S XShell::Run(const XString& _Shell) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Shell.size(), -1);

#ifdef XANADU_SYSTEM_WINDOWS
	return XProcess::Execute(L"cmd.exe", _Shell);
#else
	return XProcess::Execute(L"/bin/bash", XString(L"-c ") + _Shell);
#endif//XANADU_SYSTEM_WINDOWS
}

/// Sync run shell
int64S XShell::Run(const XString& _Shell, std::function<bool(const XString& _Output)> _Lambda) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Shell.size(), -1);

	auto		vHandle = Xanadu::popen(_Shell.ToNString().data(), "r");
	if(vHandle)
	{
		auto		vBuffer = XANADU_NEW char[XANADU_SIZE_MB];
		Xanadu::memset(vBuffer, 0, XANADU_SIZE_MB);
		while (Xanadu::fgets(vBuffer, XANADU_SIZE_MB, vHandle))
		{
			if(_Lambda)
			{
				_Lambda(XString::FromNString(vBuffer));
			}
		};
		Xanadu::pclose(vHandle);
		return 0;
	}
	return -1;
}

/// Native System
int32S XShell::System(const XString& _Command) XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Command.size(), -1);

	return Xanadu::wsystem(_Command.data());
}
