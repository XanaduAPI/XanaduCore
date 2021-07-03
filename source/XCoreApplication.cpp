#include <XanaduCore/XCoreApplication.h>
#include <XanaduCore/XFileSystem.h>
#include <XanaduCore/XRuntime.h>
#if defined(_XANADU_SYSTEM_MACOS)
#include <mach-o/dyld.h>
#endif


// constructor
XCoreApplication::XCoreApplication() noexcept
{
}

// destructor
XCoreApplication::~XCoreApplication() noexcept
{
}



// Gets the path of the current application
XString XCoreApplication::applicationPath() noexcept
{
	static auto		vApplicationPath = XString();
	if(vApplicationPath.empty())
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		wchar_t		vDirectory[XANADU_PATH] = { 0 };
		::GetModuleFileNameW(::GetModuleHandleW(nullptr), vDirectory, XANADU_PATH);
		vApplicationPath = XFileSystem::PathFormat(XString(vDirectory));
#else
#if defined(_XANADU_SYSTEM_MACOS)
		char		vDirectory[XANADU_PATH];
		uint32_t	vLength = XANADU_PATH;
		if(_NSGetExecutablePath(vDirectory, &vLength) != 0)
		{
			vDirectory[0] = '\0';
		}
		else
		{
			char*		vAbsolutePath = realpath(vDirectory, NULL);
			if(vAbsolutePath)
			{
				strncpy(vDirectory, vAbsolutePath, vLength);
				free(vAbsolutePath);
			}
		}
		vApplicationPath = XString::fromUString(vDirectory);
#else
		char		vDirectory[XANADU_PATH] = { 0 };
		auto		vCount = readlink("/proc/self/exe", vDirectory, XANADU_PATH);
		if(0 <= vCount || vCount <= XANADU_PATH)
		{
			vApplicationPath = XFileSystem::PathFormat(XString::fromUString(vDirectory));
		}
#endif
#endif
	}
	return vApplicationPath;
}

// Gets the directory of the current application
XString XCoreApplication::applicationDirectory() noexcept
{
	auto		vApplicationPath = XCoreApplication::applicationPath();
	auto		vFind = vApplicationPath.rfind(L'/');
	if(vFind != XString::npos)
	{
		return vApplicationPath.left(vFind);
	}
	return L"";
}

// Gets the name of the current application
XString XCoreApplication::applicationName() noexcept
{
	auto		vApplicationPath = XCoreApplication::applicationPath();
	auto		vFind = vApplicationPath.rfind(L'/');
	if(vFind != XString::npos)
	{
		return vApplicationPath.substr(vFind + 1);
	}
	return L"";
}

// Gets the running directory of the current application
XString XCoreApplication::currentDirectory() noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	wchar_t			vDirectory[XANADU_PATH] = { 0 };
	Xanadu::GetCurrentDirectoryW(XANADU_PATH, vDirectory);
	return XFileSystem::PathFormat(XString(vDirectory));
#else
	char			vDirectory[XANADU_PATH] = { 0 };
	Xanadu::getcwd(vDirectory, XANADU_PATH);
	return XFileSystem::PathFormat(XString::fromUString(vDirectory));
#endif
}

// sets the running directory of the current application
XString XCoreApplication::setCurrentDirectory(const XString& _Directory) noexcept
{
	auto		vDirectory = XCoreApplication::currentDirectory();
#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vPath = XFileSystem::PathFormat(_Directory);
	Xanadu::SetCurrentDirectoryW(vPath.data());
#else
	auto		vPath = XFileSystem::PathFormat(_Directory).toUString();
	Xanadu::chdir(vPath.data());
#endif
	return vDirectory;
}
