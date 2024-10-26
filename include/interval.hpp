#pragma once
#include <limits>


#ifndef INTERVAL_H
#define INTERVAL_H


const double infinity = std::numeric_limits<double>::infinity();

class interval {
  public:
    double min, max;
    interval() : min(+infinity), max(-infinity) {}

    interval(double min, double max) : min(min), max(max) {}

    double size() const;

    bool contains(double x) const;

    bool surrounds(double x) const;
    
    double clamp(double x) const;

    static const interval empty, universe;

};
/*const interval interval::empty    = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);
*/

#endif