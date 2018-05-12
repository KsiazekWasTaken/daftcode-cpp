//
// Created by HyperWorks on 2018-05-09.
//

#ifndef DAFTCODE_VERTEX_H
#define DAFTCODE_VERTEX_H

#include "geometry.h"

using point_t = double;
using index_t = int;

class Vertex {

private:
    const index_t id;
    Point p;
    int count;

public:
    Vertex(index_t node_id, Point _p) : id(node_id), p(_p) {
        count = 0;
    }

    index_t getIndex();

    const Point getPoint();

    void setPoint(Point _p);

    void incCount();

    int getCount();

    bool any();

    bool operator==(const Vertex& other){
        return id == other.id;
    }
};

#endif //DAFTCODE_VERTEX_H
