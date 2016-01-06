#ifndef __ray_tracer__h
#define __ray_tracer__h

#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include <vector>
#include <string>

class ray_tracer {
public:
	unsigned width, height;

	ray_tracer(unsigned w = 640, unsigned h = 480) : width(w), height(h) {}

	vec3f trace(ray const& r, std::vector<sphere> const& spheres) const;
	void render(std::vector<sphere> const& spheres, std::string const& outfile) const;
};

#endif