//
// Created by PiotrKsiazek on 2018-05-12.
//

#include "read_data.h"
#include <fstream>
#include <iostream>
#include <map>


std::vector<Vertex> readVertices(std::string file, bool skip_header){

    std::ifstream vertices_data(file);
    if (!vertices_data.is_open()) {
        exit(1);
    }
    index_t id;
    real_t x;
    real_t y;
    std::string line;
    std::vector<Vertex> vertices;

    if(skip_header)
        getline(vertices_data, line);

    while(getline(vertices_data, line)){
        size_t pos = 0;
        std::string token;
        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 2);
        id = stoi(token);

        pos = line.find(",");
        token = line.substr(0, pos);
        line.erase(0, pos + 2);
        x = stold(token);

        y = stold(line);
        vertices.emplace_back(id, Point(x,y));
    }
    vertices_data.close();


    return vertices;
}

std::vector<Polygon> readPolygons(std::string file, std::vector<Vertex> vertices, bool skip_header){
    index_t id;
    std::string line;
    std::vector<Polygon> polygons;
    std::ifstream polygons_data(file);
    std::map<index_t, int> id2idx;
    for(int i=0; i < vertices.size(); ++i){
        auto v = vertices[i];
        id2idx[v.getIndex()] = i;
    }

    if(skip_header)
        getline(polygons_data, line);

    while(getline(polygons_data, line)) {
        size_t pos = 0;
        std::string token;
        std::string delimiter;

        delimiter = ",";
        pos = line.find(delimiter); //get id
        token = line.substr(0, pos);
        id = stoi(token);
        line.erase(0, pos + delimiter.length());

        std::vector<index_t> tmp; //get vertices list
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            tmp.push_back(stoi(token));
            line.erase(0, pos + delimiter.length());
        }
        tmp.push_back(stoi(line));

        polygons.emplace_back(id2idx[id], tmp, vertices);
        tmp.clear();
    }
    polygons_data.close();


    return polygons;
}

