#include <vector>

#include "canvas.h"
#include "sphere.h"
#include "timer.h"

int main()
{
    const unsigned width = 1920;
    const unsigned height = 1080;

    Timer t;
    t.Start();

    std::vector<Sphere> spheres;

    spheres.push_back(Sphere (gear::Vec3f(0, 10, -20), 10, Materials::crimson));
    spheres.push_back(Sphere (gear::Vec3f(0, 0, -10), 2, Materials::aqua));
    spheres.push_back(Sphere (gear::Vec3f(-1, -4, -13), 1.5, Materials::orange_red));
    spheres.push_back(Sphere (gear::Vec3f(-11, -5, -17), 4, Materials::red_rubber));
    spheres.push_back(Sphere (gear::Vec3f(10, -5, -17), 3, Materials::ivory));

    gear::Canvas canvas(width, height);

//    Sphere sphere(gear::Vec3f(0, 10, -5), 10);

    gear::render(canvas, spheres[1]); //Переделать метод

    gear::save_canvas(canvas, "MyRayTracing0.png");

    std::cout << "rendering completed in ";
    t.Stop();

    return 0;
}

