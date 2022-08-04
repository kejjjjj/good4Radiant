
#include "h.h"

void r::R_Render3DWnd()
{

	uint32_t targetWindow = rad::dx->targetWindowIndex;
	
	//if (targetWindow != 0)
	//	return;
	//ImGui::GetBackgroundDrawList()->AddText(ImVec2(0, 0), IM_COL32(255, 0, 0, 255), std::to_string(rad::gridSizes[rad::g_qeglobals->d_gridsize]).c_str());

	//rad::GfxWindowTarget wnd = rad::dx->windows[targetWindow];

	rad::selbrush_def_t* selected_brush =  rad::g_selected_brushes();

	if (!selected_brush || selected_brush->facecount < 1) {
		vars::guizmo::give_imgui_mouse = false;
		return;
	}
	
	R_InputHandler();
	R_BeginGuizmo(selected_brush);

	//vec2_t screen;
	//if (R_WorldToScreen(org, screen)) {
	//	ImGui::GetBackgroundDrawList()->AddText(ImVec2(screen[0], screen[1]), IM_COL32(0, 255, 0, 255), "BRUHS");
	//	return;
	//}
	//ImGui::GetBackgroundDrawList()->AddText(ImVec2(0, 0), IM_COL32(255, 0, 0, 255), "FAILED");
}