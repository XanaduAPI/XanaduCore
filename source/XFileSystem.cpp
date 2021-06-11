#include <XanaduCore/XFileSystem.h>
#include <XanaduCore/XSystem.h>
#include <XanaduCore/XStream.h>
#include <XanaduCore/XBase64.h>

#define			XANADU_FILESYSTEM_REMOVE_SUFFIX					L".xrm"

//
XFileSystem::XFileSystem() noexcept
{
}

//
XFileSystem::~XFileSystem() noexcept
{
}


// 路径:是否存在
bool XFileSystem::PathIsExist(const XString& _Path) noexcept
{
	if(_Path.empty())
	{
		return false;
	}
	return XFileInfo::exists(_Path);
}

// Path To Native(Windows:\)(MAC:/)(Linux:/)
XString XFileSystem::PathToNative(const XString& _Path) noexcept
{
	auto		vNativePath = _Path;
	for (XString::size_type vIndex = 0U; vIndex < vNativePath.size(); ++vIndex)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		if (vNativePath[vIndex] == L'/')
		{
			vNativePath[vIndex] = L'\\';
		}
#else
		if(vNativePath[vIndex] == L'\\')
		{
			vNativePath[vIndex] = L'/';
		}
#endif
	}
	return vNativePath;
}

// 格式化
XString XFileSystem::PathFormat(const XString& _Path) noexcept
{
	auto		vNewPath = _Path;
	vNewPath.replace(L"\\", L"/");
	if(vNewPath.exist() && vNewPath.at(vNewPath.size() - 1) == L'/')
	{
		vNewPath = vNewPath.left(vNewPath.size() - 1);
	}
	return vNewPath;
}

// 路径:是否是文件
bool XFileSystem::PathIsFile(const XString& _Path) noexcept
{
	XFileInfo	vFileInfo(XFileSystem::PathFormat(_Path));
	return vFileInfo.isFile();
}

// 路径:是否是目录
bool XFileSystem::PathIsDirectory(const XString& _Path) noexcept
{
	XFileInfo	vFileInfo(XFileSystem::PathFormat(_Path));
	return vFileInfo.isDir();
}

// 名称是否正常
bool XFileSystem::PathIsAllow(const XString& _Name) noexcept
{
	auto		vFullPath = XSystem::UserHome() + L"/" + _Name;
	auto		vHandle = XFileSystem::FileOpen(vFullPath, L"wb");
	if(vHandle)
	{
		XFileSystem::FileClose(vHandle);
		XFileSystem::FileRemove(vFullPath);
		return true;
	}
	return false;
}

// 路径获取目录
XString XFileSystem::PathDirectory(const XString& _Path) noexcept
{
	auto			vFullPath = XFileSystem::PathFormat(_Path);
	auto			vPos = vFullPath.rfind(L'/');
	if(vPos != XString::npos)
	{
		return _Path.substr(0ULL, vPos);
	}
	return L"";
}

// 获取名称
XString XFileSystem::PathName(const XString& _Path, bool _Suffix) noexcept
{
	auto		vNPATH = XFileSystem::PathFormat(_Path);
	auto		vPOS = vNPATH.rfind(L"/");
	if(vPOS != XString::npos)
	{
		auto	vName = vNPATH.right(vNPATH.size() - vPOS - 1);
		if(_Suffix)
		{
			return vName;
		}
		vPOS = vName.rfind(L".");
		if(vPOS > 0)
		{
			vName = vName.left(vPOS);
		}
		return vName;
	}
	else
	{
		return vNPATH;
	}
}

// 后缀
XString XFileSystem::PathSuffix(const XString& _Path, bool _Dot) noexcept
{
	auto		vName = XFileSystem::PathName(_Path);
	auto		vPOS = vName.rfind(L".");
	if(vPOS > 0ULL)
	{
		auto	vSuffix = vName.right(vName.size() - vPOS - (_Dot ? 0ULL : 1ULL));
		return vSuffix;
	}
	else
	{
		return L"";
	}
}

