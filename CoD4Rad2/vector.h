#pragma once

#ifndef thisvec
#define thisvec

#include "h.h"

namespace vec {

	void clamp(const vec3_t a, const vec3_t b, vec3_t o1, vec3_t o2);
	void clamp(const vec2_t a, const vec2_t b, vec2_t o1, vec2_t o2);
	void add(const vec3_t veca, const vec3_t vecb, vec3_t out);
	void add(const vec2_t veca, const vec2_t vecb, vec2_t out);
	void subtract(const vec3_t veca, const vec3_t vecb, vec3_t out);
	void subtract(const vec2_t veca, const vec2_t vecb, vec2_t out);
	void scale(const vec3_t in, float scale, vec3_t out);
	void scale(const vec2_t in, float scale, vec2_t out);
	void divide(const vec3_t in, float scale, vec3_t out);
	void divide(const vec2_t in, float scale, vec2_t out);
	void set(vec3_t v, float val);
	void set(vec2_t v, float val);
	void copy(vec3_t a, vec3_t b);
	void copy(vec2_t a, vec2_t b);
	float dot(vec3_t a, vec3_t b);
	float dot(vec2_t a, vec2_t b);
}

#endif


