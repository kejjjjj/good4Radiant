
#include "h.h"
void rad::Rad_ExternalMsgHandler()
{
	wnd::i_wnd.hwnd = NULL;
	while (true) {


		rad::selbrush_def_t* selected_brush = rad::g_selected_brushes();

		if (!selected_brush || selected_brush->facecount < 1)
			continue;

		vec3_t org;
		rad::GetBrushOrigin(selected_brush, org);

		if (GetAsyncKeyState(VK_PRIOR) & 1) {
			rad::g_select_move(org, vec3_t{ 0,90,0 }, vec3_t{ 0, 0, 32 });
			*rad::g_nUpdateBits |= W_CAMERA;
			std::cout << "update selection!\n";
		}
		Sleep(100);
	}
}
char OnCameraLeft(void* ye)
{
	std::cout << "camera left\n";
	return 1;
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

	a->install(0x426770, r::OnCameraRight);
	a->install(0x426720, r::OnCameraLeft);
	a->install(0x4266B0, r::OnCameraForward);
	a->install(0x426610, r::OnCameraBack);

	
}