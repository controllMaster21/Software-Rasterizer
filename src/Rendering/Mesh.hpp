#include "Vectors.hpp"
#include "Triangle.hpp"

#include <vector>

#ifndef MESH_HPP
#define MESH_HPP

class Mesh {
    vec3 pos;
    vec3 rot;

    std::vector<Triangle3D> tris;

    Mesh();
};

#endif