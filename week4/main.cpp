#include <iostream>
#include <string>
#include <fstream>
#include "utils.hpp"
#include "vec3.hpp"
#include "scene.hpp"

using color = vec3;


int main()
{
    auto aspect = 16.0 / 9.0;
    int width = 400;
    int height = int(width / aspect);
    height = (height < 1) ? 1 : height;
    auto viewport_height = 1.0;
    auto viewport_width = viewport_height * (double(width)/height);
    std::string path("my_imagge.ppm");
    std::ofstream os(path);
    scene s;
    write_image(os, s);
    return 0;


}