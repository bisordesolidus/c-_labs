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