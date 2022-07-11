#include "h.h"

void r::R_CreateFonts()
{
	if (font1 && font1out)
		return;

	if (!font1)
		D3DXCreateFontA(pDevice, 30, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &font1);
	if (!font1out)
		D3DXCreateFontA(pDevice, 30, 0, FW_NORMAL, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &font1out);

}

bool r::R_Init()
{
	pDevice = *(IDirect3DDevice9**)&rad::dx->device;
	HWND window = rad::g_qeglobals->d_hwndMain;
	//HWND hwnd = FindWindowA(NULL, glob::windowname);
	oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);
	if (!pDevice) {
		std::cout << "IDirect3DDevice9 nullptr!\n";
		return false;
	}
	std::cout << "IDirect3DDevice9 hooked!\n";
	pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	void** vTable = *reinterpret_cast<void***>(pDevice);

	pEndScene = (endScene)DetourFunction((PBYTE)vTable[42], (PBYTE)D3D_DRAW);

	pDevice->Release();
	pD3D->Release();

	return true;
}
bool r::R_ResetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	if (font1)
		font1->OnLostDevice();
	if (font1out)
		font1out->OnLostDevice();

	//ImGui_ImplDX9_CreateDeviceObjects();
	return true;
}
DWORD WINAPI r::R_CheckStatus(HINSTANCE hModule)
{

	if (!R_Init()) {
		MessageBox(NULL, "Could not initialize IDirect3DDevice9", "Error", 0);
		return 0;
	}

	R_InitImGUI();
	//CFG::parseConfigHeader();



	while (!false) {
		if (rad::dx->deviceLost) {
			std::cout << "device lost!\n";
			R_ResetDevice();
		}
		Sleep(500);


	}
	return true;
}

void r::R_InitImGUI()
{
	if (glob::ImGui_Init)
		return;

	glob::ImGui_Init = !glob::ImGui_Init;
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui_ImplWin32_Init(rad::g_qeglobals->d_hwndMain);
	ImGui_ImplDX9_Init(pDevice);
	ImFont* font = nullptr;

	std::string font_directory = "C:\\Windows\\Fonts\\Arial.ttf";

	io.Fonts->AddFontFromFileTTF((font_directory.c_str()), 12 * 2);
	io.Fonts->AddFontFromFileTTF((font_directory.c_str()), 10 * 2);
	io.Fonts->AddFontFromFileTTF((font_directory.c_str()), 14 * 2);
	io.Fonts->AddFontFromFileTTF((font_directory.c_str()), 18 * 2);
}