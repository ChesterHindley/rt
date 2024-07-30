#pragma once
#include "Vec3.h"

class Ray
{

	Vec3 from, to;
public:
	Ray();
	Ray(Vec3 from, Vec3 to);

	Vec3 pointAt(float t) const;
	Vec3 origin() const;
	Vec3 direction() const;
	
};

