#include "Vec3.h"
#include <cmath>

Vec3::Vec3(type x, type y, type z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3::Vec3() = default;


Vec3::Vec3(const Vec3&) = default;

Vec3 Vec3::operator+(Vec3 v) const
{
	return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
}

float Vec3::getX() const
{
	return x;
}

float Vec3::getY() const
{
	return y;
}

float Vec3::getZ() const
{
	return z;
}

Vec3 Vec3::normalized() const
{
	return *this / length();
}

float Vec3::length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

Vec3& Vec3::operator+=(const Vec3& v) {
	*this = *this + v;
	return *this;
}

Vec3 operator+(Vec3 v, float f) {
	return Vec3(v.x + f, v.y + f, v.z + f);
}

Vec3 operator+(float f, Vec3 v) {
	return v + f;
}

Vec3 operator-(Vec3 v1, Vec3 v2)
{
	return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator*(Vec3 v,float f)
{
	return Vec3(v.x * f, v.y * f, v.z * f);
}

Vec3 operator*(float f, Vec3 v)
{
	return v * f;
}

Vec3 operator/(Vec3 v, float f)
{
	return Vec3(v.x / f, v.y / f, v.z / f);
}

float dot(Vec3 v1, Vec3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
