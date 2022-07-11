#pragma once

#ifndef mmaatth
#define mmaatth

#include "h.h"

float normalize(float x);
float invert(float x);

void AngleVectors(const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up);
void AnglesToForward(vec3_t angles, vec3_t origin, float scale, vec3_t out);
void AnglesToRight(vec3_t angles, vec3_t origin, float scale, vec3_t out);
void AnglesToUp(vec3_t angles, vec3_t origin, float scale, vec3_t out);
void vector_scale(vec3_t vector, float scale, vec3_t out);
void vector_add(vec3_t veca, vec3_t vecb, vec3_t out);
float vector_scaleComponent(float index, float scale);
float vector_addComponent(float index, float amount);

#endif