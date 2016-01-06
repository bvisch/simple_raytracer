#ifndef __ray_tracer__cpp
#define __ray_tracer__cpp

#include "ray_tracer.h"
#include <algorithm>
#include <math.h>

const double PI = std::atan(1) * 4;

vec3f ray_tracer::trace(ray const& r, std::vector<sphere> const& spheres) const {
	std::vector<float> intersections;
	sphere nearest_sphere;
	float closest_hit = INFINITY;

	for (sphere const& s : spheres) {
		float intersection = s.intersect(r);
		if (intersection > 0.0 && intersection < closest_hit) {
			closest_hit = intersection;
			nearest_sphere = s;
		}
	}

	if (closest_hit < INFINITY) {

		vec3f point_hit = r.at(closest_hit);
		vec3f hit_normal = nearest_sphere.normal_at(point_hit);

		//hardcoding light for now
		vec3f light = vec3f(0.0, 20.0, -30.0);
		vec3f light_direction = light - point_hit;
		float b = hit_normal.dot(light_direction);
		float brightness = std::max(float(0), b);

		return vec3f(0.5, 0.5, 0.5) * brightness;
	}
	else {
		return vec3f(0.0);
	}
}

void ray_tracer::render(std::vector<sphere> const& spheres, std::string const& outfile) const {
	float width_inv = 1 / float(width), height_inv = 1 / float(height);
	float fov = 30;
	float aspect_ratio = width / float(height);
	float angle = tan(PI * 0.5 * fov / 180.0);

	std::ofstream ofs("./" + outfile + ".ppm", std::ios::out | std::ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";

	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < height; ++x) {
			float xi = (2 * ((x + 0.5) * width_inv) - 1) * angle * aspect_ratio;
			float yi = (1 - 2 * ((y + 0.5) * height_inv)) * angle;
			vec3f ray_direction = vec3f(xi, yi, -1).normalize();
			ray r = ray(vec3f(0.0), ray_direction);
			ofs << trace(r, spheres);
		}
	}

	ofs.close();
}

#endif