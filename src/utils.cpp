#include "utils.hpp"
#include "vec3.hpp"
#include <iostream>
#include <string>
#include <fstream>

void write_color(std::ostream& out, const vec3& pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

int write_image(){
    std::string path("my_image.ppm");
    std::ofstream os(path);

    os << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";

    for (int j = 0; j < HEIGHT; j++)
    {
        std::clog << "\rScanlines remaining: " << (HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < WIDTH; i++)
        {
            // transform [0, 1] to rgb color channels
            auto r = double(i) / (WIDTH-1);
            auto g = double(j) / (HEIGHT-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            // end of transform
            vec3 pixel_color = {r,g,b};
            write_color(os, pixel_color);
           // os << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    return 1;
};