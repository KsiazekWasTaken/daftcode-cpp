//
// Created by HyperWorks on 2018-05-09.
//

#include <cmath>
#include <iostream>
#include "Polygon.h"

const float EPS_2 = 0.0001;

bool Polygon::contains(Vertex a) {
    bool res = contains_faster(a.getPoint());
    if (res) {
        tags.insert(a.getIndex());
    }
    return res;
}


bool Polygon::contains(index_t id, Point p) {
    bool res = contains_faster(p);
    if (res) {
        tags.insert(id);
    }
    return res;
}


bool Polygon::contains_wn(Point p) {
    auto size = vertices.size();
    if (size == 0) return false;
    real_t sum = 0;
    for (int i = 0; i < size - 1; ++i) {
        auto v1 = vertices[i].getPoint();
        auto v2 = vertices[i + 1].getPoint();
        if (ccw(p, v1, v2)) {
            sum += angle(v1, p, v2);
        } else {
            sum -= angle(v1, p, v2);
        }
    }
    return fabs(fabs(sum) - 2 * PI) < EPS;
}

bool Polygon::contains_faster(Point p) {
    int wn = 0;    // the  winding number counter
    int size = vertices.size();
    real_t le;
    // loop through all edges of the polygon
    for (int i = 0; i < size - 1; i++) {   // edge from V[i] to  V[i+1]
        auto v1 = vertices[i].getPoint();
        if(v1==p) return true;
        auto v2 = vertices[i + 1].getPoint();
        if(v2==p) return true;
        if (v1.y <= p.y) {          // start y <= P.y
            if (v2.y > p.y) {    // an upward crossing
                le = isLeft(v1, v2, p);
                if (le > EPS_2)  // P left of  edge
                    ++wn;            // have  a valid up intersect
                else if (fabs(le) < EPS_2)
                    return true;
            }
        } else {                        // start y > P.y (no test needed)
            if (v2.y <= p.y) {     // a downward crossing
                le = isLeft(v1, v2, p);
                if (le < -EPS_2)  // P right of  edge
                    --wn;            // have  a valid down intersect
                else if (fabs(le) < EPS_2) {
                    return true;
                }
            }
        }
    }
    return (wn != 0);
}

const std::set<index_t> &Polygon::getTags() const {
    return tags;
}
