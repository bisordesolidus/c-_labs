#pragma once
#include "vec3.hpp"
#include "ray.hpp"
#include "scene.hpp"
#include <vector>

/*class hit_record {
public:
  vec3 point; 
  vec3 normal; 
  double t; 

  hit_record();
};*/
class hit_record {
public:
  vec3 point;
  vec3 normal;
  double t;
  bool front_face;
  hit_record() = default;
  hit_record(const vec3& _point, const vec3& _normal, double _t = 0.0, bool _front_face = false): point(_point), normal(_normal), t(_t), front_face(_front_face){}
  void set_face_normal(const ray& r, const vec3& outward_normal);
};

class hittable {
public:
  virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const=0;
};

class sphere : public hittable {
public:
  vec3 center;
  double radius;

  sphere();
  sphere(const vec3& _center, double _radius): center(_center), radius(_radius) {}

  bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
};

class hittable_list : public hittable {
  public:
    std::vector<hittable*> objs;
    hittable_list() {}
    hittable_list(hittable* obj) { add(obj); }
    void clear() { objs.clear(); }
    void add(hittable* obj);
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
};