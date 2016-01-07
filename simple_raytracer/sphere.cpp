#ifndef __sphere__cpp
#define __sphere__cpp

#include "sphere.h"

float sphere::intersect(ray const& r) const {
	vec3f rc = r.origin - position;
	float c = rc.dot(rc) - radius*radius;
	float b = r.direction.dot(rc);
	float d = b*b - c;
	float t = -b - sqrt(abs(d));
	if (t > 0.0) return t;
	return 0.0;
}

vec3f sphere::normal_at(vec3f const& point) const {
	return (point - position).normalize();
}

#endif