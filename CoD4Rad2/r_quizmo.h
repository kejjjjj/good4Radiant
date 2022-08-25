#pragma once

#ifndef ququizmo
#define ququizmo

#include "h.h"

struct imguizmo_s
{
	bool isUsing;
	bool isManipulating;
	bool isOver;
	bool mouseMoved;
};

namespace r
{
	inline imguizmo_s imguizmo;
	inline ImGuizmo::OPERATION mCurrentGizmoOperation(ImGuizmo::TRANSLATE);
	void R_QuizmoMatrices(float(*view)[4], float(*projection)[4]);
	void R_SetupGuizmo(rad::selbrush_def_t* selected_brush, float* cameraView, float* cameraProjection);
	void R_BeginGuizmo(rad::selbrush_def_t* selected_brush);

	void R_TransformGuizmo(const vec3_t deltaPosition, rad::selbrush_def_t* selected_brush, const float grid);
	void R_ScaleGuizmo(vec3_t scale, vec3_t brush_origin, float grid);
	
}

#endif