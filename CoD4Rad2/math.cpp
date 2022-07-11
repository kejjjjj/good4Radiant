

#include "h.h"

float normalize(float x)
{
	return fmodf(x + 360 + 180, 360) - 180;
}
float invert(float x)
{
	if (x < 0)
		return fabs(x);
	else
		return x * -1;
}
void AngleVectors(const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up) {
	float		angle;
	static float		sr, sp, sy, cr, cp, cy;
	// static to help MS compiler fp bugs

	angle = angles[YAW] * (M_PI * 2 / 360);
	sy = sin(angle);
	cy = cos(angle);
	angle = angles[PITCH] * (M_PI * 2 / 360);
	sp = sin(angle);
	cp = cos(angle);
	angle = angles[ROLL] * (M_PI * 2 / 360);
	sr = sin(angle);
	cr = cos(angle);

	if (forward)
	{
		forward[0] = cp * cy;
		forward[1] = cp * sy;
		forward[2] = -sp;
	}
	if (right)
	{
		right[0] = (-1 * sr * sp * cy + -1 * cr * -sy);
		right[1] = (-1 * sr * sp * sy + -1 * cr * cy);
		right[2] = -1 * sr * cp;
	}
	if (up)
	{
		up[0] = (cr * sp * cy + -sr * -sy);
		up[1] = (cr * sp * sy + -sr * cy);
		up[2] = cr * cp;
	}
}
void vector_scale(vec3_t vector, float scale, vec3_t out) {
	out[0] = vector[0] *= scale;
	out[1] = vector[1] *= scale;
	out[2] = vector[2] *= scale;

	//return Vec3{ vector[0], vector[1], vector[2] };
}
float vector_scaleComponent(float index, float scale) {
	return index *= scale;
}
float vector_addComponent(float index, float amount) {
	return index += amount;
}
void vector_add(vec3_t veca, vec3_t vecb, vec3_t out)
{
	out[0] = veca[0] += vecb[0];
	out[1] = veca[1] += vecb[1];
	out[2] = veca[2] += vecb[2];

	//return Vec3{ veca[0], veca[1], veca[2] };
}
void AnglesToForward(vec3_t angles, vec3_t origin, float scale, vec3_t out)
{
	vec3_t forwardAngles = { angles[0], angles[1], angles[2] };

	AngleVectors(angles, forwardAngles, NULL, NULL);
	vector_scale(forwardAngles, scale, out); //vec[i] * scale

	vector_add(forwardAngles, origin, out); //vec[i] + GetEye()[0]

	//return scaled;
}
void AnglesToRight(vec3_t angles, vec3_t origin, float scale, vec3_t out)
{
	vec3_t rightAngles = { angles[0], angles[1], angles[2] };

	AngleVectors(angles, NULL, rightAngles, NULL);
	vector_scale(rightAngles, scale, out); //vec[i] * scale

	vector_add(rightAngles, origin, out); //vec[i] + GetEye()[1]

	//return scaled;
}
void AnglesToUp(vec3_t angles, vec3_t origin, float scale, vec3_t out)
{
	vec3_t upAngles = { angles[0], angles[1], angles[2] };

	AngleVectors(angles, NULL, NULL, upAngles);
	vector_scale(upAngles, scale, out); //vec[i] * scale

	vector_add(upAngles, origin, out); //vec[i] + GetEye()[2]

	//return scaled;
}