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

void gear::render(gear::Canvas &canvas, std::vector<Sphere> &spheres, std::vector<Light> &lights)
{
    for (size_t j = canvas.height; j > 0; --j)
    {
        for (size_t i = 0; i < canvas.width; ++i)
        {
            float x = (2 * (i + 0.5)/(float)canvas.width - 1) * tan(canvas.fov/2.)
                    * canvas.width/(float)canvas.height;
            float y = -(2 * (j + 0.5)/(float)canvas.height - 1) * tan(canvas.fov/2.);

            auto dir = Vec3f(x, y, -1).normalize();
            auto res = cast_ray(Vec3f (0, 0, 0), dir, spheres, lights);

            canvas << res;
        }
    }
}

gear::Vec3f gear::cast_ray(const gear::Vec3f &orig, const gear::Vec3f &dir, const std::vector<Sphere> &spheres, std::vector<Light> &lights)
{
    gear::Vec3f point, N;

    Material material;

    if (!scene_intersect(orig, dir, spheres, point, N, material))
        return gear::Vec3f (0.2, 0.7, 0.8);
//        return gear::Vec3f (0., 0., 0.);

    // Написать код для рассчета света.
    float diffuse_light_intensity = 0, specular_light_intensity = 0;
    for (auto &light : lights)
    {
        gear::Vec3f light_dir = (light.position - point).normalize();

        diffuse_light_intensity += light.intensity * std::max(0.f, N * light_dir);
        specular_light_intensity += powf(std::max(0.f, reflect(light_dir, N)*dir), material.specular_exponent) * light.intensity;
    }

    return (material.diffuse_color * diffuse_light_intensity * material.albedo.x + gear::Vec3f(1., 1., 1.) *
            specular_light_intensity * material.albedo.y).clipping_color();
}

bool gear::scene_intersect(const gear::Vec3f &orig, const gear::Vec3f &dir, const std::vector<Sphere> &spheres, Vec3f &hit, Vec3f &N, Material &material)
{
    float sphere_dist = std::numeric_limits<float>::max();
    for (const auto &sphere : spheres)
    {
        float dist_i;
        if (sphere.ray_intersect(orig, dir, dist_i) && dist_i < sphere_dist)
        {
            sphere_dist = dist_i;
            hit = orig + dir * dist_i;
            N = (hit - sphere.center).normalize();
            material = sphere.material;
        }
    }

    return sphere_dist < 1000;
}

gear::Vec3f gear::reflect(const gear::Vec3f &I, const gear::Vec3f &N)
{
    return I - N * 2.f * (I * N);
}
