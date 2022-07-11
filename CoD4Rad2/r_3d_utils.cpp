#include "h.h"



bool r::R_WorldToScreen(vec3_t pos, vec2_t xy)
{

	if (rad::dx->targetWindowIndex != 0)
		return false;
	
	rad::GfxWindowTarget target = rad::dx->windows[rad::dx->targetWindowIndex];
	rad::GfxViewParms* vparms = rad::gfxCmdBufSourceState->viewParms3D;
	

	int centerX = target.width / 2;
	int centerY = target.height / 2;

	float fov = *(float*)0x25D6028;
	float halfFovY = tan(fov * 0.01745329238474369f * 0.5f) * 0.75f;
	float halfFovX = halfFovY * ((float)target.width / (float)target.height);

	D3DXVECTOR3 vLocal, vTransForm;
	D3DXVECTOR3 vright = vparms->axis[1],
		vup = vparms->axis[2],
		vfwd = vparms->axis[0];

	VectorSubtract(pos, rad::rg->viewOrg, vLocal);

	vTransForm[0] = DotProduct(vLocal, vright);
	vTransForm[1] = DotProduct(vLocal, vup);
	vTransForm[2] = DotProduct(vLocal, vfwd);

	if (vTransForm.z < 0.01) {
		return false;
	}

	if (xy) {
		xy[0] = centerX * (1 - (vTransForm.x / halfFovX / vTransForm.z));
		xy[1] = centerY * (1 - (vTransForm.y / halfFovY / vTransForm.z));
	}
	
	return true;
}