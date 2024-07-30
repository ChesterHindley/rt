#pragma once

#include "Vec3.h"
#include "Ray.h"

class Sphere
{
	Vec3 center;
	float radius;

public:
	Sphere(Vec3 cen, float r);
	bool hit(const Ray& r, float tmin, float tmax,struct HitRecord& rec) const;


	
};

