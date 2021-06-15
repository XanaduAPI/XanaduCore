#include <XanaduCore/XShell.h>
#include <XanaduCore/XProcess.h>

XShell::XShell() noexcept
{
}

XShell::~XShell() noexcept
{
}



// Async run shell
int32S XShell::run(const XString& _Shell) noexcept
{
	XANADU_CHECK_RETURN(_Shell.size(), -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return static_cast<int32S>(XProcess::execute(L"cmd.exe", _Shell));
#else
#ifdef _XANADU_SYSTEM_ARM
	return static_cast<int32S>(XProcess::execute(L"/bin/sh", XString(L"-c ") + _Shell));
#else
	return static_cast<int32S>(XProcess::execute(L"/bin/bash", XString(L"-c ") + _Shell));
#endif // _XANADU_SYSTEM_ARM
#endif
}

// Sync run shell
int32S XShell::run(const XString& _Shell, std::function<bool(const XString& _Output)> _Lambda) noexcept
{
	XANADU_CHECK_RETURN(_Shell.exist(), -1);

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
			auto		vFind = vBytes.find('\n');
			if(vFind != XByteArray::npos)
			{
				if(_Lambda)
				{
					_Lambda(XString::fromBytes(vBytes.left(vFind)));
				}
				vBytes.remove(static_cast<XByteArray::size_type>(0U), vFind + 1);
			}

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
	return -1;
}

// Native system
int32S XShell::system(const XString& _Command) noexcept
{
	XANADU_CHECK_RETURN(_Command.size(), -1);

	return Xanadu::wsystem(_Command.data());
}
