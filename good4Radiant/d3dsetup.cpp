#include "d3dsetup.h"
#include "functions.h"
#include <iostream>
namespace D3D {
	void hookEndScene() {
		HWND  window = game::g_qeglobals->d_hwndMain;
		oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);
		pD3D = Direct3DCreate9(D3D_SDK_VERSION); // create IDirect3D9 object
		pDevice = *(IDirect3DDevice9**)&game::dx->device;
		std::cout << "hook: " << &game::dx->device << '\n';
		//init_graphics();

		void** vTable = *reinterpret_cast<void***>(pDevice);

		pEndScene = (endScene)DetourFunction((PBYTE)vTable[42], (PBYTE)D3D_DRAW);
		//v_buffer->Release();
		pDevice->Release();
		pD3D->Release();
	}
	HRESULT hr = NULL;
	void ResetDevice()
	{


		if (font1)
			font1->OnLostDevice();
		if (font1out)
			font1out->OnLostDevice();
		if (d3dline)
			d3dline->OnLostDevice();



	}
#include "koukku.h"
	DWORD WINAPI Hook(HINSTANCE hModule)
	{

		hookEndScene();
		while (true) {
			if(game::dx->deviceLost)
				ResetDevice();

			Sleep(2000);
		}
	}
}