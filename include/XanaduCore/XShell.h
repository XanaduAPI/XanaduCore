#ifndef			_XANADU_CORE_SHELL_H_
#define			_XANADU_CORE_SHELL_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

// Xanadu Class Shell
class XANADU_CORE_EXPORT XShell
{
public:
	XShell() noexcept;

	virtual ~XShell() noexcept;

public:
	// Async run shell
	static int run(const XString& _Shell) noexcept;

	// Sync run shell
	static int run(const XString& _Shell, const std::function<bool(const XString& _Output)>& _Lambda) noexcept;

	// Native system
	static int system(const XString& _Command) noexcept;
};

#endif
