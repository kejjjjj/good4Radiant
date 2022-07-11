#pragma once
#ifndef directxs
#define directxs

//DIRECTX
#pragma warning(push)
#pragma warning(disable: 26495)
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9core.h>
#pragma warning(pop)

#include "detours/detours.h"

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "detours.lib")

//IMGUI
#include "../good4Radiant/imGui/imgui.h"
#include "../good4Radiant/imGui/imgui_impl_dx9.h"
#include "../good4Radiant/imGui/imgui_impl_win32.h"
#include "../good4Radiant/imGui/imgui_internal.h"

#include <Windows.h>
#include <cstdint>
#include <string>

#include "functions.h"

#define MENU_TOGGLE VK_END

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace D3D
{
	typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);
	inline IDirect3DDevice9* pDevice;
	inline IDirect3D9* pD3D;
	static D3DPRESENT_PARAMETERS    d3dpp = {};
	inline endScene pEndScene;

	inline LPD3DXLINE d3dline;
	inline LPDIRECT3DVERTEXBUFFER9 v_buffer;
	//extern void init_graphics(void);
	extern void hookEndScene();
	extern void ResetDevice(HRESULT hr);
	//extern void resetImgui();
	extern HRESULT __stdcall D3D_DRAW(IDirect3DDevice9* pDevice);
	extern DWORD WINAPI Hook(HINSTANCE hModule);
	inline WNDPROC oWndProc;
	typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
	extern LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	inline LPD3DXFONT font1, font1out;

	inline bool LostDevice = false;
}
#endif