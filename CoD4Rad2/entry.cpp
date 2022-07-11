// dllmain.cpp : Defines the entry point for the DLL application.
#include "h.h"

static bool hooked = false;
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    static bool once{ false };

    if (!once) {
        AllocConsole();
        FILE* fp;
        freopen_s(&fp, "CONOUT$", "w", stdout); //sets cout to be used with our newly created console
        Sleep(100);

        once = true;
    }

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if (!hooked) {
            std::cout << "hooking to: " << (LPTHREAD_START_ROUTINE)rad::CG_DllEntry << '\n';
            std::thread(rad::CG_DllEntry, hModule, (LPTHREAD_START_ROUTINE)rad::CG_DllEntry).detach();
            hooked = true;
        }
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

