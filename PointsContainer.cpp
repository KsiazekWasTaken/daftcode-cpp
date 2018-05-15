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
    auto it = tags.find(a.getIndex());
    if(it==tags.end()){
        DataPoint d{a.getPoint()};
        tags.emplace(a.getIndex(), d);
    } else {
        (it->second).add(a.getPoint());
    }
}

void PointsContainer::test(std::vector<Polygon> &polygons) {
    int best_index = -1;
    int best_count = -1;
    std::vector<index_t> in_none;


    for (auto &tag : tags) {                                        //for each tag
        for(auto &point : tag.second.points){                       //for each position
            for(auto &polygon : polygons){                          //for each polygon
                bool res = polygon.contains(tag.first, point);   //test if the point is included in the polygon
                if(res){
                    tag.second.incCount(); //increment the number of times the tag was present in polygons
                }
            }
        }
    }


    for (auto &tag : tags) {                     //for each tag
        if(tag.second.getCount() > best_count){  //find most often tag
            best_count = tag.second.getCount();
            best_index = tag.first;
        }
        if(tag.second.getCount() == 0){
            in_none.push_back(tag.first); //remember the tags that weren't included in any polygon
        }
    }

    std::cout << "Most often:\n" << best_index << std::endl;
    std::cout << "Don't belong to any:\n";
    for(auto a : in_none){
        std::cout << a << " " << std::endl;
    }
}
