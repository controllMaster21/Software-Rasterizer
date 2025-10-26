#include "../Math/Vectors.hpp"
#include "../Math/Triangle.hpp"
#include "Camera.hpp"

#include <fstream>
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

class MeshFile {
    public:
    MeshFile(const char* path);

    Mesh convertToMesh();

    private:
    std::ifstream m_file;
    std::vector<vec3> m_vertices;
    std::vector<std::vector<int>*> m_faces;

    float parseAxisValue(std::string line, int& idx);
    inline vec3 getVector(std::string line);
    
    int parseVertexIdx(std::string line, int& idx);

    inline void readLine(std::string& line);
};

#endif