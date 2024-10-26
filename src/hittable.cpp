#include "hittable.hpp"
#include <cmath>


void hit_record::set_face_normal(const ray& r, const vec3& outward_normal){
  front_face = r.direction().dot(outward_normal) < 0;
  normal = front_face ? outward_normal : vec3(0,0,0)-outward_normal;
}


  bool sphere::hit(const ray& r, interval ray_t, hit_record& rec) const {
    vec3 oc = r.m_origin - center; 
    double a = r.m_direction.length() * r.m_direction.length(); 
    double b = 2.0 * oc.dot(r.m_direction); 
    double c = oc.length() * oc.length() - radius * radius; 

    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
      double t1 = (-b - sqrt(discriminant)) / (2 * a);
      double t2 = (-b + sqrt(discriminant)) / (2 * a);

      if (t1 < ray_t.max && t1 > ray_t.min) {
          rec.t = t1;
          rec.point = r.at(rec.t);
          vec3 outward_normal = (rec.point - center) / radius;
          rec.set_face_normal(r, outward_normal);
          rec.normal = unit_vector(rec.point - center); 
          return true;
      } else if (t2 < ray_t.max && t2 > ray_t.min) {
          rec.t = t2;
          rec.point = r.at(rec.t);
          vec3 outward_normal = (rec.point - center) / radius;
          rec.set_face_normal(r, outward_normal);
          rec.normal = unit_vector(rec.point - center); 
          return true;
      }
    }
    return false;
  }

void hittable_list::add(hittable* object) {
  objs.push_back(object);
}

bool hittable_list::hit(const ray& r, interval ray_t, hit_record& rec) const {
  hit_record temp_rec;
  bool hit_anything = false;
  auto closest_so_far = ray_t.max;
  for (auto object : objs) {
    if (object->hit(r, ray_t, temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }
  return hit_anything;
}