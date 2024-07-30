#pragma once
class Vec3
{
private:
	using type = float;
	type x, y, z;
public:
	Vec3(type x, type y, type z);
	Vec3();
	Vec3(const Vec3&);


	Vec3 operator+(Vec3 v) const;

	float getX() const;
	float getY() const;
	float getZ() const;

	Vec3 normalized() const;
	float length() const;
	
	friend Vec3 operator+(Vec3 v, float f);
	friend Vec3 operator+(float f, Vec3 v);
	
	Vec3& operator+=(const Vec3& v);

	friend Vec3 operator-(Vec3, Vec3);

	friend Vec3 operator*(Vec3 v,float f);
	friend Vec3 operator*(float f, Vec3 v);

	friend Vec3 operator/(Vec3 v, float f);
	
	friend float dot(Vec3, Vec3);


};

