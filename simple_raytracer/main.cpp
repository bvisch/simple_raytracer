
#include "ray_tracer.h"
#include <iostream>
using namespace std;

int main() {
	sphere sph = sphere();
	sphere sph1 = sphere(vec3f(3.0, 2.0, -40.0), 2);
	sphere sph2 = sphere(vec3f(-3.0, 2.0, -15.0), 1);
	ray_tracer rt = ray_tracer();
	vector<sphere> spheres = vector<sphere>();
	spheres.push_back(sph);
	spheres.push_back(sph1);
	spheres.push_back(sph2);

	cout << "Rendering..." << endl;
	rt.render(spheres);
	cout << "DONE!" << endl;
}