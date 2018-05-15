//
// Created by PiotrKsiazek on 2018-05-12.
//

#ifndef DAFTCODE_PARSE_H
#define DAFTCODE_PARSE_H

#include <string>
#include "geometry.h"
#include "Vertex.h"
#include "Polygon.h"

/**
 * Reads vertices from a file provided
 * Expected format:
 * id, x, y
 * Optionally a header
 * @param[in] file path : to the file
 * @param[in] skip_header : skip the first row if true
 * @return vector of vertices read from file
 */
std::vector<Vertex> readVertices(std::string file, bool skip_header);


/**
 * Reads polygons from a file provided
 * Expected format:
 * id,node_id[..] separated by comma
 * @param[in] file : path to the file
 * @param[in] vertices : vector of nodes
 * @param[in] skip_header : skip the first row if true
 * @return vector of polygons read from file
 */
std::vector<Polygon> readPolygons(std::string file, std::vector<Vertex> vertices, bool skip_header);


#endif //DAFTCODE_PARSE_H
