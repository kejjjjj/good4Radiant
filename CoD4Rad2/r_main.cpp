#include "h.h"

LRESULT __stdcall r::CamWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	struct tagRECT Rect; // [esp+8h] [ebp-10h] BYREF

	GetClientRect(hWnd, &Rect);
	if (Msg >= WM_SETFOCUS)
	{
		if (Msg <= WM_KILLFOCUS)
		{
			SendMessageA(hWnd, WM_NCACTIVATE, Msg == 7, 0);
			return 0;
		}
		if (Msg == WM_NCCALCSIZE)
		{
			DefWindowProcA(hWnd, WM_NCCALCSIZE, wParam, lParam);
			return 768;
		}
	}
	switch (Msg) {
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

	return DefWindowProcA(hWnd, Msg, wParam, lParam);
}

LRESULT CALLBACK r::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	
	

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam)) {
		//vars::guizmo::give_imgui_mouse = false;
		return true;
	}
	
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