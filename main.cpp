#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Vertex.h"
#include "Polygon.h"
#include "read_data.h"
#include "PointsContainer.h"

int main(int argc, char *argv[]) {
    using namespace std;
    string nodes_file = "..\\nodes.csv";
    string polygons_file = "..\\polygons.csv";
    string points_file = "..\\cpp_points_data.csv";

    if(argc == 1){
        cerr << "Using default input files" << endl;
    } else if (argc != 3) {
        cerr << "Usage: " << argv[0] << " nodes_file polygons_file points_file" << endl;
    } else {
        nodes_file = string(argv[1]);
        polygons_file = string(argv[2]);
        points_file = string(argv[3]);
    }

    vector<Vertex> vertices = readVertices("..\\nodes.csv", true);
    vector<Polygon> polygons = readPolygons("..\\polygons.csv", vertices, false);
    vector<Vertex> points = readVertices("..\\cpp_points_data.csv", true);

    PointsContainer pc(points);

    pc.test(polygons);

    for(Polygon& poly : polygons){
        cout << "Polygon " << poly.getId() << " contains:\n";
        for(auto tag : poly.getTags()){
            cout << tag << endl;
        }
    }

    auto set_poly_1 = polygons[1].getTags();
    auto set_poly_2 = polygons[2].getTags();
    std::vector<int> diff;

    std::set_difference(set_poly_1.begin(), set_poly_1.end(),
                        set_poly_2.begin(), set_poly_2.end(),
                        std::inserter(diff, diff.begin()));

    cout << "In polygon 1 but not in polygon 2: " << endl;
    for(index_t tag : diff){
        cout << tag << endl;
    }

    for(auto &p : polygons)
        p.reset();

    return 0;
}