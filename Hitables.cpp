#include "Hitables.h"

// Constructor
Hitables::Hitables(const std::vector<Variant>& v) : hitables(v) {}

// hit function
bool Hitables::hit(const Ray& r, float tmin, float tmax, HitRecord& rec) const {

    HitRecord temp;
    static auto hit_lambdas = overload_set{
        [&](const Sphere& s) { return s.hit(r, tmin, tmax, temp); },
        [&](const Hitables& h) {return h.hit(r,tmin,tmax,temp); },
    };

    bool hit_anything = false;
    float closest_so_far = tmax;
    for (const auto& hitable : hitables)
    {
        if (std::visit(hit_lambdas, hitable))
        {
            hit_anything = true;
            closest_so_far = temp.t;
            rec = temp;
        }
    }
    return hit_anything;
}
