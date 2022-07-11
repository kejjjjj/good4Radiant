
#include "d3dsetup.h"
#include <iostream>

#define CreateThreadArg(func, arg) CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)func, (LPVOID)arg, NULL, NULL);
#define CreateThreadMin(func) CreateThreadArg(func, NULL);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD AreWeInside, LPVOID lpReserved)
{
	if (AreWeInside == true)
	{
		//AllocConsole();
		//FILE* fp;
		//freopen_s(&fp, "CONOUT$", "w", stdout); //sets cout to be used with our newly created console
		//Sleep(100);
		//printf("Hello console on\n");
		//std::cout.clear();
		//std::cout << "test string\n";
		switch (AreWeInside)
		{
		case DLL_PROCESS_ATTACH:
			CreateThreadMin(D3D::Hook)
				break;
		}

	}

	return 1;
}

