#include "d3dsetup.h"
#include "renderer.h"
#include "initGui.h"
#include <ctime>
#include "Utils.h"
#include "hooks.h"
void D3D::TextWithOutline(std::string p, D3DRECT rect, vec3_t color)
{
	RECT rectangle, rect2, rect3, rect4, rect5;
	const char* text = p.c_str();

	SetRect(&rect2, rect.x1 - 1, rect.y1, rect.x2, rect.y2);
	D3D::font1out->DrawText(NULL, text, -1, &rect2, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	SetRect(&rect3, rect.x1 + 1, rect.y1, rect.x2, rect.y2);
	D3D::font1out->DrawText(NULL, text, -1, &rect3, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	SetRect(&rect4, rect.x1, rect.y1 + 1, rect.x2, rect.y2);
	D3D::font1out->DrawText(NULL, text, -1, &rect4, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	SetRect(&rect5, rect.x1, rect.y1 - 1, rect.x2, rect.y2);
	D3D::font1out->DrawText(NULL, text, -1, &rect5, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	SetRect(&rectangle, rect.x1, rect.y1, rect.x2, rect.y2);
	D3D::font1->DrawText(NULL, text, -1, &rectangle, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, (int)color[0], (int)color[1], (int)color[2]));

}
void D3D::InitFonts()
{
	
	if (glob::qfontInitialized)
		return;

	game::Hooks();
	glob::qfontInitialized = true;

	ImGui::InitImgui();

	if (!font1 || !font1out) 
		Utils::RegisterFont("ProggyClean");
	
	printf("font\n");
}
LRESULT CALLBACK D3D::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (GetKeyState(MENU_TOGGLE) == 1) {
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		//if (GetAsyncKeyState(VK_HOME) & 1)
		//	Game::iPrintLn("^2Menu controls!");
		return 1l;
	}
	switch (uMsg) {
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	case WM_DESTROY:
		ImGui_ImplDX9_InvalidateDeviceObjects();
		//if (pDevice) 
		//	pDevice->Release();
		//if(pD3D)
		//	pD3D->Release();
		
		//MessageBox(NULL, "quit", "quit", 0);
		exit(1);
		::PostQuitMessage(1);
	}
	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool canRender;
HRESULT __stdcall D3D::D3D_DRAW(IDirect3DDevice9* pDevice) {

	if (!game::dx->device)
		return D3D::pEndScene(pDevice);

	InitFonts();

	ImGui::R_StartImGuiRender(&canRender);
	_3d::RenderThread();
	//TextWithOutline(std::to_string(game::g_qeglobals->d_numedges), D3DRECT{500, 500, 510, 510}, vec3_t{0,255,0});

	
	ImGui::R_EndImGuiRender(&canRender);
	return D3D::pEndScene(pDevice);
}
