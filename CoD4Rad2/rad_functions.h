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

}

#endif