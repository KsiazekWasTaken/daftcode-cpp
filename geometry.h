//
// Created by HyperWorks on 2018-05-09.
//

#ifndef DAFTCODE_GEOMETRY_H
#define DAFTCODE_GEOMETRY_H
#define _GLIBCXX_USE_FLOAT128 1
#include <cmath>
using real_t = long double;

const double EPS = 0.000001;

constexpr double PI = acos(-1.0);

struct Point {
    real_t x;
    real_t y;

    Point(real_t _x, real_t _y) : x(_x), y(_y) {};
    bool operator==(const Point &other){
        return (x==other.x&&y==other.y);
    }
};

struct Vec {
    real_t x;
    real_t y;

    Vec(real_t _x, real_t _y) : x(_x), y(_y) {};

    Vec(Point a, Point b) : x(a.x - b.x), y(a.y - b.y) {};

    Vec(const Vec &v2) {
        x = v2.x;
        y = v2.y;
    };

    void scale(real_t s);

    real_t norm_sq();
};

real_t dot(Vec a, Vec b);

real_t cross(Vec a, Vec b);

real_t angle(Point a, Point o, Point b);

real_t isLeft(Point a, Point b1, Point b2);

bool ccw(Point a, Point b, Point c);

#endif //DAFTCODE_GEOMETRY_H
