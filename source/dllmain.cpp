#include <XanaduRuntime/Header.h>

bool XANADUAPI Xanadu_Runtime_Initialize() noexcept
{
	return true;
};

void XANADUAPI Xanadu_Runtime_Release() noexcept
{
};


#if defined(XANADU_SYSTEM_WINDOWS)
extern "C" BOOL WINAPI DllMain(HANDLE _HDllHandle, DWORD _Reason, LPVOID _Reserved)
{
	XANADU_UNPARAMETER(_HDllHandle);
	XANADU_UNPARAMETER(_Reserved);

	switch(_Reason)
	{
		case DLL_PROCESS_ATTACH:
			Xanadu_Runtime_Initialize();
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			Xanadu_Runtime_Release();
			break;
		default:
			break;
	}
	return TRUE;
}
#else
__attribute((constructor)) void _Xanadu_Runtime_Dynamic_Library_Init(void)
{
	Xanadu_Runtime_Initialize();
};

__attribute((destructor)) void _Xanadu_Runtime_Dynamic_Library_Fini(void)
{
	Xanadu_Runtime_Release();
};
#endif
