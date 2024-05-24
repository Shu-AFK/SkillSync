#ifndef SKILLSYNC_INJECTOR_H
#define SKILLSYNC_INJECTOR_H

#include <TlHelp32.h>
#include <Windows.h>
#include <iostream>
#include <fstream>

using f_LoadLibraryA	= HINSTANCE(WINAPI*)(const char* lpLibFilename);
using f_GetProcAddress	= UINT_PTR(WINAPI*)(HINSTANCE hModule, const char* lpProcName);
using f_DLL_ENTRY_POINT = BOOL(WINAPI*)(void* hDll, DWORD dwReason, void* pReserved);

struct MAPPING_DATA
{
    f_LoadLibraryA		pLoadLibraryA;
    f_GetProcAddress	pGetProcAddress;
    HINSTANCE			hMod;
};

bool ManualMap(HANDLE hProc, const char* szDllFile);

#endif //SKILLSYNC_INJECTOR_H
