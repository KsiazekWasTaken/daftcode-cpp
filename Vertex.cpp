//
// Created by HyperWorks on 2018-05-09.
//

#include "Vertex.h"


index_t Vertex::getIndex() { return id; }

const Point Vertex::getPoint() { return p; }

void Vertex::setPoint(Point _p) {
    p = _p;
}

void Vertex::incCount(){
    count++;
}

int Vertex::getCount(){
    return count;
}

bool Vertex::any(){
    return count!=0;
}
