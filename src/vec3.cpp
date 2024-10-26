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

static vec3 random_vec() {
        return vec3(random_double(), random_double(), random_double());
}

static vec3 random_vec(double min, double max) {
        return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
}

vec3 random_unit_vector() {
    while (true) {
        auto p = random_vec(-1,1);
        auto lensq = p.length_squared();
        if ((lensq <= 1))
            return p / sqrt(lensq);
    }
}

vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (on_unit_sphere%normal > 0.0){
        return on_unit_sphere;
    }
    else{
        return vec3(0,0,0)-on_unit_sphere;
    }
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


vec3 operator* (double a, const vec3& rhs)
{
    vec3 v = rhs;
    return v.scale(a);
}

vec3 operator* (const vec3& rhs, double a)
{
    vec3 v = rhs;
    return v.scale(a);
}

double operator% (const vec3& rhs, const vec3& cpr)
{
    vec3 v = rhs;
    vec3 u = cpr;
    return v.x() * u.x() + v.y() * u.y() + v.z() * u.z();
}

vec3 operator+ (const vec3& rhs, const vec3& cpr){
    vec3 v = rhs;
    vec3 w =  cpr;
    return v.add(w);
}

vec3 operator- (const vec3& rhs, const vec3& cpr){
    vec3 v = rhs;
    vec3 w =  cpr;
    return v.sub(w);
}

vec3 unit_vector(vec3 direction){
    double l = 1/direction.length();
    return direction * l;
}

vec3 operator^(const vec3& v, const vec3& u) {
    return vec3(v.y() * u.z() - v.z() * u.y(),
                v.z() * u.x() - v.x() * u.z(),
                v.x() * u.y() - v.y() * u.x());
}

vec3 operator/ (const vec3& rhs, double a) {
    vec3 v = rhs;
    return v.scale(1/a);
}