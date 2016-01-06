#ifndef __sphere__h
#define __sphere__h
#endif

#include "vec3.h"
#include "ray.h"
#include <math.h>

class sphere {
public:

	vec3f position;
	float radius;

	sphere() : position(0.5), radius(1.0) {}
	sphere(vec3f p, float r) : position(p), radius(r) {}

	float intersect(ray const& r) const {
		vec3f rc = r.origin - position;
		float c = rc.dot(rc);
		float b = r.direction.dot(rc);
		float d = b*b - c;
		float t = -b - sqrt(abs(d));
		if (t > 0.0) return t;
		return 0.0;
	}
};