#include <XanaduCore/XFileSystem.h>
#include <XanaduCore/XSystem.h>
#include <XanaduCore/XStream.h>
#include <XanaduCore/XBase64.h>

#define				XANADU_FILESYSTEM_REMOVE_SUFFIX			L".xrm"

///
XFileSystem::XFileSystem() noexcept
{
}

///
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
	for (auto vIndex = 0; vIndex < vNativePath.size(); ++vIndex)
	{
#ifdef XANADU_SYSTEM_WINDOWS
		if (vNativePath[vIndex] == L'/')
		{
			vNativePath[vIndex] = L'\\';
		}
#else
		if(vNativePath[vIndex] == L'\\')
		{
			vNativePath[vIndex] = L'/';
		}
#endif // XANADU_SYSTEM_WINDOWS
	}
	return vNativePath;
}

// 格式化
XString XFileSystem::PathFormat(const XString& _Path) noexcept
{
	auto		vNewPath = _Path;
	vNewPath.replace(L"\\", L"/");
	if(vNewPath.size() > 0 && vNewPath.at(vNewPath.size() - 1) == L'/')
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
		return _Path.substr(0, vPos);
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
	if(vPOS > 0)
	{
		auto	vSuffix = vName.right(vName.size() - vPOS - (_Dot ? 0 : 1));
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
	XANADU_CHECK_RETURN(_Flags, nullptr);

	auto		vFile = XFileSystem::PathFormat(_File);
	return Xanadu::wfopen(vFile.data(), _Flags);
}

// 跳转
bool XFileSystem::FileSeek(HANDLE _Handle, int64S _Offset, int32S _Origin) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return 0 == Xanadu::fseek(static_cast<FILE*>(_Handle), _Offset, _Origin);
}

// 偏移
int64S XFileSystem::FileOffset(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, -1);

	return Xanadu::ftell(static_cast<FILE*>(_Handle));
}

// 文件:是否结尾
bool XFileSystem::FileEof(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return Xanadu::feof(static_cast<FILE*>(_Handle));
}

// 文件:读取
bool XFileSystem::FileRead(HANDLE _Handle, void* _Buffer, int64S _Length) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return Xanadu::fread(static_cast<FILE*>(_Handle), _Buffer, _Length);
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

// 文件:写入
int64S XFileSystem::FileRead(void* _Buffer, int64S _Size, int64S _Count, HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return Xanadu::fread(_Buffer, _Size, _Count, static_cast<FILE*>(_Handle));
}

// 文件:写入
bool XFileSystem::FileWrite(HANDLE _Handle, const void* _Buffer, int64S _Length) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return Xanadu::fwrite(static_cast<FILE*>(_Handle), _Buffer, _Length);
}

// 文件:写入
bool XFileSystem::FileWrite(HANDLE _Handle, const XByteArray& _Buffer) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	if(_Buffer.size())
	{
		return XFileSystem::FileWrite(_Handle, _Buffer.data(), _Buffer.size());
	}
	return false;
}

// 文件:写入
int64S XFileSystem::FileWrite(const void* _Buffer, int64S _Size, int64S _Count, HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return Xanadu::fwrite(_Buffer, _Size, _Count, static_cast<FILE*>(_Handle));
}

// 文件:刷新缓存
bool XFileSystem::FileFlush(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return 0 == Xanadu::fflush(static_cast<FILE*>(_Handle));
}

// 文件:关闭
bool XFileSystem::FileClose(HANDLE _Handle) noexcept
{
	XANADU_CHECK_RETURN(_Handle, false);

	return 0 == Xanadu::fclose(static_cast<FILE*>(_Handle));
}

// 文件:拷贝
bool XFileSystem::FileCopy(const XString& _Source, const XString& _Target, std::function<bool(int64S _CurrentByte, int64S _FullByte)> _Lambda) noexcept
{
	auto		vFormatSource = XFileSystem::PathFormat(_Source);
	auto		vFormatTarget = XFileSystem::PathFormat(_Target);
	XFileSystem::FileRemove(vFormatTarget);
#ifdef XANADU_SYSTEM_WINDOWS
	if(::CopyFileW(vFormatSource.data(), vFormatTarget.data(), FALSE))
	{
		return true;
	}
#endif // XANADU_SYSTEM_WINDOWS
	return 0 == Xanadu::wfcopy(vFormatSource.data(), vFormatTarget.data());
}

