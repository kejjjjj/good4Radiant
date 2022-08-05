
#include "h.h"

void vec::clamp3(const vec3_t a, const vec3_t b, vec3_t o1, vec3_t o2)
{
	if (a[0] < o1[0]) o1[0] = a[0];
	if (a[1] < o1[1]) o1[1] = a[1];
	if (a[2] < o1[2]) o1[2] = a[2];

	if (b[0] > o2[0]) o2[0] = b[0];
	if (b[1] > o2[1]) o2[1] = b[1];
	if (b[2] > o2[2]) o2[2] = b[2];
}
void vec::clamp2(const vec2_t a, const vec2_t b, vec2_t o1, vec2_t o2)
{
	if (a[0] < o1[0]) o1[0] = a[0];
	if (a[1] < o1[1]) o1[1] = a[1];

	if (b[0] > o2[0]) o2[0] = b[0];
	if (b[1] > o2[1]) o2[1] = b[1];
}
void vec::add3(const vec3_t veca, const vec3_t vecb, vec3_t out)
{
	out[0] = veca[0] + vecb[0];
	out[1] = veca[1] + vecb[1];
	out[2] = veca[2] + vecb[2];
}
void vec::add2(const vec2_t veca, const vec2_t vecb, vec2_t out)
{
	out[0] = veca[0] + vecb[0];
	out[1] = veca[1] + vecb[1];
}
void vec::subtract3(const vec3_t veca, const vec3_t vecb, vec3_t out)
{
	out[0] = veca[0] - vecb[0];
	out[1] = veca[1] - vecb[1];
	out[2] = veca[2] - vecb[2];
}
void vec::subtract2(const vec2_t veca, const vec2_t vecb, vec2_t out)
{
	out[0] = veca[0] - vecb[0];
	out[1] = veca[1] - vecb[1];
}
void vec::scale3(const vec3_t in, float scale, vec3_t out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
	out[2] = in[2] * scale;
}
void vec::scale4(const vec4_t in, float scale, vec4_t out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
	out[2] = in[2] * scale;
	out[3] = in[3] * scale;
}
void vec::scale2(const vec2_t in, float scale, vec2_t out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
}
void vec::divide4(const vec4_t in, float scale, vec4_t out)
{
	out[0] = in[0] / scale;
	out[1] = in[1] / scale;
	out[2] = in[2] / scale;
	out[3] = in[3] / scale;
}
void vec::divide3(const vec3_t in, float scale, vec3_t out)
{
	out[0] = in[0] / scale;
	out[1] = in[1] / scale;
	out[2] = in[2] / scale;
}
void vec::divide2(const vec2_t in, float scale, vec2_t out)
{
	out[0] = in[0] / scale;
	out[1] = in[1] / scale;
}
void vec::set3(vec3_t v, float val)
{
	v[0] = val;
	v[1] = val;
	v[2] = val;
}
void set3_3(vec3_t v, vec3_t val)
{
	v[0] = val[0];
	v[1] = val[1];
	v[2] = val[2];
}
void vec::set2(vec2_t v, float val)
{
	v[0] = val;
	v[1] = val;
}
void vec::copy3(vec3_t a, vec3_t b)
{
	b[0] = a[0];
	b[1] = a[1];
	b[2] = a[2];
}
void vec::copy2(vec2_t a, vec2_t b)
{
	b[0] = a[0];
	b[1] = a[1];
}
vec_t vec::dot3(vec3_t a, vec3_t b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
vec_t vec::dot2(vec2_t a, vec2_t b)
{
	return a[0] * b[0] + a[1] * b[1];
}
void vec::vec2invert(vec2_t vec)
{
	vec[0] *= -1;
	vec[1] *= -1;
}
void vec::vec3invert(vec3_t vec)
{
	vec[0] *= -1;
	vec[1] *= -1;
	vec[2] *= -1;
}
void vec::vec4invert(vec4_t vec)
{
	vec[0] *= -1;
	vec[1] *= -1;
	vec[2] *= -1;
	vec[3] *= -1;
}
void vec::set3_3(vec3_t v, vec3_t val)
{
	VectorCopy(val, v);
}
void vec::set2_2(vec2_t v, vec2_t val)
{
	v[0] = val[0];
	v[1] = val[1];
}
void vec::setrange2(vec2_t vec, float range)
{

	vec[0] = fmodf(vec[0], range);
	vec[1] = fmodf(vec[1], range);
}
void vec::setrange3(vec3_t vec, float range)
{

	vec[0] = fmodf(vec[0], range);
	vec[1] = fmodf(vec[1], range);
	vec[2] = fmodf(vec[2], range);
}
vec_t vec::normalize(vec_t vec)
{
	return fmodf(vec + 360 + 180, 360) - 180;
}
void vec::normalize2(vec2_t vec)
{
	vec[0] = fmodf(vec[0] + 360 + 180, 360) - 180;
	vec[1] = fmodf(vec[1] + 360 + 180, 360) - 180;
}
void vec::normalize3(vec3_t vec)
{
	vec[0] = fmodf(vec[0] + 360 + 180, 360) - 180;
	vec[1] = fmodf(vec[1] + 360 + 180, 360) - 180;
	vec[2] = fmodf(vec[2] + 360 + 180, 360) - 180;
}
void vec::setabs2(vec2_t vec)
{
	vec[0] = vec[0] > 0 ? vec[0] : vec[0] * -1;
	vec[1] = vec[1] > 0 ? vec[1] : vec[1] * -1;
}
void vec::setabs3(vec3_t vec)
{
	vec[0] = vec[0] > 0 ? vec[0] : vec[0] * -1;
	vec[1] = vec[1] > 0 ? vec[1] : vec[1] * -1;
	vec[2] = vec[2] > 0 ? vec[2] : vec[2] * -1;
}
vec_t vec::length3(const vec3_t v)
{
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
vec_t vec::Q3_VectorNormalize(vec3_t v)
{
	float length, ilength;

	length = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	length = sqrt(length);

	if (length) {
		ilength = 1 / length;
		v[0] *= ilength;
		v[1] *= ilength;
		v[2] *= ilength;
	}

	return length;
}
vec_t vec::Q3_VectorNormalize2(const vec3_t v, vec3_t out)
{
	float length, ilength;

	length = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	length = sqrt(length);

	if (length) {
		ilength = 1 / length;
		out[0] = v[0] * ilength;
		out[1] = v[1] * ilength;
		out[2] = v[2] * ilength;
	}
	else {
		VectorClear(out);
	}

	return length;
}
void vec::vectoangles(const vec3_t value1, vec3_t angles) {
	float forward;
	float yaw, pitch;

	if (value1[1] == 0 && value1[0] == 0) {
		yaw = 0;
		if (value1[2] > 0) {
			pitch = 90;
		}
		else {
			pitch = 270;
		}
	}
	else {
		if (value1[0]) {
			yaw = (atan2(value1[1], value1[0]) * 180 / M_PI);
		}
		else if (value1[1] > 0) {
			yaw = 90;
		}
		else {
			yaw = 270;
		}
		if (yaw < 0) {
			yaw += 360;
		}

		forward = sqrt(value1[0] * value1[0] + value1[1] * value1[1]);
		pitch = (atan2(value1[2], forward) * 180 / M_PI);
		if (pitch < 0) {
			pitch += 360;
		}
	}

	angles[PITCH] = -pitch;
	angles[YAW] = yaw;
	angles[ROLL] = 0;
}
