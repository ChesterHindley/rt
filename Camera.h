#pragma once


#include "Vec3.h"
#include "Ray.h"

class Camera
{
	Vec3 origin				=	{ 0.f, 0.f, 0.f };
	Vec3 lowerLeftCorner	=	{ -2.f, -1.f, -1.f };
	Vec3 horizontal			=	{ 4.f, 0.f, 0.f };
	Vec3 vertical			=	{ 0.f, 2.f, 0.f };

public:

	Ray getRay(float u, float v) const;
	
};

