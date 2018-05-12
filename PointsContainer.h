//
// Created by HyperWorks on 2018-05-12.
//

#ifndef DAFTCODE_POINTSCONTAINER_H
#define DAFTCODE_POINTSCONTAINER_H

#include <vector>
#include <map>
#include "Vertex.h"
#include "geometry.h"
#include "Polygon.h"

class PointsContainer {
    struct DataPoint{
        std::vector<Point> points;
        int count;

        void incCount();

        int getCount();

        bool any();

        void add(Point p);

        explicit DataPoint(Point _p) : points() {
            points.push_back(_p);
            count = 0;
        }
    };


private:
    std::map<index_t,DataPoint> coordinates;
    std::map<index_t, index_t> old2new;
    std::vector<index_t> new2old;

public:
    explicit PointsContainer(std::vector<Vertex> &vertices) : coordinates(){
        add(vertices);
    }

    void add(Vertex a);

    void add(std::vector<Vertex> vertices);

    void test(std::vector<Polygon> &polygons);

};


#endif //DAFTCODE_POINTSCONTAINER_H
