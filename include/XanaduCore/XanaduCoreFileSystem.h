//
// Created by Administrator on 2021/1/12.
//

/*
 * This file is an exception declaration for the Xanadu family
 * */

#ifndef			_XANADU_CORE_FILESYSTEM_H_
#define			_XANADU_CORE_FILESYSTEM_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>
#include <XanaduCore/XanaduCoreByteArray.h>
#include <XanaduCore/XanaduCoreFileInfo.h>

//Xanadu File System
class XANADU_CORE_EXPORT XFileSystem
{
public:
	XFileSystem() XANADU_NOTHROW;

	virtual ~XFileSystem() XANADU_NOTHROW;

public:
	/// 是否存在
	static bool PathIsExist(const XString& _Path) XANADU_NOTHROW;

	/// Path To Native(Windows:\)(MAC:/)(Linux:/)
	static XString PathToNative(const XString& _Path) XANADU_NOTHROW;

	/// 格式化
	static XString PathFormat(const XString& _Path) XANADU_NOTHROW;

	/// 是否是文件
	static bool PathIsFile(const XString& _Path) XANADU_NOTHROW;

	/// 是否是目录
	static bool PathIsDirectory(const XString& _Path) XANADU_NOTHROW;

	/// 名称是否正常
	static bool PathIsAllow(const XString& _Name) XANADU_NOTHROW;

	/// 路径获取目录
	static XString PathDirectory(const XString& _Path) XANADU_NOTHROW;

	/// 名称(是否有后缀)
	static XString PathName(const XString& _Path, bool _Suffix = true) XANADU_NOTHROW;

	/// 后缀
	static XString PathSuffix(const XString& _Path, bool _Dot = true) XANADU_NOTHROW;

	/// 后缀匹配
	static bool PathSuffixMatch(const XString& _Path, const XString& _Suffix) XANADU_NOTHROW;

	/// 修复	\/:*?"<>|
	static XString PathRepair(const XString& _Path) XANADU_NOTHROW;

	/// 修复空格
	static XString PathSpaceRepair(const XString& _Path) XANADU_NOTHROW;

	/// 路径:移除文件或目录
	static bool PathRemove(const XString& _Path, std::function<bool(XFileInfo _Info, bool _Success)> _Lambda = nullptr) XANADU_NOTHROW;

public:
	/// 是否存在
	static bool FileIsExist(const XString& _File) XANADU_NOTHROW;

	/// 文件:大小
	static int64S FileSize(const XString& _File) XANADU_NOTHROW;

	/// 文件:打开
	static HANDLE FileOpen(const XString& _File, const wchar_t* _Flags) XANADU_NOTHROW;

	/// 文件:跳转
	static bool FileSeek(HANDLE _Handle, int64S _Offset, int32S _Origin = SEEK_SET) XANADU_NOTHROW;

	/// 文件:偏移
	static int64S FileOffset(HANDLE _Handle) XANADU_NOTHROW;

	/// 文件:是否结尾
	static bool FileEof(HANDLE _Handle) XANADU_NOTHROW;

	/// 文件:读取
	static bool FileRead(HANDLE _Handle, void* _Buffer, int64S _Length) XANADU_NOTHROW;

	/// 文件:读取一行
	static XByteArray FileReadLine(HANDLE _Handle) XANADU_NOTHROW;

	/// 文件:写入
	static int64S FileRead(void* _Buffer, int64S _Size, int64S _Count, HANDLE _Handle) XANADU_NOTHROW;

	/// 文件:写入
	static bool FileWrite(HANDLE _Handle, const void* _Buffer, int64S _Length) XANADU_NOTHROW;

	/// 文件:写入
	static bool FileWrite(HANDLE _Handle, const XByteArray& _Buffer) XANADU_NOTHROW;

	/// 文件:写入
	static int64S FileWrite(const void* _Buffer, int64S _Size, int64S _Count, HANDLE _Handle) XANADU_NOTHROW;

	/// 文件:刷新缓存
	static bool FileFlush(HANDLE _Handle) XANADU_NOTHROW;

	/// 文件:关闭
	static bool FileClose(HANDLE _Handle) XANADU_NOTHROW;

	/// 文件:拷贝
	static bool FileCopy(const XString& _Source, const XString& _Target, std::function<bool(int64S _CurrentByte, int64S _FullByte)> _Lambda = nullptr) XANADU_NOTHROW;

	/// 文件:移动
	static bool FileMove(const XString& _Source, const XString& _Target, std::function<bool(int64S _CurrentByte, int64S _FullByte)> _Lambda = nullptr) XANADU_NOTHROW;

	/// 文件:删除
	static bool FileRemove(const XString& _File) XANADU_NOTHROW;

	/// 文件:重命名
	static bool FileRename(const XString& _NameOLD, const XString& _NameNEW) XANADU_NOTHROW;

	/// 文件:名称(是否有后缀)
	static XString FileName(const XString& _File, bool _Suffix = true) XANADU_NOTHROW;

	/// 文件:后缀
	static XString FileSuffix(const XString& _File) XANADU_NOTHROW;

	/// 文件:读取至缓存
	static XByteArray FileToBytes(const XString& _File) XANADU_NOTHROW;

	/// 文件:从缓存写入文件
	static bool FileFromBytes(const XString& _File, const void* _Data, int64S _Legnth) XANADU_NOTHROW;

	/// 文件:从缓存写入文件
	static bool FileFromBytes(const XString& _File, const XByteArray& _Data) XANADU_NOTHROW;

	/// 文件:大小转字符串
	static XString FileSizeToString(int64S vSize) XANADU_NOTHROW;

	/// 文件:从BASE64格式化
	static bool FileFromBase64(const XString& _File, const void* _BASE64, int64S _Length) XANADU_NOTHROW;

	/// 文件:从BASE64格式化
	static bool FileFromBase64(const XString& _File, const XByteArray& _BASE64) XANADU_NOTHROW;

public:
	/// 是否存在
	static bool DirectoryIsExist(const XString& _Directory) XANADU_NOTHROW;

	/// 目录:创建
	static bool DirectoryCreate(const XString& _Directory, int32S _Mode = 0755) XANADU_NOTHROW;

	/// 目录:遍历
	static bool DirectoryTraverse(const XString& _Directory, std::function<bool(const XFileInfo& _Info, int32S _Level)> _Lambda) XANADU_NOTHROW;

	/// 目录:列表
	static bool DirectoryList(const XString& _Directory, std::function<bool(const XFileInfo& _Info)> _Lambda) XANADU_NOTHROW;

	/// 目录:移除
	static bool DirectoryRemove(const XString& _Directory, std::function<bool(const XFileInfo& _Info, bool _Success)> _Lambda = nullptr) XANADU_NOTHROW;

	/// 目录:大小
	static int64S DirectorySize(const XString& _Directory, std::function<bool(const XFileInfo& _Info)> _Lambda = nullptr) XANADU_NOTHROW;

	/// 目录:拷贝
	static bool DirectoryCopy(const XString& _Source, const XString& _Target, std::function<bool(const XFileInfo& _Source, const XFileInfo& _Target, bool _Success)> _Lambda = nullptr) XANADU_NOTHROW;

	/// 目录:移动
	static bool DirectoryMove(const XString& _Source, const XString& _Target, std::function<bool(const XFileInfo& _Source, const XFileInfo& _Target, bool _Success)> _Lambda = nullptr) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_FILESYSTEM_H_
