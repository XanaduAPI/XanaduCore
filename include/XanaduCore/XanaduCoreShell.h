#ifndef			_XANADU_CORE_SHELL_H_
#define			_XANADU_CORE_SHELL_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

/// Xanadu Class Shell
class XANADU_CORE_EXPORT XShell
{
public:
	XShell() XANADU_NOTHROW;

	virtual ~XShell() XANADU_NOTHROW;

public:
	/// Async run shell
	static int64S Run(const XString& _Shell) XANADU_NOTHROW;

	/// Sync run shell
	static int64S Run(const XString& _Shell, std::function<bool(const XString& _Output)> _Lambda) XANADU_NOTHROW;

	/// Native System
	static int32S System(const XString& _Command) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_SHELL_H_
