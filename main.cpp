#include <iostream>
#include <string>
#include <fstream>
#include "utils.hpp"
#include "vec3.hpp"

using color = vec3;


int main()
{
    write_image();
    std::clog << "\rDone.                 \n";
}