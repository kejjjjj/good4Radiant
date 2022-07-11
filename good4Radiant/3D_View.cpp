#include "d3dsetup.h"
#include "renderer.h"
#include "Math.h"
#include "Utils.h"
HWND D3D::_3d::Get3DViewHWND()
{
	return game::dx->windows[0].hwnd;
}

void D3D::_3d::Get3DViewResolution(RECT rect, vec2_t resolution)
{
	resolution[0] = rect.right - rect.left;
	resolution[1] = rect.bottom - rect.top;
}
RECT D3D::_3d::GetWindowDimensions(HWND hwnd, RECT *rect)
{
	GetWindowRect(hwnd, &*rect);

	return *rect;
}
void D3D::_3d::SelectedBrush_Origin(game::selbrush_def_t* brush, vec3_t out)
{
	game::brush_t_with_custom_def* def = brush->def;

	for (int i = 0; i < 3; i++)
		out[i] = def->mins[i] + (def->maxs[i] - def->mins[i]) / 2;

}
void D3D::_3d::SelectedBrush_Bounds(game::selbrush_def_t* brush, vec3_t out)
{
	game::brush_t_with_custom_def* def = brush->def;

	for (int i = 0; i < 3; i++)
		out[i] = fabs(def->maxs[i] - def->mins[i]);
}
void D3D::_3d::RenderThread()
{

	if (game::dx->targetWindowIndex != 0)
		return;

	vec3_t brushOrg{}, brushBounds{};

	game::selbrush_def_t* selected_brushes = game::g_selected_brushes();
	game::selface_t* selected_faces = game::g_selected_faces();

	if (selected_brushes) {
		if (selected_brushes->facecount == 0)
			return;
		SelectedBrush_Origin(selected_brushes, brushOrg);
		SelectedBrush_Bounds(selected_brushes, brushBounds);
		float screenX, screenY;
		if (Utils::WorldToScreen(brushOrg, &screenX, &screenY)) {
			//TextWithOutline(std::to_string(screenX) + '\n' + std::to_string(screenY), D3DRECT{ 0,0,10,10}, vec3_t{ 0,255,0 });

			std::string brush = '(' + std::to_string(brushBounds[0]) + ", " + std::to_string(brushBounds[1]) + ", " + std::to_string(brushBounds[2]) + ')' + '\n' + 
				'(' + std::to_string(selected_brushes->facecount) + ')';
			TextWithOutline(brush, D3DRECT{(long)screenX,(long)screenY,(long)screenX + 10,(long)screenY + 10}, vec3_t{255,255,255});
		}
		else TextWithOutline("not visible", D3DRECT{ 0,10,0,10 }, vec3_t{ 0,255,0 });
		//return;
	}
	if (selected_faces && selected_brushes) {
		
		float zNormal = selected_brushes->def->brush_faces[selected_faces->index].plane.normal[2];
		float fadedColor = 255.f * (zNormal - .3f);
		if(zNormal > .3f && zNormal < .7f)
			TextWithOutline('+' + std::to_string((90.f + zNormal * 90) - 117), D3DRECT{0,10,0,10}, vec3_t{255,fadedColor,0});
	}
	else
		TextWithOutline("nullptr", D3DRECT{ 0,10,0,10 }, vec3_t{ 0,255,0 });

	
	//CURSORINFO cursor_info = { 0 };
	//cursor_info.cbSize = sizeof(CURSORINFO);
	//GetCursorInfo(&cursor_info);
	//
	//TextWithOutline(std::to_string(cursor_info.ptScreenPos.x) + '\n' + std::to_string(cursor_info.ptScreenPos.y), D3DRECT{0,100,0,110}, vec3_t{0,255,0});
	//TextWithOutline(std::to_string(rect.left) + '\n' + std::to_string(rect.top), D3DRECT{0,155,0,165}, vec3_t{0,255,0});
}