#include <iostream>
#include <ctime>

#include "canvas.h"
#include "sphere.h"

int main()
{
    const unsigned width = 1920;
    const unsigned height = 1080;

    unsigned start_time = clock();

    gear::Canvas canvas(width, height);

    Sphere sphere(gear::Vec3f(0, 10, -5), 10);

    gear::render(canvas, sphere);

    gear::save_canvas(canvas, "MyRayTracing.png");

    unsigned end_time = clock();

    float res = (end_time - start_time) / 1000.f;
    std::cout << res << std::endl;
    return 0;
}

