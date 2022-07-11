#pragma once

#ifndef renderrre
#define renderrre
#include "d3dsetup.h"
#include "structs.h"
namespace D3D
{
	namespace glob
	{
		inline bool qfontInitialized;
	}
	void TextWithOutline(std::string p, D3DRECT rect, vec3_t color);
	
	void InitFonts();
	namespace _3d
	{
		HWND Get3DViewHWND();
		void RenderThread();
		void Get3DViewResolution(RECT rect, vec2_t resolution);
		RECT GetWindowDimensions(HWND hwnd, RECT* rect);
		void SelectedBrush_Origin(game::selbrush_def_t* brush, vec3_t out);
		void SelectedBrush_Bounds(game::selbrush_def_t* brush, vec3_t out);
	}
}
#endif