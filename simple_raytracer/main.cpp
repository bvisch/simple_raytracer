
#include "ray_tracer.h"
#include <iostream>
using namespace std;

int main() {
	sphere sph = sphere();
	ray_tracer rt = ray_tracer();
	vector<sphere> spheres = vector<sphere>();
	spheres.push_back(sph);

	cout << "Rendering..." << endl;
	rt.render(spheres);
	cout << "DONE!" << endl;
}