#include "../Math/Vectors.hpp"
#include "../Math/Triangle.hpp"
#include "Camera.hpp"

#include <vector>

#ifndef MESH_HPP
#define MESH_HPP

class Mesh {
    public:
    vec3 pos;
    vec3 rot;

    std::vector<Triangle3D> tris;

    Mesh();
    Mesh(vec3 pos, vec3 rot);

    Mesh getTransformed(Camera cam) const;
};

#endif