#include "utils.hpp"
#include "vec3.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "hittable.hpp"
#include "interval.hpp"

double linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
        return 10*std::sqrt(linear_component);

    return 0;
}

std::string print_color(vec3 param) {
    static const interval intensity(0.000, 0.999);
    return std::to_string(linear_to_gamma(int(intensity.clamp(param.x()) * 255.999))) + " " +
           std::to_string(linear_to_gamma(int(intensity.clamp(param.y()) * 255.999))) + " " +
           std::to_string(linear_to_gamma(int(intensity.clamp(param.z()) * 255.999)));
}

void write_color(std::ostream &out, const vec3 &pixel_color) {
    out << print_color(pixel_color) << "\n";
}