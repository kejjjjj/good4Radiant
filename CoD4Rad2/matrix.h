#pragma once

#ifndef mamtrix
#define mamtrix

#include "h.h"

#define DotProduct(x,y)			((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define VectorSubtract(a,b,c)	((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)		((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define	VectorScale(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define	VectorMA(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))

void Frustum(float left, float right, float bottom, float top, float znear, float zfar, float* m16);
void Perspective(float fovyInDegrees, float aspectRatio, float znear, float zfar, float* m16);
void Cross(const float* a, const float* b, float* r);
float Dot(const float* a, const float* b);
void Normalize(const float* a, float* r);
void LookAt(const float* eye, const float* at, const float* up, float* out);
void OrthoGraphic(const float l, float r, float b, const float t, float zn, const float zf, float* m16);
void rotationY(const float angle, float* m16);
void mtx4x4_mul(float(*mtx_out)[4], float(*a)[4], float(*b)[4]);
void mtx4tofloat(float(*m)[4], float* out);
void mtx4x4_mul(float* a, float(*b)[4]);
void mtx4x4_mul(float(*mtx_out)[4], float val);
void mtx3x3_mul(float(*mtx_out)[3], float val);
void VectorToAngles(vec3_t src, vec3_t dst, vec3_t out);
void Subtract(vec3_t src, vec3_t dst, vec3_t out);
float Magnitude(vec3_t vec);
float Distance(vec3_t src, vec3_t dst);

void clamp_vec3(const vec3_t a, const vec3_t b, vec3_t o1, vec3_t o2);
void add(const vec3_t veca, const vec3_t vecb, vec3_t out);
void scale(const vec3_t in, float scale, vec3_t out);
void set_vec3(vec3_t v, float val);

inline void (*MatrixForViewer)(float(*mtx)[4], const float* origin, const float(*axis)[3]) = (void(__cdecl*)(float(*)[4], const float*, const float(*)[3]))0x4A7A70;
inline void (*R_SetupProjection)(float(*mtx)[4], float halfFovX, float halfFovY, float zNear) = (void(__cdecl*)(float(*)[4], float, float, float))0x4A78E0;
#endif