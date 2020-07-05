#include <vector>

#include "canvas.h"
#include "sphere.h"
#include "timer.h"

int main()
{
    const unsigned width = 1920;
    const unsigned height = 1080;

    gear::Canvas canvas(width, height);

    Timer t;
    t.Start();


    std::vector<Sphere> spheres;

    std::vector<Light> lights;

    spheres.push_back(Sphere(gear::Vec3f( 0,  10, -20),  10,   Materials::crimson   ));
    spheres.push_back(Sphere(gear::Vec3f(-1,  -4, -13),  1.5,  Materials::orange_red));
    spheres.push_back(Sphere(gear::Vec3f(-11, -5, -17),  4,    Materials::red_rubber));
    spheres.push_back(Sphere(gear::Vec3f( 10, -5, -17),  3,    Materials::ivory     ));

    lights.push_back(Light(gear::Vec3f(-30, -30,  20), 1.5));
    lights.push_back(Light(gear::Vec3f(  0,   0, -10), 1.5));

//    lights.push_back(Light(gear::Vec3f(-20, 20,  20), 1.5));
//    lights.push_back(Light(gear::Vec3f( 30, 50, -25), 1.8));
//    lights.push_back(Light(gear::Vec3f( 30, 20,  30), 1.7));

    gear::render(canvas, spheres, lights);

    gear::save_canvas(canvas, "MyRayTracing.png");

    t.Stop();

    std::cout << "completed in " << t << std::endl;

    return 0;
}

