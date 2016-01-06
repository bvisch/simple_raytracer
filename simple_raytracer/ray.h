#ifndef __ray__h
#define __ray__h

#include "vec3.h"

class ray {
public:
	vec3f origin, direction;
	
	ray(vec3f o = vec3f(0.0, 0.0, -0.6), vec3f d = vec3f(0.0, 0.0, 1.0)) : origin(o), direction(d) {}
	
	vec3f at(float const& distance) const { return origin + direction * distance; }
};

#endif