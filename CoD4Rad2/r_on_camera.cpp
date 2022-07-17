

#include "h.h"

void r::MoveBrush(rad::selbrush_def_t* brush, vec3_t dir, vec3_t move)
{
	if (!brush || brush->facecount < 1)
		return;

	vec3_t org;
	rad::GetBrushOrigin(brush, org);

	rad::g_select_move(org, dir, move);
	*rad::g_nUpdateBits |= rad::W_CAMERA | rad::VIEW_MODE_2D;

}
void r::TranslateObject(CAM_DIRECTION dir, vec3_t move, float axial, int32_t grid)
{
	switch (dir) {
	case CAM_DIRECTION::CAM_LEFT:
		move[0] = (int)round(rad::rg->viewDir[1]) * -grid;
		move[1] = (int)round(rad::rg->viewDir[0]) * grid;
		break;
	case CAM_DIRECTION::CAM_RIGHT:
		move[0] = (int)round(rad::rg->viewDir[1]) * grid;
		move[1] = (int)round(rad::rg->viewDir[0]) * -grid;
		break;
	case CAM_DIRECTION::CAM_FORWARD:
		move[0] = (int)round(rad::rg->viewDir[0]) * grid;
		move[1] = (int)round(rad::rg->viewDir[1]) * grid;
		break;
	case CAM_DIRECTION::CAM_BACK:
		move[0] = (int)round(rad::rg->viewDir[0]) * -grid;
		move[1] = (int)round(rad::rg->viewDir[1]) * -grid;
		break;
	}
	vec2_t absmove;

	absmove[0] = abs(move[0]);
	absmove[1] = abs(move[1]);

	if (absmove[0] != grid)
		move[0] = 0;
	else if (absmove[1] != grid)
		move[1] = 0;

	if (absmove[0] == absmove[1]) {
		if (axial == 90 || axial == 270)
			move[0] = 0;
		else move[1] = 0;
	}
}
void r::TransformObjectByView(CAM_DIRECTION dir, vec3_t outmove)
{
	vec3_t cameraDir{};
	vec::scale3(rad::rg->viewDir, 180, cameraDir);

	float axial = GetAxialYaw(cameraDir[1]);

	int grid = rad::gridSizes[rad::g_qeglobals->d_gridsize];
	vec3_t move;

	move[2] = 0;

	TranslateObject(dir, move, axial, grid);


	vec::copy3(move, outmove);
}
char r::OnCameraLeft(void* mainframe)
{
	vec3_t move;

	TransformObjectByView(CAM_DIRECTION::CAM_LEFT, move);

	vec_t* dir = vec3_t{ 0, 0, 0 };
	rad::selbrush_def_t* brush =  rad::g_selected_brushes();

	MoveBrush(brush, dir, move);

	return 1;
}
char r::OnCameraRight(void* mainframe)
{
	vec3_t move;

	TransformObjectByView(CAM_DIRECTION::CAM_RIGHT, move);

	vec_t* dir = vec3_t{ 0, 0, 0 };
	rad::selbrush_def_t* brush = rad::g_selected_brushes();

	MoveBrush(brush, dir, move);

	return 1;
}
char r::OnCameraForward(void* mainframe)
{
	vec3_t move;

	TransformObjectByView(CAM_DIRECTION::CAM_FORWARD, move);

	vec_t* dir = vec3_t{ 0, 0, 0 };
	rad::selbrush_def_t* brush = rad::g_selected_brushes();

	MoveBrush(brush, dir, move);

	return 1;
}
char r::OnCameraBack(void* mainframe)
{
	vec3_t move;

	TransformObjectByView(CAM_DIRECTION::CAM_BACK, move);

	vec_t* dir = vec3_t{ 0, 0, 0 };
	rad::selbrush_def_t* brush = rad::g_selected_brushes();

	MoveBrush(brush, dir, move);

	return 1;
}