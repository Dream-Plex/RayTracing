#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "canvas.h"

gear::Canvas::Canvas(unsigned width, unsigned height)
{
    this->index = 0;
    this->width = width;
    this->height = height;
    this->pixels = new uint8_t [width * height * channel_num];
}

gear::Canvas::~Canvas()
{
    delete [] this->pixels;
}

void gear::Canvas::operator <<(gear::Vec3f &pixel)
{
    pixel *= this->rgb;

    pixels[index++] = pixel.x;
    pixels[index++] = pixel.y;
    pixels[index++] = pixel.z;
}

void gear::save_canvas(gear::Canvas &canvas, const char* name)
{
    unsigned stride = canvas.width * canvas.channel_num;
    stbi_write_png(name, canvas.width, canvas.height, canvas.channel_num, canvas.pixels, stride);
}

void gear::render(gear::Canvas &canvas, Sphere &sphere)
{
    for (size_t j = canvas.height; j > 0; --j)
    {
        for (size_t i = 0; i < canvas.width; ++i)
        {
            float x = (2 * (i + 0.5)/(float)canvas.width - 1) * tan(canvas.fov/2.)
                    * canvas.width/(float)canvas.height;
            float y = -(2 * (j + 0.5)/(float)canvas.height - 1) * tan(canvas.fov/2.);

            auto dir = Vec3f(x, y, -1).normalize();
            auto res = cast_ray(Vec3f (0, 0, 0), dir, sphere);

            canvas << res;
        }
    }
}

gear::Vec3f gear::cast_ray(const gear::Vec3f &orig, const gear::Vec3f &dir, const Sphere &sphere)
{
    float sphere_dist = std::numeric_limits<float>::max();
    if (!sphere.ray_intersect(orig, dir, sphere_dist))
        return gear::Vec3f (0.2, 0.7, 0.8);
    return /*gear::Vec3f (0.4, 0.4, 0.3)*/ sphere.material.diffuse_color;
}
