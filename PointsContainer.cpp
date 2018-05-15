//
// Created by PiotrKsiazek on 2018-05-12.
//

#include <iostream>
#include "PointsContainer.h"


void PointsContainer::DataPoint::incCount(){
    ++count;
}

int PointsContainer::DataPoint::getCount(){
    return count;
}

bool PointsContainer::DataPoint::any(){
    return count!=0;
}

void PointsContainer::DataPoint::add(Point p){
    points.push_back(p);
}

void PointsContainer::add(std::vector<Vertex> vertices) {
    for(auto v : vertices){
        add(v);
    }
}

void PointsContainer::add(Vertex a) {
    auto it = coordinates.find(a.getIndex());
    if(it==coordinates.end()){
        DataPoint d{a.getPoint()};
        coordinates.emplace(a.getIndex(), d);
    } else {
        (it->second).add(a.getPoint());
    }
}

void PointsContainer::test(std::vector<Polygon> &polygons) {
    int best_index = -1;
    int best_count = -1;
    std::vector<index_t> in_none;


    for (auto &coordinate : coordinates) { //for each tag
        for(auto &point : coordinate.second.points){ //for each position
            for(auto &polygon : polygons){ //for each polygon
                bool res = polygon.contains(coordinate.first, point); //test if the point is included in the polygon
                if(res){
                    coordinate.second.incCount(); //increment the number of times the tag was present in polygons
                }
            }
        }
    }


    for (auto &coordinate : coordinates) { //for each tag
        if(coordinate.second.getCount() > best_count){ //find most often tag
            best_count = coordinate.second.getCount();
            best_index = coordinate.first;
        }
        if(coordinate.second.getCount() == 0){
            in_none.push_back(coordinate.first); //remember the tags that weren't included in any polygon
        }
    }

    std::cout<< "Most often:\n" << best_index << std::endl;
    std::cout << "Don't belong to any:\n";
    for(auto a : in_none){
        std::cout << a << " " << std::endl;
    }
}
