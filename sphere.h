#ifndef SPHERE_H
#define SPHERE_H

#include "vec3f.h"

class Material
{
public:
    gear::Vec3f diffuse_color;
public:
    Material() : diffuse_color(){};
    Material(const gear::Vec3f &color) : diffuse_color(color){};
};

namespace Materials
{
    const Material ivory (gear::Vec3f(0.4, 0.4, 0.3));

    const Material red_rubber (gear::Vec3f(0.3, 0.1, 0.1));

    const Material aqua (gear::Vec3f(0, 1, 1));

    const Material silver (gear::Vec3f(0.75, 0.75, 0.75));

    const Material crimson (gear::Vec3f(0.86, 0.08, 0.24));

    const Material orange_red (gear::Vec3f(1.f, 0.27, 0.f));
}

class Sphere
{
public:
    gear::Vec3f center;
    float radius;

    Material material;

public:
    Sphere(const gear::Vec3f &c, const float &r, const Material &m) : center(c), radius(r), material(m){}

    bool ray_intersect(const gear::Vec3f orig, const gear::Vec3f dir, float &t0) const;
};

class Light
{
public:
    gear::Vec3f position;
    float intensity;
public:
    Light(const gear::Vec3f &p, const float &i) : position(p), intensity(i){};

};

#endif // SPHERE_H
