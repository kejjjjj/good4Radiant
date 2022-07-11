#include "Math.h"
#include "renderer.h"
#include "structs.h"
bool Utils::WorldToScreen(vec3_t vWorldLocation, float* fScreenX, float* fScreenY)
{
	vec2_t resolution{};

	float prefFov = *(float*)0x25D6028;

	game::GfxWindowTarget* target = game::dx->windows;

	resolution[0] = (float)target[0].width;
	resolution[1] = (float)target[0].height;

	float fov[2]{};
	fov[1] = tan(prefFov * 0.017453 * 0.5f) * 0.75;
	fov[0] = fov[1] * resolution[0] / resolution[1];

	//D3D::TextWithOutline(std::to_string(fov[0]) + '\n' + std::to_string(fov[1]), D3DRECT{100, 100, 110, 100}, vec3_t{255,255,255});

	int centerX = resolution[0] / 2;
	int centerY = resolution[1] / 2;

	D3DXVECTOR3 vLocal, vTransForm;
	D3DXVECTOR3 vright = game::gfxCmdBufSourceState->viewParms3D->axis[1],
				vup = game::gfxCmdBufSourceState->viewParms3D->axis[2],
				vfwd = game::gfxCmdBufSourceState->viewParms3D->axis[0];
	
	VectorSubtract(vWorldLocation, game::rg->viewOrg, vLocal);

	vTransForm[0] = DotProduct(vLocal, vright);
	vTransForm[1] = DotProduct(vLocal, vup);
	vTransForm[2] = DotProduct(vLocal, vfwd);

	if (vTransForm.z < 0.01) 
		return 0;
	

	if (fScreenX && fScreenY) {
		*fScreenX = fabs(centerX * (1 - (vTransForm.x / fov[0] / vTransForm.z)));
		*fScreenY = centerY * (1 - (vTransForm.y / fov[1] / vTransForm.z));
	}

	return  vTransForm.z > 0;
}