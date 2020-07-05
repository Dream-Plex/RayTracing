#ifndef SPHERE_H
#define SPHERE_H

#include "vec3f.h"
// Сделать нормальные вектора
class Vec2f
{
public:
    Vec2f(float x, float y) : x(x), y(y){};
    Vec2f() : x(), y(){};
    float x, y;
};

class Material
{
public:
    Vec2f albedo;
    gear::Vec3f diffuse_color;
    float specular_exponent;
public:
    Material() : albedo(1, 0), diffuse_color(), specular_exponent(){};
    Material(const Vec2f &a, const gear::Vec3f &color, const float &spec) : albedo(a), diffuse_color(color), specular_exponent(spec){};
};

namespace Materials
{
    const Material ivory (Vec2f(0.6,  0.3), gear::Vec3f(0.4, 0.4, 0.3), 50.);

    const Material red_rubber (Vec2f(0.9,  0.1), gear::Vec3f(0.3, 0.1, 0.1), 10.);

    const Material aqua (Vec2f(0.6,  0.3), gear::Vec3f(0, 1, 1), 50.);

    const Material silver (Vec2f(0.6,  0.3), gear::Vec3f(0.75, 0.75, 0.75), 10.);

    const Material crimson (Vec2f(0.6,  0.3), gear::Vec3f(0.86, 0.08, 0.24), 50.);

    const Material orange_red (Vec2f(0.6,  0.3), gear::Vec3f(1.f, 0.27, 0.f), 10.);
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
