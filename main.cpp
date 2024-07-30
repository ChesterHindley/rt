#define _CRT_SECURE_NO_WARNINGS


#include <print>
#include <iostream>
#include <fstream>
#include <limits>
#include <random>

#include "Vec3.h"
#include "Ray.h"
#include "FileManager.h"
#include "Hitables.h"
#include "Camera.h"
#include "ScopeTimer.h"


void printHeader(int width, int height, std::FILE* f = stdout) {
	std::print(f, "P3\n{} {}\n255\n", width, height);
}


float randomFloat() {
	std::uniform_real_distribution dist(0.f, 1.f);
	std::random_device dev;
	return dist( dev);
}



// returns vector with components within 0-1 range
// or 
Vec3 color(const Ray& r, Hitables world) {

	HitRecord record;
	if (world.hit(r, 0.0, std::numeric_limits<float>::max(), record))
		return 0.5f * (record.normal + 1);
	
	//  background gradient
	Vec3 direction = r.direction().normalized();
	float t = 0.5f * (direction.getY() + 1.0f);
	return (1.0f - t) * Vec3(1, 1, 1) + t * Vec3(0.5f, 0.7f, 1);
}

int main() {
	// define width and height for the image
	int width = 100;
	int height = 200;

	// ???
	int antiAliasingSamples = 100;

	FileManager f = std::fopen("out.ppm", "w");

	printHeader(width, height, f);


	// define bounds of 3d scene


	Camera cam;
	std::vector<Hitables::Variant> v{ Sphere(Vec3(0,-100.5,-1),100),Sphere(Vec3(0,0,-1),0.5) };

	Hitables world{ v };


	ScopeTimer timer;
	for (int j = height - 1; j >= 0; j--)
	{
		for (int i = 0; i < width; i++)
		{
			Vec3 col(0, 0, 0);
			for (int s = 0; s < antiAliasingSamples; s++)
			{

				float u = (i + randomFloat()) / static_cast<float>(width);
				float v = (j + randomFloat()) / static_cast<float>(height);

				// ray is a line from origin (camera) to some point on canvas 
				Ray r = cam.getRay(u, v);

				Vec3 p = r.pointAt(2.0f);
				col += color(r, world);
			}
			col = col / static_cast<float>(antiAliasingSamples);  // average 

			// scale rgb from 0-1 to 0-256
			int ir = static_cast<int>(255.99f * col.getX());
			int ig = static_cast <int>(255.99f * col.getY());
			int ib = static_cast <int>(255.99f * col.getZ());

			std::print(f, "{} {} {}\n", ir, ig, ib);
		}
	}

}