#ifndef CANVAS_H
#define CANVAS_H

#include <cstdint>
#include <limits>
#include <vector>

#include "stb\stb_image_write.h"
#include "stb\stb_image.h"
#include "vec3f.h"
#include "sphere.h"

namespace  gear
{

class Canvas
{   
private:
    unsigned width, height, index;

    const int fov = M_PI/2;

    uint8_t *pixels;

    const short unsigned channel_num = 3;
    const float rgb = 255.99;

    friend void render (gear::Canvas &canvas, std::vector<Sphere> &sphere);
    friend void save_canvas(Canvas &canvas, const char *name);

public:
    Canvas(unsigned width, unsigned height);
    ~Canvas();

    void operator <<(gear::Vec3f &pixel);
};

gear::Vec3f cast_ray(const gear::Vec3f &orig, const gear::Vec3f &dir, const std::vector<Sphere> &spheres);

bool scene_intersect(const gear::Vec3f &orig, const gear::Vec3f &dir, const std::vector<Sphere> &spheres, float &dist, Material &material);

void save_canvas(Canvas &canvas, const char *name);

void render (gear::Canvas &canvas, std::vector<Sphere> &sphere);

}
#endif // CANVAS_H
