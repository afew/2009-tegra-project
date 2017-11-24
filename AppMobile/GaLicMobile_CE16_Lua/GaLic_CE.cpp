//
// Program Start.
////////////////////////////////////////////////////////////////////////////////

#include "_StdAfx.h"




DWORD	g_dSystemVolume=0;
INT RegistryInit();
INT RegistryClose();


CMain*	g_pApp;

#if	_WIN32_WCE

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPTSTR, int)

#else

int main()

#endif
{
	INT			hr=0;
	HINSTANCE	hInst;
	CMain		appMain;


	hInst = GetModuleHandle(NULL);
	g_pApp = &appMain;


	RegistryInit();


	if(FAILED(appMain.Create(hInst)))
	{
		RegistryClose();
		return -1;
	}

	hr = appMain.Run();

	RegistryClose();

	return hr;
}












INT RegistryInit()
{
	HKEY	hKey;
	DWORD	dType;
	DWORD	dSize = sizeof(DWORD);
	DWORD	dVolum=0x00010000;			// Mute

	LONG hr = RegOpenKeyEx( HKEY_CURRENT_USER, _T("ControlPanel\\Volume"), 0, KEY_ALL_ACCESS, &hKey );

	if( ERROR_SUCCESS != hr )
		return -1;

	hr = RegQueryValueEx( hKey, _T("Screen"), NULL, &dType, (BYTE*)&g_dSystemVolume, &dSize );

	if( ERROR_SUCCESS != hr )
		return -1;


	hr = RegSetValueEx(hKey, _T("Screen"), NULL, REG_DWORD, (BYTE*)&dVolum, sizeof(DWORD));

	RegCloseKey( hKey );

	if( ERROR_SUCCESS != hr )
		return -1;


	typedef void (*Function)(void);
	Function	lpfnFunc = NULL;
	HINSTANCE	hCoreDll = LoadLibrary(TEXT("coredll.dll"));

	if (hCoreDll)
	{
		lpfnFunc = (Function)GetProcAddress(hCoreDll, _T("AudioUpdateFromRegistry"));

		if (lpfnFunc)
		{
			(lpfnFunc)();
		}

		FreeLibrary(hCoreDll);
	}

	return 0;
}



INT RegistryClose()
{
	HKEY	hKey;
	LONG hr = RegOpenKeyEx( HKEY_CURRENT_USER, _T("ControlPanel\\Volume"), 0, KEY_ALL_ACCESS, &hKey );

	if( ERROR_SUCCESS != hr )
		return -1;

	hr = RegSetValueEx(hKey, _T("Screen"), NULL, REG_DWORD, (BYTE*)&g_dSystemVolume, sizeof(DWORD));

	RegCloseKey( hKey );

	if( ERROR_SUCCESS != hr )
		return -1;


	typedef void (*Function)(void);
	Function	lpfnFunc = NULL;
	HINSTANCE	hCoreDll = LoadLibrary(TEXT("coredll.dll"));

	if (hCoreDll)
	{
		lpfnFunc = (Function)GetProcAddress(hCoreDll, _T("AudioUpdateFromRegistry"));

		if (lpfnFunc)
		{
			(lpfnFunc)();
		}

		FreeLibrary(hCoreDll);
	}

	return 0;
}