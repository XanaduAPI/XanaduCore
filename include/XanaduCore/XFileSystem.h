/*
 * This file is an exception declaration for the Xanadu family
 * */

#ifndef			_XANADU_CORE_FILESYSTEM_H_
#define			_XANADU_CORE_FILESYSTEM_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>
#include <XanaduCore/XByteArray.h>
#include <XanaduCore/XFileInfo.h>

//Xanadu File system
class XANADU_CORE_EXPORT XFileSystem
{
public:
	XFileSystem() noexcept;

	virtual ~XFileSystem() noexcept;

public:
	// 是否存在
	static bool PathIsExist(const XString& _Path) noexcept;

	// Path To Native(Windows:\)(MAC:/)(Linux:/)
	static XString PathToNative(const XString& _Path) noexcept;

	// 格式化
	static XString PathFormat(const XString& _Path) noexcept;

	// 是否是文件
	static bool PathIsFile(const XString& _Path) noexcept;

	// 是否是目录
	static bool PathIsDirectory(const XString& _Path) noexcept;

	// 名称是否正常
	static bool PathIsAllow(const XString& _Name) noexcept;

	// 路径获取目录
	static XString PathDirectory(const XString& _Path) noexcept;

	// 名称(是否有后缀)
	static XString PathName(const XString& _Path, bool _Suffix = true) noexcept;

	// 后缀
	static XString PathSuffix(const XString& _Path, bool _Dot = true) noexcept;

	// 后缀匹配
	static bool PathSuffixMatch(const XString& _Path, const XString& _Suffix) noexcept;

	// 修复	\/:*?"<>|
	static XString PathRepair(const XString& _Path) noexcept;

	// 修复空格
	static XString PathSpaceRepair(const XString& _Path) noexcept;

	// 路径:移除文件或目录
	static bool PathRemove(const XString& _Path, std::function<bool(XFileInfo _Info, bool _Success)> _Lambda = nullptr) noexcept;

public:
	// 是否存在
	static bool FileIsExist(const XString& _File) noexcept;

	// 文件:大小
	static int64S FileSize(const XString& _File) noexcept;

	// 文件:打开
	static HANDLE FileOpen(const XString& _File, const wchar_t* _Flags) noexcept;

	// 文件:跳转
	static bool FileSeek(HANDLE _Handle, int64S _Offset, int32S _Origin = SEEK_SET) noexcept;

	// 文件:偏移
	static int64S FileOffset(HANDLE _Handle) noexcept;

	// 文件:是否结尾
	static bool FileEof(HANDLE _Handle) noexcept;

	// 文件:读取
	static bool FileRead(HANDLE _Handle, void* _Buffer, int64U _Length) noexcept;

	// 文件:读取一行
	static XByteArray FileReadLine(HANDLE _Handle) noexcept;

	// 文件:读取
	static int64U FileRead(void* _Buffer, int64U _Size, int64U _Count, HANDLE _Handle) noexcept;

	// 文件:写入
	static bool FileWrite(HANDLE _Handle, const void* _Buffer, int64U _Length) noexcept;

	// 文件:写入
	static bool FileWrite(HANDLE _Handle, const XByteArray& _Buffer) noexcept;

	// 文件:写入
	static int64U FileWrite(const void* _Buffer, int64U _Size, int64U _Count, HANDLE _Handle) noexcept;

	// 文件:刷新缓存
	static bool FileFlush(HANDLE _Handle) noexcept;

	// 文件:关闭
	static bool FileClose(HANDLE _Handle) noexcept;

	// 文件:拷贝
	static bool FileCopy(const XString& _Source, const XString& _Target, std::function<bool(int64U _CurrentByte, int64U _FullByte)> _Lambda = nullptr) noexcept;

	// 文件:移动
	static bool FileMove(const XString& _Source, const XString& _Target, std::function<bool(int64U _CurrentByte, int64U _FullByte)> _Lambda = nullptr) noexcept;

	// 文件:删除
	static bool FileRemove(const XString& _File) noexcept;

	// 文件:重命名
	static bool FileRename(const XString& _NameOLD, const XString& _NameNEW) noexcept;

	// 文件:名称(是否有后缀)
	static XString FileName(const XString& _File, bool _Suffix = true) noexcept;

	// 文件:后缀
	static XString FileSuffix(const XString& _File) noexcept;

	// 文件:读取至缓存
	static XByteArray FileToBytes(const XString& _File) noexcept;

	// 文件:从缓存写入文件
	static bool FileFromBytes(const XString& _File, const void* _Data, int64U _Legnth) noexcept;

	// 文件:从缓存写入文件
	static bool FileFromBytes(const XString& _File, const XByteArray& _Data) noexcept;

	// 文件:大小转字符串
	static XString FileSizeToString(int64U vSize) noexcept;

	// 文件:从BASE64格式化
	static bool FileFromBase64(const XString& _File, const void* _BASE64, int64U _Length) noexcept;

	// 文件:从BASE64格式化
	static bool FileFromBase64(const XString& _File, const XByteArray& _BASE64) noexcept;

public:
	// 是否存在
	static bool DirectoryIsExist(const XString& _Directory) noexcept;

	// 目录:创建
	static bool DirectoryCreate(const XString& _Directory, int32S _Mode = 0755) noexcept;

	// 目录:遍历
	static bool DirectoryTraverse(const XString& _Directory, std::function<bool(const XFileInfo& _Info, int32S _Level)> _Lambda) noexcept;

	// 目录:列表
	static bool DirectoryList(const XString& _Directory, std::function<bool(const XFileInfo& _Info)> _Lambda) noexcept;

	// 目录:移除
	static bool DirectoryRemove(const XString& _Directory, std::function<bool(const XFileInfo& _Info, bool _Success)> _Lambda = nullptr) noexcept;

	// 目录:大小
	static int64S DirectorySize(const XString& _Directory, std::function<bool(const XFileInfo& _Info)> _Lambda = nullptr) noexcept;

	// 目录:拷贝
	static bool DirectoryCopy(const XString& _Source, const XString& _Target, std::function<bool(const XFileInfo& _Source, const XFileInfo& _Target, bool _Success)> _Lambda = nullptr) noexcept;

	// 目录:移动
	static bool DirectoryMove(const XString& _Source, const XString& _Target, std::function<bool(const XFileInfo& _Source, const XFileInfo& _Target, bool _Success)> _Lambda = nullptr) noexcept;
};

#endif // _XANADU_CORE_FILESYSTEM_H_
