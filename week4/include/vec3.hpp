#pragma once
#include <string>

class vec3 
{
private:
    double e[3];
public:
    vec3();

    vec3(double e0, double e1, double e2);
    double x() const;
    double y() const;
    double z() const;
    double get(int idx) const;

    vec3& add(const vec3& v);
    vec3& sub(const vec3& v);
    vec3& scale(double s);
    double dot(const vec3& v) const;
    vec3 cross(const vec3& v) const;
    std::string print() const;
    double length() const;
    double length_squared() const;
};

vec3 unit_vector(vec3 direction);
vec3 operator* (double a, const vec3& rhs);
vec3 operator* (const vec3& rhs, double a);
vec3 operator+ (const vec3& rhs, const vec3& cpr);
vec3 operator- (const vec3& rhs, const vec3& cpr);
vec3 operator^(const vec3 &v, const vec3 &u);
vec3 operator/ (const vec3& rhs, double a);