// 后缀匹配
bool XFileSystem::PathSuffixMatch(const XString& _Path, const XString& _Suffix) noexcept
{
	if(_Path.length() >= _Suffix.length())
	{
		auto	vSub = _Path.substr(_Path.length() - _Suffix.length());
		if(0 == vSub.compare(_Suffix, Xanadu::CaseInsensitive))
		{
			return true;
		}
	}
	return false;
}

// 修复	\/:*?"<>|
XString XFileSystem::PathRepair(const XString& _Path) noexcept
{
	auto		vPathNEW = _Path;
	auto		vPos = vPathNEW.rfind(L'/');
	for(auto vIndex = vPos; vIndex < vPathNEW.size(); ++vIndex)
	{
		switch(_Path[vIndex])
		{
			//\/:*?"<>|
			case L':':
			case L'*':
			case L'?':
			case L'\"':
			case L'<':
			case L'>':
			case L'|':
				vPathNEW[vIndex] = L'_';
				break;
			default:
				break;
		}
	}
	return vPathNEW;
}

// 修复空格
XString XFileSystem::PathSpaceRepair(const XString& _Path) noexcept
{
	if(_Path.contains(L" "))
	{
		return XString(L"\"") + _Path + XString(L"\"");
	}
	return _Path;
}

// 路径:移除文件或目录
bool XFileSystem::PathRemove(const XString& _Path, std::function<bool(XFileInfo _Info, bool _Success)> _Lambda) noexcept
{
	if (XFileSystem::PathIsFile(_Path))
	{
		return XFileSystem::FileRemove(_Path);
	}
	else
	{
		return XFileSystem::DirectoryRemove(_Path, _Lambda);
	}
}






// 是否存在
bool XFileSystem::FileIsExist(const XString& _File) noexcept
{
	if(_File.empty())
	{
		return false;
	}
	return XFileSystem::PathIsFile(_File) && XFileInfo::exists(_File);
}

// 文件:大小
int64S XFileSystem::FileSize(const XString& _File) noexcept
{
	auto		vHandle = XFileInfo(XFileSystem::PathFormat(_File));
	return vHandle.size();
}

// 文件:打开
HANDLE XFileSystem::FileOpen(const XString& _File, const wchar_t* _Flags) noexcept
{
	if(_Flags)
	{
		auto		vFile = XFileSystem::PathFormat(_File);
		return Xanadu::wfopen(vFile.data(), _Flags);
	}
	else
	{
		return nullptr;
	}
}

// 跳转
bool XFileSystem::FileSeek(HANDLE _Handle, int64S _Offset, int32S _Origin) noexcept
{
	if(_Handle)
	{
		return 0 == Xanadu::fseek(static_cast<FILE*>(_Handle), _Offset, _Origin);
	}
	else
	{
		return false;
	}
}

// 偏移
int64S XFileSystem::FileOffset(HANDLE _Handle) noexcept
{
	if(_Handle)
	{
		return Xanadu::ftell(static_cast<FILE*>(_Handle));
	}
	return -1;
}

// 文件:是否结尾
bool XFileSystem::FileEof(HANDLE _Handle) noexcept
{
	if(_Handle)
	{
		return Xanadu::feof(static_cast<FILE*>(_Handle));
	}
	else
	{
		return false;
	}
}

// 文件:读取
bool XFileSystem::FileRead(HANDLE _Handle, void* _Buffer, int64U _Length) noexcept
{
	if(_Handle)
	{
		return Xanadu::fread(static_cast<FILE*>(_Handle), _Buffer, static_cast<size_t>(_Length));
	}
	else
	{
		return false;
	}
}

// 文件:读取一行
XByteArray XFileSystem::FileReadLine(HANDLE _Handle) noexcept
{
	auto		vBytes = XByteArray();
	auto		vBuffer = XANADU_NEW char[XANADU_SIZE_MB];
	if(vBuffer)
	{
		if(Xanadu::fgets(vBuffer, XANADU_SIZE_MB - 2, static_cast<FILE*>(_Handle)))
		{
			vBytes = XByteArray(vBuffer, Xanadu::strlen(vBuffer));
		}
		XANADU_DELETE_ARR(vBuffer);
	}
	return vBytes;
}

