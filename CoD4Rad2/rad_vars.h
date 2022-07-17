#pragma once


namespace vars
{
	namespace guizmo
	{
		inline bool enabled;
		inline bool draw_bounds;

		//NOT-PREFERENCES
		inline bool give_imgui_mouse;
	}
	inline ImGuiContext* m_ggui_context = nullptr;
	inline bool set_next_frame;
}