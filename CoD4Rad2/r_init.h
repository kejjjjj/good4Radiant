#pragma once
#include "h.h"

#ifndef r_init
#define r_init
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace r
{
	typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);
	inline IDirect3DDevice9* pDevice;
	inline IDirect3D9* pD3D;
	static D3DPRESENT_PARAMETERS    d3dpp = {};
	inline endScene pEndScene;

	extern HRESULT __stdcall D3D_DRAW(IDirect3DDevice9* pDevice);

	inline WNDPROC oWndProc;
	typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
	extern LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	LRESULT __stdcall CamWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam); //hook

	inline LPD3DXFONT font1, font1out;

	void R_CreateFonts();
	bool R_Init();
	DWORD WINAPI R_CheckStatus(HINSTANCE hModule);
	bool R_ResetDevice();

	void R_InitImGUI();

	//inline std::vector<LPDIRECT3DTEXTURE9> tabs(20);
	//inline std::vector<const char*> imagepaths;

	//bool CreateTextures(std::vector<std::pair<const char*, LPDIRECT3DTEXTURE9>>& pair);
	//bool ReturnErrorCode(HRESULT result);
	namespace glob {
		inline bool ImGui_Init;
	}
}


#endif