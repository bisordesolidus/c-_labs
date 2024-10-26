#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include "utils.hpp"
#include "vec3.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "hittable.hpp"

using color = vec3;
//using std::make_shared;
//using std::shared_ptr;

int main()
{
    auto aspect = 1;
    int width = 500;
    int height = int(width / aspect);
    height = (height < 1) ? 1 : height;
    auto viewport_height = 1.0;
    auto viewport_width = viewport_height * (double(width)/height);
    std::string path("my_imagge.ppm");
    std::ofstream os(path);
    scene s;
    camera cam;
    cam.image_width = 500;
    hittable_list world;
    sphere *s1 = new sphere(vec3(0,0.4,-1), 0.5);
    sphere *s2 = new sphere(vec3(0,-100.5,-1), 100);
    world.add(s1);
    world.add(s2);
    cam.render(os, world);
    delete s1;
    delete s2;
    return 0;


}