
#include "h.h"


void r::R_InputHandler()
{

	const bool lButtonPressed = GetAsyncKeyState(VK_LBUTTON) < 0;

	ImGuiIO& io = ImGui::GetIO();
	for (uint8_t i = 0; i < 5; i++)
		io.MouseDown[i] = false;

	io.MouseDown[0] = lButtonPressed;

}
void r::R_StartRender()
{

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGuizmo::BeginFrame();
}

void r::R_EndRender()
{
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}