#include "Mesh.hpp"
#include "Camera.hpp"
#include "../Math/translation.hpp"

#include <fstream>

Mesh::Mesh() {}
Mesh::Mesh(vec3 pos, vec3 rot) : pos(pos), rot(rot) {}

Mesh Mesh::getTransformed(Camera cam) const {
    Mesh temp;
    for (Triangle3D tri : tris) {
        tri = rotate(tri, rot.x, rot.y, rot.z);
        tri += pos - cam.pos;
        tri = rotate(tri, cam.rot.x, cam.rot.y, cam.rot.z);
        temp.tris.push_back(tri);
    }
    return temp;
}

MeshFile::MeshFile(const char* path) {
    file = std::ifstream(path);

    std::string line;

    getline(file, line);
}