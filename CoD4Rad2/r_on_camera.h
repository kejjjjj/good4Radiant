#pragma once

#ifndef oncamera
#define oncamera

#include "h.h"

namespace r
{
	enum CAM_DIRECTION {
		CAM_LEFT,
		CAM_RIGHT,
		CAM_FORWARD,
		CAM_BACK
	};

	void MoveBrush(rad::selbrush_def_t* brush, vec3_t dir, vec3_t move);
	void TransformObjectByView(CAM_DIRECTION dir, vec3_t outmove);
	void TranslateObject(CAM_DIRECTION dir, vec3_t outmove, float axial, int32_t grid);
	char OnCameraLeft(void* mainframe);
	char OnCameraRight(void* mainframe);
	char OnCameraForward(void* mainframe);
	char OnCameraBack(void* mainframe);
}


#endif