#include "d3dsetup.h"
#include "initGui.h"
void ImGui::InitImgui()
{
	if (glob::init)
		return;

	glob::init = true;
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.WantCaptureMouse = true;
	//io.MouseDrawCursor = true;
	ImGui_ImplWin32_Init(game::g_qeglobals->d_hwndMain);
	ImGui_ImplDX9_Init(D3D::pDevice);
}
void ImGui::R_MenuToggle(bool b)
{
	if (b) {
		glob::drawmenu = false;
		return;
	}
	glob::drawmenu = true;
}
void ImGui::R_MenuStyle()
{
	ImVec4 col;

	col.x = 0.7f;
	col.y = 0.0f;
	col.z = 0.12f;
	col.w = 0.9f;

	ImGuiStyle* style = &ImGui::GetStyle();
	style->Colors[ImGuiCol_TitleBgActive] = col;
	style->Colors[ImGuiCol_Button] = col;
	style->Colors[ImGuiCol_CheckMark] = col;
	style->Colors[ImGuiCol_SliderGrab] = col;
	style->Colors[ImGuiCol_SliderGrabActive] = col;
	style->Colors[ImGuiCol_Tab] = col;

	col.x = 1.f;
	style->Colors[ImGuiCol_TabActive] = col;
	style->Colors[ImGuiCol_TabHovered] = col;

	style->WindowTitleAlign = ImVec2{ 0.5f, 0.5f };
}
void ImGui::R_StartImGuiRender(bool* canRender)
{

	if (game::dx->targetWindowIndex != 1) {
		*canRender = false;
		return;
	}

	//if (glob::drawmenu)
	//	R_MenuToggle(1);

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	//if (GetKeyState(MENU_TOGGLE) == 1) 
	//	ImGui::Begin("Good4Radiant", 0);

	//R_MenuStyle();

	//ImGui::Text("hello world!");
	*canRender = true;

	
	//if (!glob::drawmenu && GetKeyState(MENU_TOGGLE) == 0) {
	//	R_MenuToggle(0);
	//}
}
void ImGui::R_EndImGuiRender(bool* canRender)
{
	if (!*canRender)
		return;

	//if (GetKeyState(MENU_TOGGLE) == 1)
	//	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}