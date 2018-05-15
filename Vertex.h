//
// Created by PiotrKsiazek on 2018-05-09.
//

#ifndef DAFTCODE_VERTEX_H
#define DAFTCODE_VERTEX_H

#include "geometry.h"

using point_t = double;
using index_t = int;


/**
 * A structure holding
 * an index
 * and 2D coordinates
 */
class Vertex {

private:
    const index_t id;
    const Point p;

public:
    Vertex(index_t node_id, Point _p) : id(node_id), p(_p) {}

    const index_t getIndex() const;

    const Point & getPoint() const;

    bool operator==(const Vertex& other){
        return id == other.id;
    }
};

#endif //DAFTCODE_VERTEX_H
