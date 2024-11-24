#include <windows.h>

char msg[255];

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	
	DWORD dwVersion = GetVersion();
	DWORD dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
	DWORD dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
	DWORD dwBuild = 0;
		
	if(dwVersion < (1<<31)){
		dwBuild = (DWORD)(HIWORD(dwVersion));
	} else {
		if (dwMajorVersion < 4)
			dwBuild = (DWORD)(HIWORD(dwVersion)) & (1<<15);
		else
			dwBuild = 0;
	}

	wsprintfA(msg, "Hello world \nVersion = %x\nMajorVersion = %d\nMinorVersion = %d\nBuild = %d",
		dwVersion, dwMajorVersion, dwMinorVersion, dwBuild);

	MessageBox(NULL, msg, "Windows Application", MB_OK | MB_ICONINFORMATION);

	return 0;
}
