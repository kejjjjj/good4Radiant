
#include "h.h"

void vec::clamp(const vec3_t a, const vec3_t b, vec3_t o1, vec3_t o2)
{
	if (a[0] < o1[0]) o1[0] = a[0];
	if (a[1] < o1[1]) o1[1] = a[1];
	if (a[2] < o1[2]) o1[2] = a[2];

	if (b[0] > o2[0]) o2[0] = b[0];
	if (b[1] > o2[1]) o2[1] = b[1];
	if (b[2] > o2[2]) o2[2] = b[2];
}
void vec::clamp(const vec2_t a, const vec2_t b, vec2_t o1, vec2_t o2)
{
	if (a[0] < o1[0]) o1[0] = a[0];
	if (a[1] < o1[1]) o1[1] = a[1];

	if (b[0] > o2[0]) o2[0] = b[0];
	if (b[1] > o2[1]) o2[1] = b[1];
}
void vec::add(const vec3_t veca, const vec3_t vecb, vec3_t out)
{
	out[0] = veca[0] + vecb[0];
	out[1] = veca[1] + vecb[1];
	out[2] = veca[2] + vecb[2];
}
void vec::add(const vec2_t veca, const vec2_t vecb, vec2_t out)
{
	out[0] = veca[0] + vecb[0];
	out[1] = veca[1] + vecb[1];
}
void vec::subtract(const vec3_t veca, const vec3_t vecb, vec3_t out)
{
	out[0] = veca[0] - vecb[0];
	out[1] = veca[1] - vecb[1];
	out[2] = veca[2] - vecb[2];
}
void vec::subtract(const vec2_t veca, const vec2_t vecb, vec2_t out)
{
	out[0] = veca[0] - vecb[0];
	out[1] = veca[1] - vecb[1];
}
void vec::scale(const vec3_t in, float scale, vec3_t out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
	out[2] = in[2] * scale;
}
void vec::scale(const vec2_t in, float scale, vec2_t out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
}
void vec::divide(const vec3_t in, float scale, vec3_t out)
{
	out[0] = in[0] / scale;
	out[1] = in[1] / scale;
	out[2] = in[2] / scale;
}
void vec::divide(const vec2_t in, float scale, vec2_t out)
{
	out[0] = in[0] / scale;
	out[1] = in[1] / scale;
}
void vec::set(vec3_t v, float val)
{
	v[0] = val;
	v[1] = val;
	v[2] = val;
}
void vec::set(vec2_t v, float val)
{
	v[0] = val;
	v[1] = val;
}
void vec::copy(vec3_t a, vec3_t b)
{
	b[0] = a[0];
	b[1] = a[1];
	b[2] = a[2];
}
void vec::copy(vec2_t a, vec2_t b)
{
	b[0] = a[0];
	b[1] = a[1];
}
float vec::dot(vec3_t a, vec3_t b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
float vec::dot(vec2_t a, vec2_t b)
{
	return a[0] * b[0] + a[1] * b[1];
}