// 文件:读取
int64U XFileSystem::FileRead(void* _Buffer, int64U _Size, int64U _Count, HANDLE _Handle) noexcept
{
	if(_Handle)
	{
		return Xanadu::fread(_Buffer, static_cast<size_t>(_Size), static_cast<size_t>(_Count), static_cast<FILE*>(_Handle));
	}
	return false;
}

// 文件:写入
bool XFileSystem::FileWrite(HANDLE _Handle, const void* _Buffer, int64U _Length) noexcept
{
	if(_Handle)
	{
		return Xanadu::fwrite(static_cast<FILE*>(_Handle), _Buffer, static_cast<size_t>(_Length));
	}
	return false;
}

// 文件:写入
bool XFileSystem::FileWrite(HANDLE _Handle, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	if(_Handle && _Buffer.exist())
	{
		return XFileSystem::FileWrite(_Handle, _Buffer.data(), _Buffer.size());
	}
	return false;
}

// 文件:写入
int64U XFileSystem::FileWrite(const void* _Buffer, int64U _Size, int64U _Count, HANDLE _Handle) noexcept
{
	if(_Handle)
	{
		return Xanadu::fwrite(_Buffer, static_cast<size_t>(_Size), static_cast<size_t>(_Count), static_cast<FILE*>(_Handle));
	}
	return 0ULL;
}

// 文件:刷新缓存
bool XFileSystem::FileFlush(HANDLE _Handle) noexcept
{
	if(_Handle)
	{
		return 0 == Xanadu::fflush(static_cast<FILE*>(_Handle));
	}
	return false;
}

// 文件:关闭
bool XFileSystem::FileClose(HANDLE _Handle) noexcept
{
	if(_Handle)
	{
		return 0 == Xanadu::fclose(static_cast<FILE*>(_Handle));
	}
	return false;
}

// 文件:拷贝
bool XFileSystem::FileCopy(const XString& _Source, const XString& _Target, std::function<bool(int64U _CurrentByte, int64U _FullByte)> _Lambda) noexcept
{
	XANADU_UNPARAMETER(_Lambda);

	auto		vFSource = XFileSystem::PathFormat(_Source);
	auto		vFTarget = XFileSystem::PathFormat(_Target);
	XFileSystem::FileRemove(vFTarget);
#if defined(_XANADU_SYSTEM_WINDOWS)
	if(::CopyFileW(vFSource.data(), vFTarget.data(), FALSE))
	{
		return true;
	}
#endif
	return 0 == Xanadu::wfcopy(vFSource.data(), vFTarget.data());
}

// 文件:移动
bool XFileSystem::FileMove(const XString& _Source, const XString& _Target, std::function<bool(int64U _CurrentByte, int64U _FullByte)> _Lambda) noexcept
{
	XANADU_UNPARAMETER(_Lambda);

	auto		vFormatSource = XFileSystem::PathFormat(_Source);
	auto		vFormatTarget = XFileSystem::PathFormat(_Target);
	XFileSystem::FileRemove(vFormatTarget);
	if(XFileSystem::FileRename(vFormatSource, vFormatTarget))
	{
		return true;
	}
	else
	{
		if(XFileSystem::FileCopy(vFormatSource, vFormatTarget))
		{
			return XFileSystem::FileRemove(vFormatSource);
		}
		return false;
	}
}

// 文件:删除
bool XFileSystem::FileRemove(const XString& _File) noexcept
{
	if (XFileSystem::FileIsExist(_File))
	{
		auto		vFile = XFileSystem::PathFormat(_File);
		if(0 == Xanadu::wremove(vFile.data()))
		{
			return true;
		}
		else
		{
#if defined(_XANADU_SYSTEM_WINDOWS)
			if(::DeleteFileW(vFile.data()))
			{
				return true;
			}
#endif
			return XFileSystem::FileRename(vFile, vFile + XANADU_FILESYSTEM_REMOVE_SUFFIX);
		}
	}
	return true;
}

