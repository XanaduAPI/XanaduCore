#include <XanaduCore/XanaduCore.h>

bool XANADUAPI Xanadu_Core_Initialize() noexcept
{
	return true;
};

void XANADUAPI Xanadu_Core_Release() noexcept
{
};

#ifdef XANADU_SYSTEM_WINDOWS
BOOL WINAPI DllMain(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved)
{
	XANADU_UNPARAMETER(_HDllHandle);
	XANADU_UNPARAMETER(_Reserved);

	BOOL	vResult = TRUE;
	switch(_Reason)
	{
		case DLL_PROCESS_ATTACH:
			Xanadu_Core_Initialize();
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			Xanadu_Core_Release();
			break;
		default:
			break;
	}
	return vResult;
}
#else
__attribute((constructor)) void Xanadu_Core_Dynamic_Library_Init(void)
{
	Xanadu_Core_Initialize();
};

__attribute((destructor)) void Xanadu_Core_Dynamic_Library_Fini(void)
{
	Xanadu_Core_Release();
};
#endif /// XANADU_SYSTEM_WINDOWS
