#include <iostream>
#include "Vertex.h"
#include "Polygon.h"
#include "parse.h"
#include "PointsContainer.h"
#include <iomanip>
int main(int argc, char *argv[]) {
    using namespace std;


    vector<Vertex> vertices = readVertices("..\\nodes.csv", true);
    vector<Polygon> polygons = readPolygons("..\\polygons.csv", vertices, false);
    vector<Vertex> points = readVertices("..\\cpp_points_data.csv", true);


    PointsContainer pc(points);


    pc.test(polygons);


    for(Polygon& poly : polygons){
        cout << "Polygon " << poly.getId() << " contains:\n";
        for(auto x : poly.getTags()){
            cout << x << endl;
        }
    }


    return 0;
}