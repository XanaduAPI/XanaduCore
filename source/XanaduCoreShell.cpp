#include <XanaduCore/XanaduCoreShell.h>
#include <XanaduCore/XanaduCoreProcess.h>

XShell::XShell() noexcept
{
}

XShell::~XShell() noexcept
{
}



// Async run shell
int64S XShell::run(const XString& _Shell) noexcept
{
	XANADU_CHECK_RETURN(_Shell.size(), -1);

#ifdef XANADU_SYSTEM_WINDOWS
	return XProcess::Execute(L"cmd.exe", _Shell);
#else
	return XProcess::Execute(L"/bin/bash", XString(L"-c ") + _Shell);
#endif//XANADU_SYSTEM_WINDOWS
}

// Sync run shell
int64S XShell::run(const XString& _Shell, std::function<bool(const XString& _Output)> _Lambda) noexcept
{
	XANADU_CHECK_RETURN(_Shell.size(), -1);

	auto		vHandle = Xanadu::popen(_Shell.toNString().data(), "r");
	if(vHandle)
	{
		auto		vBuffer = XANADU_NEW char[XANADU_SIZE_MB];
		Xanadu::memset(vBuffer, 0, XANADU_SIZE_MB);
		while (Xanadu::fgets(vBuffer, XANADU_SIZE_MB, vHandle))
		{
			if(_Lambda)
			{
				_Lambda(XString::fromNString(vBuffer));
			}
		};
		Xanadu::pclose(vHandle);
		return 0;
	}
	return -1;
}

// Native system
int32S XShell::system(const XString& _Command) noexcept
{
	XANADU_CHECK_RETURN(_Command.size(), -1);

	return Xanadu::wsystem(_Command.data());
}
