//
// Created by HyperWorks on 2018-05-09.
//

#include <cmath>
#include "geometry.h"

real_t cross(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}

real_t dot(Vec a, Vec b) {
    return a.x * b.x + a.y * b.y;
}

real_t Vec::norm_sq() {
    return x * x + y * y;
}

real_t angle(Point a, Point o, Point b) {
    Vec oa{o, a};
    Vec ob{o, b};
    return acos(dot(oa, ob) / sqrt(oa.norm_sq() * ob.norm_sq()));
}

void Vec::scale(real_t s) {
    x *= s;
    y *= s;
}


real_t isLeft(Point p0, Point p1, Point p2) {
    return ( (p1.x - p0.x) * (p2.y - p0.y)
             - (p2.x -  p0.x) * (p1.y - p0.y) );
}

bool ccw(Point a, Point b, Point c) {
    Vec ab{a, b};
    Vec ac{a, c};
    return cross(ab, ac) > 0;
}
