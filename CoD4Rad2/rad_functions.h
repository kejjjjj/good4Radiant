#pragma once


#ifndef radfuncs
#define radfuncs

#include "h.h"

namespace rad
{
	selbrush_def_t* g_active_brushes();
	selbrush_def_t* g_active_brushes_next();
	selbrush_def_t* g_selected_brushes();
	selbrush_def_t* g_selected_brushes_next();
	selface_t* g_selected_faces();

	void GetBrushOrigin(selbrush_def_t* brush, vec3_t out);
	void GetBrushBounds(selbrush_def_t* brush, vec3_t out);

	inline void (*g_select_delete)() = (void (__cdecl*)())0x0425690;
	inline void (*g_on_selection_movedown)() = (void(__cdecl*)())0x429050;
	inline int (*g_update_selection)(WPARAM wParam, eclass_t* _class) = (int(__cdecl*)(WPARAM, eclass_t*))0x497180;
	inline void (*g_select_get_mid)(float* brushMtx) = (void(__cdecl*)(float*))0x48FC70;
	inline void (*g_select_move)(vec3_t origin, vec3_t dir, vec3_t move) = (void(__cdecl*)(vec3_t, vec3_t, vec3_t))0x47F0C0;

	inline int (*r_drawsurfs)(GfxCmdBufSourceState* source, GfxCmdBufState* state, GfxCmdBufState* prepassstate, GfxDrawSurfListInfo* info) = (int(__cdecl*)(GfxCmdBufSourceState * , GfxCmdBufState * , GfxCmdBufState * , GfxDrawSurfListInfo * ))0x5324E0;

	//brush[12]
	inline void (*g_select_applymatrix)(float* rotate_axis, void* brush, int snap, float degree, int unk /*bool*/) = (void(__cdecl*)(float*, void* , int , float , int))0x429050;
}

#endif