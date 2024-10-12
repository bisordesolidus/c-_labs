#pragma once
#include "utils.hpp"
#include "vec3.hpp"
#include "ray.hpp"
#include "scene.hpp"

vec3 color_to_rgb(const vec3& input_color);
vec3 gradient_vertical(const vec3& color_start, const vec3& color_end, int x, int y);
vec3 gradient_horizontal(const vec3& color_start, const vec3& color_end, int x, int y);
vec3 invert_color(const vec3& color);
vec3 color2bw(const vec3& color);
vec3 ray_color(const ray &r, const scene &s);