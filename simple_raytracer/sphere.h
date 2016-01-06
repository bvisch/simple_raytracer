#ifndef __sphere__h
#define __sphere__h

#include "vec3.h"
#include "ray.h"
#include <math.h>

class sphere {
public:

	vec3f position; 
	float radius;

	sphere() : position(vec3f(5.0, 0.0, -25.0)), radius(3.0) {}
	sphere(vec3f p, float r) : position(p), radius(r) {}

	float intersect(ray const& r) const;
	vec3f normal_at(vec3f const& point) const;
};

#endif