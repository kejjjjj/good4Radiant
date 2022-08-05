#pragma once

#ifndef thisvec
#define thisvec

#include "h.h"

namespace vec {


	void clamp3(const vec3_t a, const vec3_t b, vec3_t o1, vec3_t o2);
	void clamp2(const vec2_t a, const vec2_t b, vec2_t o1, vec2_t o2);
	void add3(const vec3_t veca, const vec3_t vecb, vec3_t out);
	void add2(const vec2_t veca, const vec2_t vecb, vec2_t out);
	void subtract3(const vec3_t veca, const vec3_t vecb, vec3_t out);
	void subtract2(const vec2_t veca, const vec2_t vecb, vec2_t out);
	void scale4(const vec4_t in, float scale, vec4_t out);
	void scale3(const vec3_t in, float scale, vec3_t out);
	void scale2(const vec2_t in, float scale, vec2_t out);
	void divide4(const vec4_t in, float scale, vec4_t out);
	void divide3(const vec3_t in, float scale, vec3_t out);
	void divide2(const vec2_t in, float scale, vec2_t out);
	void set3(vec3_t v, float val);
	void set3_3(vec3_t v, vec3_t val);
	void set2(vec2_t v, float val);
	void set2_2(vec2_t v, vec2_t val);
	void copy3(vec3_t a, vec3_t b);
	void copy2(vec2_t a, vec2_t b);
	vec_t dot3(vec3_t a, vec3_t b);
	vec_t dot2(vec2_t a, vec2_t b);
	void vec2invert(vec2_t vec);
	void vec3invert(vec3_t vec);
	void vec4invert(vec4_t vec);
	void setrange2(vec2_t vec, float range);
	void setrange3(vec3_t vec, float range);
	vec_t normalize(vec_t vec);
	void normalize2(vec2_t vec);
	void normalize3(vec3_t vec);
	void setabs2(vec2_t vec);
	void setabs3(vec3_t vec);
	vec_t length3(const vec3_t v);
	vec_t Q3_VectorNormalize(vec3_t v);
	vec_t Q3_VectorNormalize2(const vec3_t v, vec3_t out);
	void vectoangles(const vec3_t value1, vec3_t angles);

}

#endif


