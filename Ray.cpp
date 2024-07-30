#include "Ray.h"

Ray::Ray(Vec3 from, Vec3 to)
{
    this->from = from;
    this->to = to;
}

Vec3 Ray::pointAt(float t) const {
    return from + to * t;
}

Vec3 Ray::origin() const
{
    return this->from;
}

Vec3 Ray::direction() const
{
    return this->to;
}

