

#include "viewport.hpp"
#pragma once
#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#endif 

class scene {
public:
    scene();

    viewport v{{0, 0, -1}};

    int width() const;

    int height() const;

    ray cds_to_ray(unsigned x, unsigned y) const;

private:
    int m_width, m_height;
};