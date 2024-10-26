#include "camera.hpp"

    void camera::render(std::ofstream &os, const hittable& world) {
        initialize();
        std::cout << pixel_delta_u.x() << ' ' << pixel_delta_u.y() << ' ' << pixel_delta_u.z();
        std::cout << pixel_delta_v.x() << ' ' << pixel_delta_v.y() << ' ' << pixel_delta_v.z();
        os << "P3\n" << image_height << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; j++) {
            std::cout << "\rScanlines remaining: " << (image_height - j) << ' ' << std::endl;
            for (int i = 0; i < image_width; i++) {
                /*auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
                auto ray_direction = pixel_center - center;
                ray r(center, ray_direction);

                vec3 pixel_color = ray_color(r, world);
                write_color(os, pixel_color);*/
                vec3 pixel_color(0,0,0);
                for (int sample = 0; sample < samples_per_pixel; sample++) {
                    ray r = get_ray(i, j);
                    pixel_color = pixel_color + ray_color(r, max_reflection, world);
                }
                write_color(os, pixel_samples_scale * pixel_color);
            }
        }

        std::clog << "\rDone.                 \n";
    }

    void camera::initialize() {

        center = vec3(0, 0, 0);
        pixel_samples_scale = 1.0 / samples_per_pixel;
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (aspect_ratio);

        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);

        pixel_delta_u = viewport_u / image_height;
        pixel_delta_v = viewport_v / image_width;

        auto viewport_upper_left =
            center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }


    ray camera::get_ray(int i, int j) const {

        auto offset = sample_square();
        auto pixel_sample = pixel00_loc
                          + ((i + offset.x()) * pixel_delta_u)
                          + ((j + offset.y()) * pixel_delta_v);

        auto ray_origin = center;
        auto ray_direction = pixel_sample - ray_origin;

        return ray(ray_origin, ray_direction);
    }

vec3 camera::sample_square() const {
    return vec3(random_double() - 0.5, random_double() - 0.5, 0);
}


vec3 camera::ray_color(const ray& r, int depth, const hittable& world) const {
    if (depth<=0){
        return vec3(0,0,0);
    }
    
    hit_record rec;
    if (world.hit(r, interval(0.0001, infinity), rec)) {
        vec3 N = random_on_hemisphere(rec.normal);
        return 0.5 * ray_color(ray(rec.point, N), depth-1, world);
        //vec3 N = unit_vector(r.at(rec.t) - vec3(0,0,-1));
        //return 0.5*vec3(N.x()+1, N.y()+1, N.z()+1);
    };
    vec3 unit_direction = unit_vector(r.m_direction);
    double t = 0.5 * (unit_direction.y() + 1.0);
    return ((1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0)); 
}

