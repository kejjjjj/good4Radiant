#pragma once

#ifndef ququizmo
#define ququizmo

#include "h.h"

namespace r
{
	static ImGuizmo::OPERATION mCurrentGizmoOperation(ImGuizmo::TRANSLATE);
	void R_QuizmoMatrices(float(*view)[4], float(*projection)[4]);
	void R_TransformGuizmo(rad::selbrush_def_t* selected_brush, float* cameraView, float* cameraProjection);
	void R_BeginGuizmo(rad::selbrush_def_t* selected_brush);
}

#endif