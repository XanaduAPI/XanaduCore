//
// Created by Administrator on 2021/1/12.
//

/*
 * This file is an exception declaration for the Xanadu family
 * */

#ifndef			_XANADU_CORE_FILEINFO_H_
#define			_XANADU_CORE_FILEINFO_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

class XFileInfoPrivate;

/// File information
class XANADU_CORE_EXPORT XFileInfo
{
private:
	/// Private structures
	XFileInfoPrivate*			_Info;

public:
	/// Overload Initialize
	XFileInfo() XANADU_NOTHROW;

	/// Overload Initialize
	XFileInfo(const XString& _Filepath) XANADU_NOTHROW;

	/// Overload Initialize
	XFileInfo(const XFileInfo& _Fileinfo) XANADU_NOTHROW;

	/// Virtual destructor
	virtual ~XFileInfo() XANADU_NOTHROW;

public:
	/// Overload Operator =
	XFileInfo& operator = (const XString& _Filepath) XANADU_NOTHROW;

	/// Overload Operator =
	XFileInfo& operator = (const XFileInfo& _Fileinfo) XANADU_NOTHROW;

public:
	/// Convert to an absolute path
	static XString ToAbsolutePath(const XString& _Filepath) XANADU_NOTHROW;

	/// Convert to an relative path
	static XString ToRelativePath(const XString& _Filepath) XANADU_NOTHROW;

public:
	/// Check if the file exists
	virtual bool exists() const XANADU_NOTHROW;

	virtual XString filePath() const XANADU_NOTHROW;

	virtual XString absoluteFilePath() const XANADU_NOTHROW;

	virtual XString fileName() const XANADU_NOTHROW;

	virtual XString baseName() const XANADU_NOTHROW;

	virtual XString completeBaseName() const XANADU_NOTHROW;

	virtual XString suffix() const XANADU_NOTHROW;

	virtual XString completeSuffix() const XANADU_NOTHROW;

	virtual XString path() const XANADU_NOTHROW;

	virtual XString absolutePath() const XANADU_NOTHROW;

	virtual XString dir() const XANADU_NOTHROW;

	virtual XString absoluteDir() const XANADU_NOTHROW;

	virtual bool isFile() const XANADU_NOTHROW;

	virtual bool isDir() const XANADU_NOTHROW;

	virtual int64S size() const XANADU_NOTHROW;

public:
	/// Check if the file exists
	static bool exists(const XString& _Filepath) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_FILEINFO_H_
