#pragma once
#include "hittable.hpp"
#include "vec3.hpp"
#include <iostream>
#include <chrono>
#include "params.hpp"
#include "utils.hpp"
#include "utils.hpp"
#include "random.hpp"

class camera {
  public:
    double aspect_ratio = 1;
    int    image_width  = 500;
    int    samples_per_pixel = 10;
    int    max_reflection = 10;

    void render(std::ofstream &os, const hittable& world);
  private:
    double pixel_samples_scale;
    int    image_height = image_width * aspect_ratio;   
    vec3 center;         
    vec3 pixel00_loc;    
    vec3   pixel_delta_u;  
    vec3   pixel_delta_v;  

    void initialize();
    
    ray get_ray(int i, int j) const;

    vec3 sample_square() const;
    vec3 ray_color(const ray& r, int depth, const hittable& world) const;
};