// 文件:重命名
bool XFileSystem::FileRename(const XString& _NameOLD, const XString& _NameNEW) noexcept
{
	XFileSystem::FileRemove(_NameNEW);

	auto		vFileOLD = XFileSystem::PathFormat(_NameOLD);
	auto		vFileNEW = XFileSystem::PathFormat(_NameNEW);
	if(0 == Xanadu::wrename(vFileOLD.data(), vFileNEW.data()))
	{
		return true;
	}
	else
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		if(::MoveFileW(vFileOLD.data(), vFileNEW.data()))
		{
			return true;
		}
#endif
		return false;
	}
}

// 文件:名称(是否有后缀)
XString XFileSystem::FileName(const XString& _File, bool _Suffix) noexcept
{
	auto		vHandle = XFileInfo(XFileSystem::PathFormat(_File));
	if(_Suffix)
	{
		return vHandle.fileName();
	}
	else
	{
		return vHandle.baseName();
	}
}

// 文件:后缀
XString XFileSystem::FileSuffix(const XString& _File) noexcept
{
	auto		vHandle = XFileInfo(XFileSystem::PathFormat(_File));
	return vHandle.completeSuffix();
}

// 文件:读取至缓存
XByteArray XFileSystem::FileToBytes(const XString& _File) noexcept
{
	auto		vBytes = XByteArray();
	auto		vSize = XFileSystem::FileSize(_File);
	auto		vHandle = XFileSystem::FileOpen(_File, L"rb");
	if(vHandle && vSize > 0ULL)
	{
		auto		vSize32 = static_cast<size_t>(vSize);
		auto		vBuffer = XANADU_NEW char[vSize32];
		if (vBuffer)
		{
			if(XFileSystem::FileRead(vHandle, vBuffer, vSize))
			{
				vBytes = XByteArray(vBuffer, static_cast<XByteArray::size_type>(vSize));
			}
			XANADU_DELETE_ARR(vBuffer);
		}
		XFileSystem::FileClose(vHandle);
	}
	return vBytes;
}

// 文件:从缓存写入文件
bool XFileSystem::FileFromBytes(const XString& _File, const void* _Data, int64U _Legnth) noexcept
{
	auto		vSync = false;
	if(_Data && _Legnth > 0ULL)
	{
		auto		vHandle = XFileSystem::FileOpen(_File, L"wb");
		if(vHandle)
		{
			vSync = XFileSystem::FileWrite(vHandle, _Data, _Legnth);
			XFileSystem::FileClose(vHandle);
		}
	}
	return vSync;
}

// 文件:从缓存写入文件
bool XFileSystem::FileFromBytes(const XString& _File, const XByteArray& _Data) noexcept
{
	return XFileSystem::FileFromBytes(_File, _Data.data(), _Data.size());
}

// 文件:大小转字符串
XString XFileSystem::FileSizeToString(int64U vSize) noexcept
{
	double		vDivision = 1024.0f;
	wchar_t		vBuffer[XANADU_PATH] = { 0 };
	if(vSize > 1024)
	{
		auto		vFileSize = (double)vSize;
		vFileSize /= vDivision;
		if(vFileSize > vDivision)
		{
			vFileSize /= vDivision;
			if(vFileSize > vDivision)
			{
				vFileSize /= vDivision;
				if(vFileSize > vDivision)
				{
					swprintf(vBuffer, XANADU_PATH, L"%.2fTB", vFileSize);
				}
				else
				{
					swprintf(vBuffer, XANADU_PATH, L"%.2fGB", vFileSize);
				}
			}
			else
			{
				swprintf(vBuffer, XANADU_PATH, L"%.2fMB", vFileSize);
			}
		}
		else
		{
			swprintf(vBuffer, XANADU_PATH, L"%.2fKB", vFileSize);
		}
	}
	else
	{
		swprintf(vBuffer, XANADU_PATH, L"%lldB", vSize);
	}
	return vBuffer;
}

