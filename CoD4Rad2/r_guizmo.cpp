#include "h.h"
void r::R_QuizmoMatrices(float(*view)[4], float(*projection)[4])
{
	//cheers to xoxor4d for letting me copy paste

	rad::GfxViewParms* vparms = rad::gfxCmdBufSourceState->viewParms3D;
	rad::GfxWindowTarget target = rad::dx->windows[0];

	MatrixForViewer(view, vparms->origin, (float(*)[3])vparms->axis);

	float fov = *(float*)0x25D6028;
	float halfFovY = tan(fov * 0.01745329238474369f * 0.5f) * 0.75f;
	float halfFovX = halfFovY * ((float)target.width / (float)target.height);

	R_SetupProjection(projection, halfFovX, halfFovY, 10.f);

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
	mtx4x4_mul(projection, inv_view_mtx, projection);
	mtx4x4_mul(projection, projection, inv_view_mtx);
	mtx3x3_mul((float(*)[3])projection, -1);

}
void r::R_TransformGuizmo(rad::selbrush_def_t* selected_brush, float* cameraView, float* cameraProjection)
{
	static ImGuizmo::MODE mCurrentGizmoMode(ImGuizmo::LOCAL);
	ImGuiIO& io = ImGui::GetIO();

	mCurrentGizmoOperation = ImGuizmo::TRANSLATE;

	vec3_t selection_center, mins, maxs;
	rad::GetBrushOrigin(selected_brush, selection_center);
	float rotation[3] = { 0.0f, 0.0f, 0.0f };
	float scale[3] = { 1.0f, 1.0f, 1.0f };
	float mtrx[16];

	ImGuizmo::RecomposeMatrixFromComponents(selection_center, rotation, scale, mtrx);

	mCurrentGizmoMode = ImGuizmo::WORLD;


	rad::GfxWindowTarget wnd = rad::dx->windows[0];

	ImGui::Begin("Gizmo", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
	ImGui::SetWindowPos(ImVec2(0, 0));
	ImGui::SetWindowSize(ImVec2(wnd.width, wnd.height));
	ImGuizmo::SetDrawlist();
	ImGuizmo::SetRect(0,0, wnd.width, wnd.height);

	float delta_matrix[16];


	VectorSubtract(selected_brush->def->mins, selection_center, mins);
	VectorSubtract(selected_brush->def->maxs, selection_center, maxs);

	vec_t bounds[] = { mins[0], mins[1], mins[2], maxs[0], maxs[1], maxs[2] };


	ImGuizmo::Manipulate(cameraView, cameraProjection, ImGuizmo::OPERATION::TRANSLATE, ImGuizmo::MODE::WORLD, mtrx, delta_matrix, 0, bounds);
	ImGui::End();



}
void r::R_BeginGuizmo(rad::selbrush_def_t* selected_brush)
{

	uint32_t targetWindow = rad::dx->targetWindowIndex;

	if (targetWindow != 0)
		return;

	float fov = *(float*)0x25D6028;

	ImGuizmo::SetOrthographic(false);
	ImGuizmo::BeginFrame();

	float view[4][4]{};
	float proj[4][4]{};
	R_QuizmoMatrices(view, proj);



	R_TransformGuizmo(selected_brush, (float*)view, (float*)proj);

	//ImGui::GetBackgroundDrawList()->AddText(ImVec2(wnd.width / 2, wnd.height / 2), IM_COL32(0, 255, 0, 255), std::to_string(cameraView[12]).c_str());
}