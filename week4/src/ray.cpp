#include "ray.hpp"
#include <iostream>
#include <cmath>

ray::ray() : m_origin(vec3(0.0, 0.0, 0.0)), m_direction(vec3(0.0, 0.0, 1.0)) {}

ray::ray(const vec3& A, const vec3& b) : m_origin(A), m_direction(b) {}

vec3 ray::at(double t) const {
    return m_origin + m_direction * t;
  }

vec3 ray::origin() const { return m_origin; }
vec3 ray::direction() const { return m_direction; }

double hit_sphere(const vec3& center, double radius, const ray& r) {
  vec3 oc = r.m_origin - center; 
  double a = r.m_direction.length() * r.m_direction.length();
  double b = 2.0 * oc.dot(r.m_direction);
  double c = oc.length() * oc.length() - radius * radius; 

  double discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
      return -1.0;
  } else {
      return (-b - std::sqrt(discriminant) ) / (2.0*a);
  }
}