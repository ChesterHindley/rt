#include "Sphere.h"
#include <cmath>

#include "Hitables.h"
#include "Ray.h"

Sphere::Sphere(Vec3 cen, float r) : center{ cen }, radius{ r } {}

bool Sphere::hit(const Ray& r, float tmin, float tmax, HitRecord& rec) const {
    // Auxiliary variable for frequent calculations
    Vec3 oc = r.origin() - center;

    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius * radius;

    float discriminant = b * b - a * c;

    if (discriminant < 0)
        return false;

    auto calculate_roots = [&](float root) -> bool {
        if (root < tmax && root > tmin)
        {
            rec.t = root;
            rec.p = r.pointAt(rec.t);
            rec.normal = (rec.p - center) / radius; // Already normalized
            return true;
        }
        return false;
        };

    float sqrt_discriminant = std::sqrt(discriminant);

    
    return calculate_roots((-b - sqrt_discriminant) / a) ||
        calculate_roots((-b + sqrt_discriminant) / a);
}
