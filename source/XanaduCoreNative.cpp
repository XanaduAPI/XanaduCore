#include <XanaduCore/XanaduCoreNative.h>
#include <XanaduCore/XanaduCoreMutex.h>

// Native platform variable declarations
#ifndef XANADU_SYSTEM_WINDOWS
std::map<DWORD, std::vector<MSG>>		_StaticMessageArray;			// 全局线程消息队列
XMutex						_StaticMessageMutex;			// 消息队列互斥量
#endif // XANADU_SYSTEM_WINDOWS

#ifndef XANADU_SYSTEM_WINDOWS
//从调用线程的消息队列里取得一个消息并将其放于指定的结构。
//此函数可取得与指定窗口联系的消息和由PostThreadMessage寄送的线程消息。
//此函数接收一定范围的消息值。GetMessage不接收属于其他线程或应用程序的消息。
//获取消息成功后，线程将从消息队列中删除该消息。
//函数会一直等待直到有消息到来才有返回值。
XANADU_CORE_EXPORT BOOL XANADUAPI GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
	XANADU_CHECK_RETURN(lpMsg, FALSE);

	while(!PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, PM_REMOVE))
	{
		Xanadu::msleep(1);
	};
	return TRUE;
}

//检查线程消息队列，并将该消息（如果存在）放于指定的结构
XANADU_CORE_EXPORT BOOL XANADUAPI PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
	XANADU_CHECK_RETURN(lpMsg, FALSE);

	auto			vThreadID = Xanadu::GetCurrentThreadId();
	auto			vFind = FALSE;
	XANADU_MUTEX_AUTO(_StaticMessageMutex);

	auto		vIterator = _StaticMessageArray.find(vThreadID);
	if(vIterator != _StaticMessageArray.end())
	{
		if(vIterator->second.size())
		{
			for(auto vIteratorArray = vIterator->second.begin(); vIteratorArray != vIterator->second.end(); ++vIteratorArray)
			{
				if(wMsgFilterMin <= vIteratorArray->message && vIteratorArray->message <= wMsgFilterMax)
				{
					vFind = TRUE;
					memcpy(lpMsg, &(*vIteratorArray), sizeof(MSG));

					switch(wRemoveMsg)
					{
						case PM_REMOVE:
							vIterator->second.erase(vIteratorArray);
							break;
						default:
							break;
					}
					break;
				}
			}
		}
		else
		{
			_StaticMessageArray.erase(vIterator);
		}
	}
	return vFind;
}

//将一个队列消息放入（寄送）到指定线程的消息队列里，不等待线程处理消息就返回
XANADU_CORE_EXPORT BOOL XANADUAPI PostThreadMessageW(DWORD _ThreadID, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	XANADU_MUTEX_AUTO(_StaticMessageMutex);

	auto		vIterator = _StaticMessageArray.find(_ThreadID);
	if(vIterator == _StaticMessageArray.end())
	{
		_StaticMessageArray.insert(std::map<DWORD, std::vector<MSG>>::value_type(_ThreadID, std::vector<MSG>()));
	}
	vIterator = _StaticMessageArray.find(_ThreadID);
	if(vIterator != _StaticMessageArray.end())
	{
		MSG	vMessage;
		Xanadu::memset(&vMessage, 0, sizeof(MSG));
		vMessage.message = Msg;
		vMessage.wParam = wParam;
		vMessage.lParam = lParam;

		vIterator->second.push_back(vMessage);
		return TRUE;
	}
	return FALSE;
}

#endif // XANADU_SYSTEM_WINDOWS

// 创建注册表项
XANADU_CORE_EXPORT bool PlatformRegeditCreate(HKEY _Key, const wchar_t* _SubKey)
{
#ifdef XANADU_SYSTEM_WINDOWS
	HKEY			vNewKey = NULL;
	::RegCreateKeyW(_Key, _SubKey, &vNewKey);
	if(vNewKey)
	{
		::RegCloseKey(vNewKey);
		return true;
	}
#endif//XANADU_SYSTEM_WINDOWS
	return false;
}
