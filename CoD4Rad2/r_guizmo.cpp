#include "h.h"
void r::R_QuizmoMatrices(float(*view)[4], float(*projection)[4])
{
	//cheers to xoxor4d for letting me copy paste

	rad::GfxViewParms* vparms = rad::gfxCmdBufSourceState->viewParms3D;
	rad::GfxWindowTarget target = rad::dx->windows[0];


	MatrixForViewer(view, rad::rg->viewOrg, vparms->axis);

	float fov = *(float*)0x25D6028;
	float halfFovY = tan(fov * 0.01745329238474369f * 0.5f) * 0.75f;
	float halfFovX = halfFovY * ((float)target.width / (float)target.height);

	R_SetupProjection(projection, halfFovX, halfFovY, 10.f);

	//converts from left handed to right randed, credits to xoxor4d

	float inv_view_mtx[4][4] = {
			-1.f, 0.f, 0.f, 0.f,
			0.f, -1.f, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f };

	

	mtx4x4_mul(view, inv_view_mtx, view);
	mtx4x4_mul(view, view, inv_view_mtx);

	view[0][0] *= -1;
	view[0][1] *= -1;
	view[0][2] *= -1;
	view[1][0] *= -1;
	view[1][1] *= -1;
	view[1][2] *= -1;

	float inv_proj_mtx[4][4] = {
			1.f, 0.f, 0.f, 0.f,
			0.f, 1.f, 0.f, 0.f,
			0.f, 0.f, -1.f, 0.f,
			0.f, 0.f, 0.f, 1.f };
	mtx4x4_mul(projection, inv_proj_mtx, projection);
	mtx4x4_mul(projection, projection, inv_proj_mtx);
	//mtx3x3_mul((float(*)[3])projection, -1);

}
void r::R_SetupGuizmo(rad::selbrush_def_t* selected_brush, float* cameraView, float* cameraProjection)
{
	
	ImGuiIO& io = ImGui::GetIO();

	vec3_t selection_center, mins, maxs;
	rad::GetBrushOrigin(selected_brush, selection_center);
	float rotation[3] = { 0.0f, 0.0f, 0.0f };
	float scale[3] = { 1.0f, 1.0f, 1.0f };
	float matrix[16], delta_matrix[16];

	ImGuizmo::RecomposeMatrixFromComponents(selection_center, rotation, scale, matrix);

	//mCurrentGizmoMode = ImGuizmo::WORLD;


	rad::GfxWindowTarget wnd = rad::dx->windows[0];

	ImGui::Begin("Gizmo", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::SetWindowSize(ImVec2(wnd.width, wnd.height));
	ImGuizmo::SetDrawlist();
	ImGuizmo::SetRect(0,0, wnd.width, wnd.height);

	VectorSubtract(selected_brush->def->mins, selection_center, mins);
	VectorSubtract(selected_brush->def->maxs, selection_center, maxs);

	vec_t bounds[] = { mins[0], mins[1], mins[2], maxs[0], maxs[1], maxs[2] };


	float grid = rad::gridSizes[rad::g_qeglobals->d_gridsize];


	imguizmo.isManipulating = ImGuizmo::Manipulate(cameraView, cameraProjection, mCurrentGizmoOperation, ImGuizmo::WORLD, matrix, delta_matrix, vec3_t{grid,grid ,grid}/*, bounds*/);
	imguizmo.isOver			= ImGuizmo::IsOver();
	imguizmo.isUsing		= ImGuizmo::IsUsing();


	if (imguizmo.isUsing && imguizmo.isManipulating) {
		if (imguizmo.isOver) {
			vec3_t delta_origin, delta_angles, scale;
			ImGuizmo::DecomposeMatrixToComponents(delta_matrix, delta_origin, delta_angles, scale);



			R_TransformGuizmo(delta_origin, selected_brush, grid);
			R_ScaleGuizmo(scale, selection_center, grid);
		}

	

	}
	ImGui::End();

	imguizmo.mouseMoved = false;



}
void r::R_TransformGuizmo(const vec3_t deltaPosition, rad::selbrush_def_t* selected_brush, const float grid)
{	
	if (mCurrentGizmoOperation != ImGuizmo::OPERATION::TRANSLATE)
		return;

	if(imguizmo.mouseMoved)
		rad::g_brush_move(deltaPosition, selected_brush->def, true);
}
void r::R_ScaleGuizmo(vec3_t scale, vec3_t brush_origin, float grid)
{
	if (mCurrentGizmoOperation != ImGuizmo::OPERATION::SCALE)
		return;
	
	vec3_t v;
	vec::set3(v, 0);
	v[2] = grid;
	if (imguizmo.mouseMoved)
		rad::g_select_move(0, 0, v);
}
void r::R_BeginGuizmo(rad::selbrush_def_t* selected_brush)
{

	uint32_t targetWindow = rad::dx->targetWindowIndex;

	if (targetWindow != 0)
		return;

	ImGuizmo::SetOrthographic(false);


	float view[4][4]{};
	float proj[4][4]{};
	R_QuizmoMatrices(view, proj);



	R_SetupGuizmo(selected_brush, (float*)view, (float*)proj);

	//ImGui::GetBackgroundDrawList()->AddText(ImVec2(wnd.width / 2, wnd.height / 2), IM_COL32(0, 255, 0, 255), std::to_string(cameraView[12]).c_str());
}