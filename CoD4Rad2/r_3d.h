#pragma once

#ifndef tdview
#define tdview
#include "h.h"

namespace r
{

	void R_Render3DWnd();


	//utils
	bool R_WorldToScreen(vec3_t pos, vec2_t xy);
}


#endif