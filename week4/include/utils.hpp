#pragma once
#include "ray.hpp"
#include "params.hpp"
#include "scene.hpp"
#include "transformations.hpp"
#include <iostream>
#include <string>
#include <fstream>

void write_image(std::ofstream &os, scene &s);