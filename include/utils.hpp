#pragma once
#include "ray.hpp"
#include "params.hpp"
#include "scene.hpp"
#include "transformations.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include "interval.hpp"
#include <cstdlib>
#include "random.hpp"

void write_image(std::ofstream &os, scene &s);
void write_color(std::ostream &out, const vec3 &pixel_color);
