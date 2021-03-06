#ifndef			_XANADU_CORE_SHELL_H_
#define			_XANADU_CORE_SHELL_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

// Xanadu Class Shell
class XANADU_CORE_EXPORT XShell
{
public:
	XShell() noexcept;

	virtual ~XShell() noexcept;

public:
	// Async run shell
	static int64S run(const XString& _Shell) noexcept;

	// Sync run shell
	static int64S run(const XString& _Shell, std::function<bool(const XString& _Output)> _Lambda) noexcept;

	// Native system
	static int32S system(const XString& _Command) noexcept;
};

#endif // _XANADU_CORE_SHELL_H_
