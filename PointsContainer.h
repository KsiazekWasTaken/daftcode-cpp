//
// Created by PiotrKsiazek on 2018-05-12.
//

#ifndef DAFTCODE_POINTSCONTAINER_H
#define DAFTCODE_POINTSCONTAINER_H

#include <vector>
#include <map>
#include "Vertex.h"
#include "geometry.h"
#include "Polygon.h"

class PointsContainer {

    /**
     * Data structure representing a single tag
     */
    struct DataPoint{
        std::vector<Point> points;
        int count;

        /**
         * Increment the number of times
         * the tag has been present
         * in one of the polygons
         */
        void incCount();

        /**
         * @return the number of times
         * the tag has been present
         * in one of the polygons
         */
        int getCount();

        /**
         * @return true iff any position
         * of the tag has been in any of the polygons
         */
        bool any();

        /**
         * Add 2D point to the collection
         * of tag's positions
         * @param[in] p : 2D point
         */
        void add(Point p);

        explicit DataPoint(Point _p) : points() {
            points.push_back(_p);
            count = 0;
        }
    };


private:
    std::map<index_t,DataPoint> tags;

public:
    explicit PointsContainer(std::vector<Vertex> &vertices) : tags(){
        add(vertices);
    }

    /**
     * Add a single vertice (a point with an id)
     * to tag_id -> coordinates map
     * @param[in] a : vertice
     */
    void add(Vertex a);


    /**
     * Add a collection of vertices
     * @param[in] vertices
     */
    void add(std::vector<Vertex> vertices);


    /**
     * Check if the points in the data structure
     * are included in polygons
     * @param[in] polygons : collection of polygons
     */
    void test(std::vector<Polygon> &polygons);

};


#endif //DAFTCODE_POINTSCONTAINER_H
