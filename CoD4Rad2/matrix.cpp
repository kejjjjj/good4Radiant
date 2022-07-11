
#include "h.h"


void Frustum(float left, float right, float bottom, float top, float znear, float zfar, float* m16)
{
	float temp, temp2, temp3, temp4;
	temp = 2.0f * znear;
	temp2 = right - left;
	temp3 = top - bottom;
	temp4 = zfar - znear;
	m16[0] = temp / temp2;
	m16[1] = 0.0;
	m16[2] = 0.0;
	m16[3] = 0.0;
	m16[4] = 0.0;
	m16[5] = temp / temp3;
	m16[6] = 0.0;
	m16[7] = 0.0;
	m16[8] = (right + left) / temp2;
	m16[9] = (top + bottom) / temp3;
	m16[10] = (-zfar - znear) / temp4;
	m16[11] = -1.0f;
	m16[12] = 0.0;
	m16[13] = 0.0;
	m16[14] = (-temp * zfar) / temp4;
	m16[15] = 0.0;
}

void Perspective(float fovyInDegrees, float aspectRatio, float znear, float zfar, float* m16)
{
	float ymax, xmax;
	ymax = znear * tanf(fovyInDegrees * 3.141592f / 180.0f);
	xmax = ymax * aspectRatio;
	Frustum(-xmax, xmax, -ymax, ymax, znear, zfar, m16);
}

void Cross(const float* a, const float* b, float* r)
{
	r[0] = a[1] * b[2] - a[2] * b[1];
	r[1] = a[2] * b[0] - a[0] * b[2];
	r[2] = a[0] * b[1] - a[1] * b[0];
}

