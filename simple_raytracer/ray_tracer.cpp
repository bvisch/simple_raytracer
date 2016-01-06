#ifndef __ray_tracer__cpp
#define __ray_tracer__cpp

#include "ray_tracer.h"
#include <iostream>
#include <algorithm>

vec3f ray_tracer::trace(ray const& r, std::vector<sphere> const& spheres) const {
	std::vector<float> intersections;
	sphere nearest_sphere;
	float closest_hit;

	for (sphere const& s : spheres) {
		float intersection = s.intersect(r);
		if (intersection > 0.0 && intersection < closest_hit) {
			closest_hit = intersection;
			nearest_sphere = s;
		}
	}

	vec3f point_hit = r.at(closest_hit);
	vec3f hit_normal = nearest_sphere.normal_at(point_hit);

	//hardcoding light for now
	vec3f light = vec3f(0.5, 0.9, 0.5);
	vec3f light_direction = light - point_hit;
	float brightness = hit_normal.dot(light_direction);

	return vec3f(0.5, 0.5, 0.5) * brightness;
}

void ray_tracer::render(std::vector<sphere> const& spheres, std::string const& outfile) const {
}

#endif