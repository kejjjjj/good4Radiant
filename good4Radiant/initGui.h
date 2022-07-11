#pragma once

namespace ImGui
{
	namespace glob
	{
		inline bool init;
		inline bool drawmenu;
	}
	void InitImgui();
	void R_StartImGuiRender(bool* canRender);
	void R_EndImGuiRender(bool* canRender);
	void R_MenuStyle();
	void R_MenuToggle(bool b);

}