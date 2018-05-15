//
// Created by PiotrKsiazek on 2018-05-09.
//

#ifndef DAFTCODE_POLYGON_H
#define DAFTCODE_POLYGON_H

#include <vector>
#include <set>
#include <cstdio>
#include "Vertex.h"

class Polygon {
private:
    const index_t id;
    std::vector<Vertex> vertices;
    std::set<index_t> tags;

    /**
     * Standard implementation of WN algorithm,
     * from Competitive Programming 3
     * @param[in] p : 2D point
     * @return true iff the polygon contains the point p
     */
    bool contains_wn(const Point &p);

    /**
     * Alternative implementation of WN algorithm
     * believed to have a better performance
     * it also catches points on the edges
     * http://geomalgorithms.com/a03-_inclusion.html
     * https://stackoverflow.com/questions/37703202/winding-number-algorithm-and-point-on-boundary-edge-of-convex?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
     * @param[in] p : 2D point
     * @return true if the polygon contains the point p
     */
    bool contains_wn_improved(const Point &p);

public:
    Polygon(index_t poly_id, std::vector<index_t> &vertices_list, std::vector<Vertex> &global_vertices) : id(poly_id),
                                                                                                    vertices(), tags() {
        for (auto x : vertices_list) {
            vertices.push_back(global_vertices[x]);
        }
    };

    bool contains(const Vertex &a);

    bool contains(index_t id, const Point &p);

    index_t getId() { return id; }

    const std::set<index_t> &getTags() const;

    /**
     * Reset polygon's tag set
     */
    void reset();
};


#endif //DAFTCODE_POLYGON_H
