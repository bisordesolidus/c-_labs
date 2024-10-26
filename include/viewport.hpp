#pragma once

#include "ray.hpp"

#ifndef MAIN_VIEWPORT_H
#define MAIN_VIEWPORT_H
#endif

class viewport {

public:
    viewport();

    viewport(vec3 focal_vec);

    vec3 get_center() const;

    vec3 get_u() const;

    vec3 get_v() const;

private:
    double m_width, m_height;
    vec3 center = {0, 0, 10};
    vec3 m_u = {1, 0, 0},
            m_v = {0, -1, 0};
};