// 文件:从BASE64格式化
bool XFileSystem::FileFromBase64(const XString& _File, const void* _BASE64, int64U _Length) noexcept
{
	auto		vSync = false;
	if(_BASE64 && _Length > 0ULL)
	{
		auto		vData = XBase64::decode(_BASE64, _Length);
		if(vData.exist())
		{
			auto	vHandle = XFileSystem::FileOpen(XFileSystem::PathFormat(_File), L"wb");
			if(vHandle)
			{
				vSync = XFileSystem::FileWrite(vHandle, vData.data(), vData.size());
				XFileSystem::FileClose(vHandle);
			}
		}
	}
	return vSync;
}

// 文件:从BASE64格式化
bool XFileSystem::FileFromBase64(const XString& _File, const XByteArray& _BASE64) noexcept
{
	return XFileSystem::FileFromBase64(_File, _BASE64.data(), _BASE64.size());
}





// 回调
bool XANADUAPI FunctionTraverseDirectoryW(const XANADU_RUNTIME_FILE_INFO_W* _FileInfo, void* _UserData)
{
	XANADU_CHECK_RETURN(_FileInfo, false);
	XANADU_CHECK_RETURN(_UserData, false);

	auto		vArray = static_cast<std::vector<XString>*>(_UserData);
	if(0 == Xanadu::wcscmp(_FileInfo->name, L".") || 0 == Xanadu::wcscmp(_FileInfo->name, L".."))
	{
		return true;
	}
	vArray->push_back(_FileInfo->path);
	return true;
};

std::vector<XString> XanaduRuntimeDirectoryTraverse(const XString& _Directory)
{
	auto		vDirectory = XFileSystem::PathFormat(_Directory);
	auto		vPathArray = std::vector<XString>();
	Xanadu::wtraversedir(vDirectory.data(), FunctionTraverseDirectoryW, &vPathArray);
	return vPathArray;
};

// 是否存在
bool XFileSystem::DirectoryIsExist(const XString& _Directory) noexcept
{
	auto		vFileInfo = XFileInfo(XFileSystem::PathFormat(_Directory));
	if (vFileInfo.exists() && vFileInfo.isDir())
	{
		return true;
	}
	return false;
}

// 目录:创建
bool XFileSystem::DirectoryCreate(const XString& _Directory, int32S _Mode) noexcept
{
	auto		vDirectory = XFileSystem::PathFormat(_Directory);
	return 0 == Xanadu::wmkpath(vDirectory.data(), _Mode);
}

// 目录:遍历:实现
bool AchieveDirectoryTraverse(const XString& _Directory, int32S _Level, std::function<bool(const XFileInfo& _File, int32S _Level)> _Lambda) noexcept
{
	// 路径不存在，则返回false
	if(!XFileSystem::DirectoryIsExist(_Directory))
	{
		return false;
	}

	auto			vSync = true;
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
	for(auto vIndex = 0ULL; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(static_cast<size_t>(vIndex)));
		if(vItemInfo.isDir())
		{
			vSync = AchieveDirectoryTraverse(vItemInfo.filePath(), ++_Level, _Lambda);
		}
		if(vSync && _Lambda)
		{
			vSync = _Lambda(vItemInfo, _Level);
		}
	}
	return vSync;
}

// 目录:遍历
bool XFileSystem::DirectoryTraverse(const XString& _Directory, std::function<bool(const XFileInfo& _Info, int32S _Level)> _Lambda) noexcept
{
	return AchieveDirectoryTraverse(_Directory, 1, _Lambda);
}

// 目录:列表
bool XFileSystem::DirectoryList(const XString& _Directory, std::function<bool(const XFileInfo& _Info)> _Lambda) noexcept
{
	// 路径不存在，则返回false
	if(!XFileSystem::DirectoryIsExist(_Directory))
	{
		return false;
	}

	auto		vSync = true;
	auto		vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
	for(auto vIndex = 0ULL; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = vArrayInfo.at(static_cast<size_t>(vIndex));
		if(vSync && _Lambda)
		{
			vSync = _Lambda(vItemInfo);
		}
	}
	return vSync;
}

