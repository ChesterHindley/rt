#pragma once

#include <vector>
#include <variant>
#include "Sphere.h"
#include "Ray.h"

struct HitRecord
{
    float t;
    Vec3 p;
    Vec3 normal;
};

// A variant that can hold any type of hitable object
class Hitables
{
public:
    using Variant = std::variant<Sphere,Hitables>; // Add more hitable objects here if needed


private:
    std::vector<Variant> hitables;

public:
    Hitables(const std::vector<Variant>& v);
    bool hit(const Ray& r, float tmin, float tmax, HitRecord& rec) const;
};

// Helper for creating an overload set
template <typename ...F>
struct overload_set : public F ...
{
    using F::operator() ...;
};

template <typename ...F>
overload_set(F&& ... f) -> overload_set<F...>;
