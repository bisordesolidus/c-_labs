#include "viewport.hpp"
#include "params.hpp"

viewport::viewport() {
    // int width = WIDTH;
    // int height = int(width / RATIO);
    // height = (height < 1) ? 1 : height;

    // m_height = 2.0;
    // m_width = m_height * (double(width) / height);

    // m_u = m_u * m_width;
    // m_v = m_v * m_height;
}

viewport::viewport(vec3 focal_vec) : viewport() {
    center = focal_vec;
    m_u = unit_vector((focal_vec ^ vec3{0, 1, 0})) * m_width;
    m_v = unit_vector((focal_vec ^ m_u)) * m_height;
}

vec3 viewport::get_center() const {
    return center;
}

vec3 viewport::get_u() const {
    return m_u;
}

vec3 viewport::get_v() const {
    return m_v;
}