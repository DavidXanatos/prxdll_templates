#include <Windows.h>

#include "proxydll.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        /* uncomment this if you want to syncronously load the original DLL and
           all of its export procs in DllMain. dangerous; risks dead-locking. */
        //proxy_dll_init(TRUE); 
        break;
    case DLL_PROCESS_DETACH:
        if (!lpReserved)
            proxy_dll_free();
        break;
    default:
        break;
    }
    return TRUE;
}