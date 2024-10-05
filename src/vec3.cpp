#include <iostream>
#include <cmath>
#include "vec3.hpp"
#include <string>

vec3::vec3() : e{0, 0, 0} {}

vec3::vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }

double vec3::get(int idx) const { return e[idx]; }

vec3& vec3::add(const vec3& v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
}

vec3& vec3::sub(const vec3& v) {
    e[0] -= v.x();
    e[1] -= v.y();
    e[2] -= v.z();
    return *this;
}

vec3& vec3::scale(double s) {
    e[0] *= s;
    e[1] *= s;
    e[2] *= s; 
    return   *this;
}

double vec3::dot(const vec3& v) const {
    return e[0] * v.x() + e[1] * v.y() + e[2] * v.z();
}

vec3 vec3::cross(const vec3& v) const {
    return vec3(e[1] * v.z() - e[2] * v.y(),
                e[2] * v.x() - e[0] * v.z(),
                e[0] * v.y() - e[1] * v.x());
}

std::string vec3::print() const {
    return "[" + std::to_string(e[0]) + ", " + std::to_string(e[1]) + ", " + std::to_string(e[2]) + "]";
}

double vec3::length() const {
    return sqrt(length_squared());
}

double vec3::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}
