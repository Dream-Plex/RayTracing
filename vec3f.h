#ifndef VEC3F_H
#define VEC3F_H

#include <math.h>
#include <iostream>

namespace gear
{

class Vec3f
{
public:
    float x, y, z;

    Vec3f();
    Vec3f(float x, float y, float z);

    Vec3f(const Vec3f & other);

    float length();

    Vec3f normalize();
    static void normalize(Vec3f &target);

    Vec3f operator *(const float &var) const;
    void operator *=(const float &var);

    float operator *(const Vec3f &other) const;
    void operator *=(const Vec3f &other);

    Vec3f operator +(const Vec3f &other) const;
    void operator +=(const Vec3f &other);

    Vec3f operator -(const Vec3f &other) const;
    void operator -=(const Vec3f &other);

    void operator =(const Vec3f &other);

};

}

std::ostream& operator <<(std::ostream &out, const gear::Vec3f &v);

#endif // VEC3F_H
