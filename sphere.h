#ifndef SPHERE_H
#define SPHERE_H

#include "vec3f.h"

class Sphere
{
public:
    gear::Vec3f center;
    float radius;

public:
    Sphere(const gear::Vec3f &c, const float r) : center(c), radius(r){}

    bool ray_intersect(const gear::Vec3f orig, const gear::Vec3f dir, float &t0) const;
};

#endif // SPHERE_H
