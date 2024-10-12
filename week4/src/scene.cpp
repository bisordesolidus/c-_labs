#include "scene.hpp"
#include "params.hpp"

scene::scene() {
    m_width = WIDTH;
    m_height = int(m_width / RATIO);
    m_height = (m_height < 1) ? 1 : m_height;
}

int scene::width() const {
    return m_width;
}

int scene::height() const {
    return m_height;
}

ray scene::cds_to_ray(unsigned int x, unsigned int y) const {
    return ray(vec3(0,0,0), v.get_center() + (double(x) / m_width - .5) * v.get_u() + (double(y) / m_height - .5) * v.get_v());
}