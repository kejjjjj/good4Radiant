
#include "h.h"
void rad::Rad_ExternalMsgHandler()
{
	wnd::i_wnd.hwnd = NULL;
	while (true) {


		*rad::g_nUpdateBits = W_CAMERA | W_XY | W_XZ | W_YZ;

		Sleep(50);
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
	
	memcpy(gridSizes, (float*)0x06DDE5C, 44);
	memcpy(g_commands, (SCommandInfo*)0x73B240, sizeof(g_commands)); //surfaceinspector -> index 23

	a->install(0x426770, r::OnCameraRight);
	a->install(0x426720, r::OnCameraLeft);
	a->install(0x4266B0, r::OnCameraForward);
	a->install(0x426610, r::OnCameraBack);
	a->install(0x402D90, r::CamWndProc);
	MainFrame_OnKeyDown_f =  (MainFrame_OnKeyDown_hook)a->install(0x422370, MainFrame_OnKeyDown);


	Drag_MouseMoved_f = (Drag_MouseMoved_h)a->install(0x47FF30, Drag_MouseMoved);

	//a->install(0x403160, ccamwnd::on_lbutton_down);

	a->nop(0x53B2C3); //shader constants..
}