#pragma once

#ifndef deez
#define deez
#include "h.h"

struct imWindow
{
	ImVec2 resolution;
	ImVec2 size;
	ImVec2 pos;
	HWND hwnd;
};


namespace wnd
{
	// Data

		// Data
	static LPDIRECT3D9              g_pD3D = NULL;
	static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
	static D3DPRESENT_PARAMETERS    g_d3dpp = {};

	bool CreateDeviceD3D(HWND hWnd);
	void CleanupDeviceD3D();
	void ResetDevice();

	inline imWindow i_wnd;

	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void Wnd_CreateWnd();
	void Wnd_DestroyWnd();
	void Wnd_Style();

	bool Wnd_Features();
}

#endif