//
// Created by HyperWorks on 2018-05-09.
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
public:
    const std::set<index_t> &getTags() const;

private:

    bool contains_wn(Point p);

    bool contains_faster(Point p);

public:
    Polygon(index_t poly_id, std::vector<index_t> &vertices_list, std::vector<Vertex> &global_vertices) : id(poly_id),
                                                                                                    vertices(), tags() {
        for (auto x : vertices_list) {
            vertices.push_back(global_vertices[x]);
        }
    };

    void print() {
        for (auto v : vertices) {
            printf("%.2Lf|%.2Lf ", v.getPoint().x, v.getPoint().y);
        }
        printf("\n");
    }

    bool contains(Vertex a);

    bool contains(index_t id, Point p);

    index_t getId() { return id; }
};


#endif //DAFTCODE_POLYGON_H