float Dot(const float* a, const float* b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void Normalize(const float* a, float* r)
{
	float il = 1.f / (sqrtf(Dot(a, a)) + FLT_EPSILON);
	r[0] = a[0] * il;
	r[1] = a[1] * il;
	r[2] = a[2] * il;
}

void LookAt(const float* eye, const float* at, const float* up, float* m16)
{
	float X[3], Y[3], Z[3], tmp[3];

	tmp[0] = eye[0] - at[0];
	tmp[1] = eye[1] - at[1];
	tmp[2] = eye[2] - at[2];
	Normalize(tmp, Z);
	Normalize(up, Y);

	Cross(Y, Z, tmp);
	Normalize(tmp, X);

	Cross(Z, X, tmp);
	Normalize(tmp, Y);

	m16[0] = X[0];
	m16[1] = Y[0];
	m16[2] = Z[0];
	m16[3] = 0.0f;
	m16[4] = X[1];
	m16[5] = Y[1];
	m16[6] = Z[1];
	m16[7] = 0.0f;
	m16[8] = X[2];
	m16[9] = Y[2];
	m16[10] = Z[2];
	m16[11] = 0.0f;
	m16[12] = -Dot(X, eye);
	m16[13] = -Dot(Y, eye);
	m16[14] = -Dot(Z, eye);
	m16[15] = 1.0f;
}
void OrthoGraphic(const float l, float r, float b, const float t, float zn, const float zf, float* m16)
{
	m16[0] = 2 / (r - l);
	m16[1] = 0.0f;
	m16[2] = 0.0f;
	m16[3] = 0.0f;
	m16[4] = 0.0f;
	m16[5] = 2 / (t - b);
	m16[6] = 0.0f;
	m16[7] = 0.0f;
	m16[8] = 0.0f;
	m16[9] = 0.0f;
	m16[10] = 1.0f / (zf - zn);
	m16[11] = 0.0f;
	m16[12] = (l + r) / (l - r);
	m16[13] = (t + b) / (b - t);
	m16[14] = zn / (zn - zf);
	m16[15] = 1.0f;
}

inline void rotationY(const float angle, float* m16)
{
	float c = cosf(angle);
	float s = sinf(angle);

	m16[0] = c;
	m16[1] = 0.0f;
	m16[2] = -s;
	m16[3] = 0.0f;
	m16[4] = 0.0f;
	m16[5] = 1.f;
	m16[6] = 0.0f;
	m16[7] = 0.0f;
	m16[8] = s;
	m16[9] = 0.0f;
	m16[10] = c;
	m16[11] = 0.0f;
	m16[12] = 0.f;
	m16[13] = 0.f;
	m16[14] = 0.f;
	m16[15] = 1.0f;
}
void mtx4x4_mul(float(*mtx_out)[4], float(*a)[4], float(*b)[4])
{
	mtx_out[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + b[2][0] * a[0][2] + b[3][0] * a[0][3];
	mtx_out[0][1] = b[1][1] * a[0][1] + a[0][0] * b[0][1] + b[2][1] * a[0][2] + a[0][3] * b[3][1];
	mtx_out[0][2] = b[1][2] * a[0][1] + b[0][2] * a[0][0] + a[0][2] * b[2][2] + a[0][3] * b[3][2];
	mtx_out[0][3] = b[1][3] * a[0][1] + a[0][0] * b[0][3] + b[2][3] * a[0][2] + a[0][3] * b[3][3];
	mtx_out[1][0] = a[1][1] * b[1][0] + a[1][0] * b[0][0] + b[2][0] * a[1][2] + b[3][0] * a[1][3];
	mtx_out[1][1] = a[1][0] * b[0][1] + b[1][1] * a[1][1] + b[2][1] * a[1][2] + a[1][3] * b[3][1];
	mtx_out[1][2] = a[1][1] * b[1][2] + a[1][0] * b[0][2] + a[1][2] * b[2][2] + b[3][2] * a[1][3];
	mtx_out[1][3] = a[1][0] * b[0][3] + b[1][3] * a[1][1] + b[2][3] * a[1][2] + a[1][3] * b[3][3];
	mtx_out[2][0] = a[2][1] * b[1][0] + a[2][0] * b[0][0] + b[2][0] * a[2][2] + b[3][0] * a[2][3];
	mtx_out[2][1] = a[2][0] * b[0][1] + b[1][1] * a[2][1] + b[2][1] * a[2][2] + a[2][3] * b[3][1];
	mtx_out[2][2] = a[2][1] * b[1][2] + a[2][0] * b[0][2] + a[2][2] * b[2][2] + b[3][2] * a[2][3];
	mtx_out[2][3] = a[2][0] * b[0][3] + b[1][3] * a[2][1] + b[2][3] * a[2][2] + a[2][3] * b[3][3];
	mtx_out[3][0] = b[0][0] * a[3][0] + a[3][1] * b[1][0] + a[3][2] * b[2][0] + b[3][0] * a[3][3];
	mtx_out[3][1] = b[1][1] * a[3][1] + a[3][0] * b[0][1] + a[3][2] * b[2][1] + a[3][3] * b[3][1];
	mtx_out[3][2] = b[0][2] * a[3][0] + b[1][2] * a[3][1] + a[3][2] * b[2][2] + b[3][2] * a[3][3];
	mtx_out[3][3] = b[1][3] * a[3][1] + a[3][0] * b[0][3] + a[3][2] * b[2][3] + a[3][3] * b[3][3];
}
void mtx4x4_mul(float* a, float(*b)[4])
{
	a[0] *= b[3][0];
	a[1] *= b[3][1];
	a[2] *= b[3][2];
	a[3] *= b[3][3];
}
void mtx4x4_mul(float(*mtx_out)[4], float val)
{
	mtx_out[0][0] *= val;
	mtx_out[0][1] *= val;
	mtx_out[0][2] *= val;
	mtx_out[0][3] *= val;

	mtx_out[1][0] *= val;
	mtx_out[1][1] *= val;
	mtx_out[1][2] *= val;
	mtx_out[1][3] *= val;

	mtx_out[2][0] *= val;
	mtx_out[2][1] *= val;
	mtx_out[2][2] *= val;
	mtx_out[2][3] *= val;

	mtx_out[3][0] *= val;
	mtx_out[3][1] *= val;
	mtx_out[3][2] *= val;
	mtx_out[3][3] *= val;
}
void mtx3x3_mul(float(*mtx_out)[3], float val)
{
	mtx_out[0][0] *= val;
	mtx_out[0][1] *= val;
	mtx_out[0][2] *= val;

	mtx_out[1][0] *= val;
	mtx_out[1][1] *= val;
	mtx_out[1][2] *= val;

	mtx_out[2][0] *= val;
	mtx_out[2][1] *= val;
	mtx_out[2][2] *= val;

}
void mtx4tofloat(float(*m)[4], float* out)
{
	out[0] = m[0][0];
	out[1] = m[0][1];
	out[2] = m[0][2];
	out[3] = m[0][3];
	out[4] = m[1][0];
	out[5] = m[1][1];
	out[6] = m[1][2];
	out[7] = m[1][3];
	out[8] = m[2][0];
	out[9] = m[2][1];
	out[10] = m[2][2];
	out[11] = m[2][3];
	out[12] = m[3][0];
	out[13] = m[3][1];
	out[14] = m[3][2];
	out[15] = m[3][3];
}
void Subtract(vec3_t src, vec3_t dst, vec3_t out)
{
	out[0] = src[0] - dst[0];
	out[1] = src[1] - dst[1];
	out[2] = src[2] - dst[2];
	//diff.z = src.z - dst.z;
	//return diff;
}

float Magnitude(vec3_t vec)
{
	return sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

float Distance(vec3_t src, vec3_t dst)
{
	vec3_t out;
	Subtract(src, dst, out);
	return Magnitude(out);
}
float getHyp(float x, float y)
{
	float hyp = sqrt(pow(x, 2) + pow(y, 2));
	return hyp;
}
float GetYaw(float yaw, vec3_t src, vec3_t dst)
{
	if (src[0] > dst[0] && src[1] > dst[1] || src[0] > dst[0] && src[1] < dst[1])
		yaw += 180;
	return yaw;
}
void VectorToAngles(vec3_t src, vec3_t dst, vec3_t out)
{
	float distance, hyp;
	vec3_t angles{};

	Subtract(src, dst, out);
	distance = Distance(src, dst);

	hyp = getHyp(out[0], out[1]);
	angles[YAW] = atan(out[1] / out[0]) * 180.f / PI;
	angles[YAW] = GetYaw(angles[YAW], src, dst);

	angles[PITCH] = atan(out[2] / hyp) * 180.f / PI;

	out[YAW] = angles[YAW];
	out[PITCH] = angles[PITCH];
	out[ROLL] = 0;
}
void clamp_vec3(const vec3_t a, const vec3_t b, vec3_t o1, vec3_t o2)
{
	if (a[0] < o1[0]) o1[0] = a[0];
	if (a[1] < o1[1]) o1[1] = a[1];
	if (a[2] < o1[2]) o1[2] = a[2];

	if (b[0] > o2[0]) o2[0] = b[0];
	if (b[1] > o2[1]) o2[1] = b[1];
	if (b[2] > o2[2]) o2[2] = b[2];
}
void add(const vec3_t veca, const vec3_t vecb, vec3_t out)
{
	out[0] = veca[0] + vecb[0];
	out[1] = veca[1] + vecb[1];
	out[2] = veca[2] + vecb[2];
}
void scale(const vec3_t in, float scale, vec3_t out)
{
	out[0] = in[0] * scale;
	out[1] = in[1] * scale;
	out[2] = in[2] * scale;
}
void set_vec3(vec3_t v, float val)
{
	v[0] = val;
	v[1] = val;
	v[2] = val;
}