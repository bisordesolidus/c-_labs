#include "transformations.hpp"
#include <cmath>
#include "params.hpp"


vec3 color_to_rgb(const vec3& input_color){

    int ir = int(255.999 * input_color.x());
    int ig = int(255.999 * input_color.y());
    int ib = int(255.999 * input_color.z());
    return vec3(ir, ig, ib);
}

vec3 gradient_vertical(const vec3& color_start, const vec3& color_end, int x, int y){   
    
    vec3 color_begin{color_start};
    vec3 color_finish{color_end};
    double t = double(y) / double(HEIGHT - 1);
    color_finish.scale(t);
    color_begin.scale(1 - t);
    color_finish.add(color_begin);
    color_finish.scale(0.5);
    return color_finish;
}

vec3 gradient_horizontal(const vec3& color_start, const vec3& color_end, int x, int y){   
    
    vec3 color_begin{color_start};
    vec3 color_finish{color_end};
    double t = double(x) / double(WIDTH - 1);
    color_begin.scale(1 - t);
    color_finish.scale(t);
    color_finish.add(color_begin);
    color_finish.scale(0.5);
    return color_finish;
}

vec3 invert_color(const vec3& input_color){
    
    return vec3{1, 1, 1}.sub(input_color);
}

vec3 color2bw(const vec3& input_color){
    
    double a = 1.7;
    double component = input_color.length()/a;
    return vec3(component, component, component);
}