// 文件:移动
bool XFileSystem::FileMove(const XString& _Source, const XString& _Target, std::function<bool(int64S _CurrentByte, int64S _FullByte)> _Lambda) noexcept
{
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
			XANADU_INFO(L"[REMOVE] [%ls] SUCCESS", vFile.data());
			return true;
		}
		else
		{
#ifdef XANADU_SYSTEM_WINDOWS
			if(::DeleteFileW(vFile.data()))
			{
				XANADU_INFO(L"[REMOVE] [%ls] SUCCESS", vFile.data());
				return true;
			}
#endif // XANADU_SYSTEM_WINDOWS
			XANADU_ERROR(L"[REMOVE] [%ls] FAILURE", vFile.data());
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
#ifdef XANADU_SYSTEM_WINDOWS
		if(::MoveFileW(vFileOLD.data(), vFileNEW.data()))
		{
			return true;
		}
#endif // XANADU_SYSTEM_WINDOWS
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
	if(vHandle && vSize > 0)
	{
		auto		vSize32 = static_cast<unsigned int>(vSize);
		auto		vBuffer = XANADU_NEW char[vSize32];
		if (vBuffer)
		{
			if(XFileSystem::FileRead(vHandle, vBuffer, vSize))
			{
				vBytes = XByteArray(vBuffer, vSize);
			}
			XANADU_DELETE_ARR(vBuffer);
		}
		XFileSystem::FileClose(vHandle);
	}
	return vBytes;
}

// 文件:从缓存写入文件
bool XFileSystem::FileFromBytes(const XString& _File, const void* _Data, int64S _Legnth) noexcept
{
	XANADU_CHECK_RETURN(_Data, false);
	XANADU_CHECK_RETURN(_Legnth > 0, false);

	auto		vSync = false;
	auto		vHandle = XFileSystem::FileOpen(_File, L"wb");
	if(vHandle)
	{
		vSync = XFileSystem::FileWrite(vHandle, _Data, _Legnth);
		XFileSystem::FileClose(vHandle);
	}
	return vSync;
}

// 文件:从缓存写入文件
bool XFileSystem::FileFromBytes(const XString& _File, const XByteArray& _Data) noexcept
{
	return XFileSystem::FileFromBytes(_File, _Data.data(), _Data.size());
}

// 文件:大小转字符串
XString XFileSystem::FileSizeToString(int64S vSize) noexcept
{
	double		vDivision = 1024.0f;
	wchar_t		vBuffer[XANADU_PATH] = { 0 };
	if(vSize > 1024)
	{
		double		vFileSize = (double)vSize;
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
bool XFileSystem::FileFromBase64(const XString& _File, const void* _BASE64, int64S _Length) noexcept
{
	XANADU_CHECK_RETURN(_BASE64, false);
	XANADU_CHECK_RETURN(_Length > 0, false);

	auto		vResult = false;
	auto		vData = XBase64::decode(_BASE64, _Length);
	if(vData.size())
	{
		auto	vHandle = XFileSystem::FileOpen(XFileSystem::PathFormat(_File), L"wb");
		if(vHandle)
		{
			vResult = XFileSystem::FileWrite(vHandle, vData.data(), vData.size());
			XFileSystem::FileClose(vHandle);
		}
	}
	return vResult;
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
	if(false == XFileSystem::DirectoryIsExist(_Directory))
	{
		return false;
	}

	auto			vSync = true;
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(vIndex));
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
	if(false == XFileSystem::DirectoryIsExist(_Directory))
	{
		return false;
	}

	auto			vSync = true;
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = vArrayInfo.at(vIndex);
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
	if(false == XFileSystem::DirectoryIsExist(_Directory))
	{
		return false;
	}

	auto			vSync = true;
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
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
	if(false == XFileSystem::DirectoryIsExist(_Directory))
	{
		return 0;
	}

	auto			vSize = 0LL;
	auto			vSync = true;
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Directory);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size(); ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(vIndex));
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
	if(false == XFileSystem::DirectoryIsExist(_Source))
	{
		return false;
	}

	auto			vSync = true;
	auto			vFormatTarget = XFileSystem::PathFormat(_Target);
	if(!XFileSystem::DirectoryCreate(_Target))
	{
		return false;
	}
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Source);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(vIndex));
		auto		vTargetPath = vFormatTarget + L"/" + vItemInfo.fileName();
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
	if(false == XFileSystem::DirectoryIsExist(_Source))
	{
		return false;
	}

	auto			vSync = true;
	auto			vFormatTarget = XFileSystem::PathFormat(_Target);
	if(!XFileSystem::DirectoryCreate(_Target))
	{
		return false;
	}
	auto			vArrayInfo = XanaduRuntimeDirectoryTraverse(_Source);
	for(auto vIndex = 0U; vIndex < vArrayInfo.size() && vSync; ++vIndex)
	{
		auto		vItemInfo = XFileInfo(vArrayInfo.at(vIndex));
		auto		vTargetPath = vFormatTarget + L"/" + vItemInfo.fileName();
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
