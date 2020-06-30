#include "vec3f.h"

gear::Vec3f::Vec3f()
{
    this->x =
    this->y =
    this->z = 0;
}

gear::Vec3f::Vec3f(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

gear::Vec3f::Vec3f(const Vec3f &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

float gear::Vec3f::length()
{
    return std::sqrt (x * x + y * y + z * z);
}

gear::Vec3f gear::Vec3f::normalize()
{
    float invLength = 1 / this->length ();
    return *this * invLength;
}

void gear::Vec3f::normalize(gear::Vec3f &target)
{
    float invLength = 1/ target.length ();
    target *= invLength;
}

gear::Vec3f gear::Vec3f::operator *(const float &var) const
{
    Vec3f temp(*this);
    temp.x *= var;
    temp.y *= var;
    temp.z *= var;
    return temp;
}

void gear::Vec3f::operator *=(const float &var)
{
    x *= var;
    y *= var;
    z *= var;
}

float gear::Vec3f::operator *(const gear::Vec3f &other) const
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

void gear::Vec3f::operator *=(const gear::Vec3f &other)
{
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
}
// Векторное произведение векторов
//gear::Vec3f gear::Vec3f::operator *(const Vec3f &other) const
//{
//    Vec3f temp(*this);
//    temp.x = +(temp.y * other.z - temp.z * other.y);
//    temp.y = -(temp.x * other.z - temp.z * other.x);
//    temp.z = +(temp.x * other.y - temp.y * other.x);
//    return temp;
//}

//void gear::Vec3f::operator *=(const Vec3f &other)
//{
//    Vec3f temp(*this);
//    this->x = +(temp.y * other.z - temp.z * other.y);
//    this->y = -(temp.x * other.z - temp.z * other.x);
//    this->z = +(temp.x * other.y - temp.y * other.x);
//}

gear::Vec3f gear::Vec3f::operator +(const gear::Vec3f &other) const
{
    Vec3f temp(*this);
    temp.x += other.x;
    temp.y += other.y;
    temp.z += other.z;
    return temp;
}

void gear::Vec3f::operator +=(const gear::Vec3f &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
}

gear::Vec3f gear::Vec3f::operator -(const gear::Vec3f &other) const
{
    Vec3f temp(*this);
    temp.x -= other.x;
    temp.y -= other.y;
    temp.z -= other.z;
    return temp;
}

void gear::Vec3f::operator -=(const gear::Vec3f &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
}

void gear::Vec3f::operator =(const gear::Vec3f &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

std::ostream &operator <<(std::ostream &out, const gear::Vec3f &v)
{
    return out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}