// 目录:移除
bool XFileSystem::DirectoryRemove(const XString& _Directory, std::function<bool(const XFileInfo& _Info, bool _Success)> _Lambda) noexcept
{
	// 路径不存在，则返回false
	if(!XFileSystem::DirectoryIsExist(_Directory))
	{
		return false;
	}

	auto		vSync = true;
	auto		vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(vIndex));
		if(vItemInfo.isFile())
		{
			vSync = XFileSystem::FileRemove(vItemInfo.filePath());
		}
		else
		{
			vSync = XFileSystem::DirectoryRemove(vItemInfo.filePath(), _Lambda);
		}
		if(vSync && _Lambda)
		{
			vSync = _Lambda(vItemInfo, vSync);
		}
	}
	if(vSync)
	{
		vSync = (0 == Xanadu::wrmdir(_Directory.data()));
	}
	return vSync;
}

// 目录:大小
int64S XFileSystem::DirectorySize(const XString& _Directory, std::function<bool(const XFileInfo& _Info)> _Lambda) noexcept
{
	if(!XFileSystem::DirectoryIsExist(_Directory))
	{
		return 0;
	}

	auto		vSize = 0LL;
	auto		vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
	for(auto & vIndex : vArrayInfo)
	{
		auto		vItemInfo = XFileInfo(vIndex);
		if(vItemInfo.isFile())
		{
			vSize += XFileSystem::FileSize(vItemInfo.filePath());
		}
		else
		{
			vSize += XFileSystem::DirectorySize(vItemInfo.filePath(), _Lambda);
		}
		if(_Lambda)
		{
			if(!_Lambda(vItemInfo))
			{
				break;
			}
		}
	}
	return vSize;
}

// 目录:拷贝
bool XFileSystem::DirectoryCopy(const XString& _Source, const XString& _Target, std::function<bool(const XFileInfo& _Source, const XFileInfo& _Target, bool _Success)> _Lambda) noexcept
{
	if(!XFileSystem::DirectoryIsExist(_Source))
	{
		return false;
	}

	auto		vSync = true;
	auto		vFTarget = XFileSystem::PathFormat(_Target);
	if(!XFileSystem::DirectoryCreate(_Target))
	{
		return false;
	}
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Source);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(vIndex));
		auto		vTargetPath = vFTarget + L"/" + vItemInfo.fileName();
		if(vItemInfo.isFile())
		{
			vSync = XFileSystem::FileCopy(vItemInfo.filePath(), vTargetPath);
		}
		else
		{
			vSync = XFileSystem::DirectoryCopy(vItemInfo.filePath(), vTargetPath, _Lambda);
		}
		if(vSync && _Lambda)
		{
			vSync = _Lambda(vItemInfo, XFileInfo(vTargetPath), vSync);
		}
	}
	return vSync;
}

// 目录:移动
bool XFileSystem::DirectoryMove(const XString& _Source, const XString& _Target, std::function<bool(const XFileInfo& _Source, const XFileInfo& _Target, bool _Success)> _Lambda) noexcept
{
	if(!XFileSystem::DirectoryIsExist(_Source))
	{
		return false;
	}

	auto		vSync = true;
	auto		vFTarget = XFileSystem::PathFormat(_Target);
	if(!XFileSystem::DirectoryCreate(_Target))
	{
		return false;
	}
	auto		vArrayInfo = XanaduRuntimeDirectoryTraverse(_Source);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(vIndex));
		auto		vTargetPath = vFTarget + L"/" + vItemInfo.fileName();
		if(vItemInfo.isFile())
		{
			vSync = XFileSystem::FileMove(vItemInfo.filePath(), vTargetPath);
		}
		else
		{
			vSync = XFileSystem::DirectoryMove(vItemInfo.filePath(), vTargetPath, _Lambda);
		}
		if(vSync && _Lambda)
		{
			vSync = _Lambda(vItemInfo, XFileInfo(vTargetPath), vSync);
		}
	}
	if(vSync)
	{
		vSync = (0 == Xanadu::wrmdir(_Source.data()));
	}
	return vSync;
}
