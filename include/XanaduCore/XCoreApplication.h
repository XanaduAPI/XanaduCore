#ifndef			_XANADU_CORE_XCOREAPPLICATION_H_
#define			_XANADU_CORE_XCOREAPPLICATION_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>

///  <summary>
///  Some common operations of application program
///  </summary>
class XANADU_CORE_EXPORT XCoreApplication
{
public:
	// constructor
	XCoreApplication() noexcept;

	// destructor
	virtual ~XCoreApplication() noexcept;

public:
	// Gets the path of the current application
	static XString applicationPath() noexcept;

	// Gets the directory of the current application
	static XString applicationDirectory() noexcept;

	// Gets the name of the current application
	static XString applicationName() noexcept;

	// Gets the running directory of the current application
	static XString currentDirectory() noexcept;

	// sets the running directory of the current application
	static XString setCurrentDirectory(const XString& _Directory) noexcept;
};

#endif
