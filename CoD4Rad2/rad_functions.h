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
	inline void (*g_select_move)(vec3_t origin, vec3_t dir, vec3_t move) = (void(__cdecl*)(vec3_t, vec3_t, vec3_t))0x47F0C0;
}

#endif