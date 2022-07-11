
#include "h.h"
void rad::Rad_ExternalMsgHandler()
{
	wnd::i_wnd.hwnd = NULL;
	while (true) {

		if (wnd::i_wnd.hwnd == NULL && GetAsyncKeyState(MENU_KEY) & 1) {
			std::cout << "creating external window..\n";
			std::thread(wnd::Wnd_CreateWnd).detach();
		}
		Sleep(10);

	}
}
void rad::CG_DllEntry(HMODULE hModule, LPTHREAD_START_ROUTINE startAddr)
{
	hook* a = nullptr;
	

	while (!*(IDirect3DDevice9**)&dx->device)
		std::this_thread::sleep_for(100ms);
	
	std::thread(r::R_CheckStatus, hModule).detach();
	std::thread(Rad_ExternalMsgHandler).detach();
	std::cout << "hooked!\n\n";
	

	
}