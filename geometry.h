//
// Created by PiotrKsiazek on 2018-05-09.
//

#ifndef DAFTCODE_GEOMETRY_H
#define DAFTCODE_GEOMETRY_H
#define _GLIBCXX_USE_FLOAT128 1
#include <cmath>
using real_t = long double;


/***
 * Epsilon for float comparison
 */
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


/**
 * Vector structure
 */
struct Vec {
    real_t x;
    real_t y;

    Vec(real_t _x, real_t _y) : x(_x), y(_y) {};

    Vec(Point a, Point b) : x(a.x - b.x), y(a.y - b.y) {};

    Vec(const Vec &v2) {
        x = v2.x;
        y = v2.y;
    };


    /***
     * Scale vector by scale s
     * @param[in] s
     */
    void scale(real_t s);


    /***
     * @return norm squared
     */
    real_t norm_sq();
};


/**
 * @param[in] a : vector
 * @param[in] b : vector
 * @return dot product of vectors a and b
 */
real_t dot(Vec a, Vec b);


/**
 * @param[in] a vector
 * @param[in] b vector
 * @return cross product of vectors a nad b
 */
real_t cross(Vec a, Vec b);


/**
 * @param[in] a : 2D point
 * @param[in] o : 2D point
 * @param[in] b : 2D point
 * @return angle aob in radians
 */
real_t angle(const Point &a, const Point &o, const Point &b);

/**
 * @param[in] a : 2D point
 * @param[in] b1 : 2D point, first point to determine a line
 * @param[in] b2 : 2D point, second point to determine a line
 * @return
 */
real_t isLeft(const Point &a, const Point &b1, const Point &b2);

bool ccw(Point a, Point b, Point c);

#endif //DAFTCODE_GEOMETRY_H
