#pragma once
#include "vec3.hpp"
class ray{
    public:
        vec3 m_origin; 
        vec3 m_direction;
        ray();
        ray(const vec3& A, const vec3& b);
        vec3 at(double t) const;
        vec3 origin() const;
        vec3 direction() const;
};
double hit_sphere(const vec3& center, double radius, const ray& r);