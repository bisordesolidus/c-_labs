#include "utils.hpp"
#include "vec3.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "hittable.hpp"


std::string print_color(vec3 param) {
    return std::to_string(int(param.x() * 255.999)) + " " +
           std::to_string(int(param.y() * 255.999)) + " " +
           std::to_string(int(param.z() * 255.999));
}

void write_color(std::ostream &out, const vec3 &pixel_color) {
    out << print_color(pixel_color) << "\n";
}

void write_image(std::ofstream &os, scene &s) {

    os << "P3\n" << s.width() << ' ' << s.height() << "\n255\n";
    for (int j = 0; j < s.height(); j++) {
        std::clog << "\rScanlines remaining: " << (s.height() - j) << ' ' << std::flush;
        for (int i = 0; i < s.width(); i++) {
            ray r = s.cds_to_ray(i, j);
            write_color(os, ray_color(r, s));
        }
    }
    std::clog << "\rDone.\n";
}

vec3 ray_color(const ray& r, const scene &s) {
    sphere s1 = sphere(vec3(0.0, 0.0, -2.0), 0.5);
    hit_record rec(vec3(0,0,0), vec3(0,0,0), 0);
    bool  tt = s1.hit(r,0, 100, rec);
    if (tt == true) {
        vec3 N = unit_vector(r.at(rec.t) - vec3(0,0,-1));
        return 0.5*vec3(N.x()+1, N.y()+1, N.z()+1);
    };
    vec3 unit_direction = unit_vector(r.m_direction);
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0); 
}