#include "sphere.h"

bool Sphere::ray_intersect(const gear::Vec3f orig, const gear::Vec3f dir, float &t0) const
{
    gear::Vec3f L = this->center - orig;
    float tca = L * dir;
    float d2 = L * L - tca * tca;

    if (d2 > (this->radius * this->radius)) return false;

    float thc = sqrtf((this->radius * this->radius) - d2);
    t0 = tca - thc;
    float t1 = tca +thc;

    if (t0 < 0) t0 = t1;
    if (t0 < 0) return false;

    return true;
}
