cmake_minimum_required(VERSION 3.8)
project(daftcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vertex.cpp Vertex.h Polygon.cpp Polygon.h geometry.h geometry.cpp parse.h parse.cpp PointsContainer.cpp PointsContainer.h PointCounter.cpp PointCounter.h)
add_compile_options(-g)
add_executable(daftcode ${SOURCE_FILES})