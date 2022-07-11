#include "h.h"

LRESULT CALLBACK r::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	//if (GetKeyState(MENU_KEY) == 1) {
	//	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
	//	//if (GetAsyncKeyState(VK_HOME) & 1)
	//	//	Game::iPrintLn("^2Menu controls!");
	//	return 1l;
	//}
	switch (uMsg) {
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	case WM_DESTROY:
		ImGui_ImplDX9_InvalidateDeviceObjects();
		FreeConsole();
		exit(1);
		::PostQuitMessage(1);
	}
	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}
HRESULT __stdcall r::D3D_DRAW(IDirect3DDevice9* pDevice) {

	R_CreateFonts();

	R_StartRender();

	R_Render3DWnd();

	R_EndRender();

	return pEndScene(pDevice);
}