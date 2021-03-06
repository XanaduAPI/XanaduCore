﻿/*
 * This file is an exception declaration for the Xanadu family
 * */

#ifndef			_XANADU_CORE_FILEINFO_H_
#define			_XANADU_CORE_FILEINFO_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>


#ifndef _XANADU_SYSTEM_WINDOWS
#define FILE_ATTRIBUTE_READONLY				0x00000001
#define FILE_ATTRIBUTE_HIDDEN				0x00000002
#define FILE_ATTRIBUTE_SYSTEM				0x00000004
#define FILE_ATTRIBUTE_DIRECTORY			0x00000010
#define FILE_ATTRIBUTE_ARCHIVE				0x00000020
#define FILE_ATTRIBUTE_DEVICE				0x00000040
#define FILE_ATTRIBUTE_NORMAL				0x00000080
#define FILE_ATTRIBUTE_TEMPORARY			0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE			0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT			0x00000400
#define FILE_ATTRIBUTE_COMPRESSED			0x00000800
#define FILE_ATTRIBUTE_OFFLINE				0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED		0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED			0x00004000
#define FILE_ATTRIBUTE_INTEGRITY_STREAM			0x00008000
#define FILE_ATTRIBUTE_VIRTUAL				0x00010000
#define FILE_ATTRIBUTE_NO_SCRUB_DATA			0x00020000
#define FILE_ATTRIBUTE_EA				0x00040000
#define FILE_ATTRIBUTE_PINNED				0x00080000
#define FILE_ATTRIBUTE_UNPINNED				0x00100000
#define FILE_ATTRIBUTE_RECALL_ON_OPEN			0x00040000
#define FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS		0x00400000
#endif//

// Xanadu Filesystem Time
typedef struct _XANADU_FILESYSTEM_TIME
{
	int32U			_Sec;				// 秒数		[0,59]
	int32U			_Min;				// 分钟		[0,59]
	int32U			_Hour;				// 小时		[0,23]
	int32U			_Day;				// 天数		[1,31]
	int32U			_Month;				// 月份		[0,11]
	int32U			_Year;				// 年份		[1980..2044]

	_XANADU_FILESYSTEM_TIME()
	{
		this->_Sec = 0;
		this->_Min = 0;
		this->_Hour = 0;
		this->_Day = 1;
		this->_Month = 0;
		this->_Year = 1970;
	};
}XANADU_FILESYSTEM_TIME;


class XFileInfoPrivate;

// File information
class XANADU_CORE_EXPORT XFileInfo
{
private:
	// Private structures
	XFileInfoPrivate*			_Info;

public:
	// Overload _copy
	XFileInfo() noexcept;

	// Overload _copy
	XFileInfo(const XString& _Filepath) noexcept;

	// Overload _copy
	XFileInfo(const XFileInfo& _Fileinfo) noexcept;

	// Virtual destructor
	virtual ~XFileInfo() noexcept;

public:
	// Overload Operator =
	virtual XFileInfo& operator = (const XString& _Filepath) noexcept;

	// Overload Operator =
	virtual XFileInfo& operator = (const XFileInfo& _Fileinfo) noexcept;

	// operators overload =
	virtual XFileInfo& operator = (XFileInfo&& _Fileinfo) noexcept;

public:
	// Convert to an absolute path
	static XString ToAbsolutePath(const XString& _Filepath) noexcept;

	// Convert to an relative path
	static XString ToRelativePath(const XString& _Filepath) noexcept;

public:
	// Check if the file exists
	virtual bool exists() const noexcept;

	virtual XString filePath() const noexcept;

	virtual XString absoluteFilePath() const noexcept;

	virtual XString fileName() const noexcept;

	virtual XString baseName() const noexcept;

	virtual XString completeBaseName() const noexcept;

	virtual XString suffix() const noexcept;

	virtual XString completeSuffix() const noexcept;

	virtual XString path() const noexcept;

	virtual XString absolutePath() const noexcept;

	virtual XString dir() const noexcept;

	virtual XString absoluteDir() const noexcept;

	virtual bool isFile() const noexcept;

	virtual bool isDir() const noexcept;

	virtual int64S size() const noexcept;

public:
	// Check if the file exists
	static bool exists(const XString& _Filepath) noexcept;
};

#endif // _XANADU_CORE_FILEINFO_H_
