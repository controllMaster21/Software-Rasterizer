#include "Mesh.hpp"
#include "Camera.hpp"
#include "../Math/translation.hpp"

#include <fstream>
#include <iostream>

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
    m_file = std::ifstream(path);

    std::string line;

    for (int i = 0; m_file.peek() != EOF; i++) {
        if (line.empty()) {
            readLine(line);
            continue;
        }

        const std::string dataType = line.substr(0, 2).c_str();

        if (dataType == "v ") {
            m_vertices.push_back(getVector(line));
        } else if (dataType == "f ") {
            int idx = 2;

            std::vector<int> vertexIndices;

            for (int i = parseVertexIdx(line, idx); i >=0; i = parseVertexIdx(line, idx)) {
                vertexIndices.push_back(i);

                idx = line.find_first_of(' ', idx);

                if (idx == std::string::npos) {
                    break;
                } else {
                    idx++;
                }
            }

            m_faces.push_back(&vertexIndices);
        }
        
        readLine(line);
    }

}

float MeshFile::parseAxisValue(std::string line, int& idx) {
        std::string axisString;

        for (int& i = idx; !std::iswspace(line[i]) && i < line.size(); i++) {
            axisString.push_back(line[i]);
        }

        idx++;

        return std::stof(axisString);
}

inline vec3 MeshFile::getVector(std::string line) {
    vec3 vPos;

    int idx = 2;

    vPos.x = parseAxisValue(line, idx);
    vPos.y = parseAxisValue(line, idx);
    vPos.z = parseAxisValue(line, idx);

    return vPos;
}

int MeshFile::parseVertexIdx(std::string line, int& idx) {
    std::string vertexIdx;

    for (int& i = idx; !std::iswspace(line[i]) && line[i] != '/' && i < line.size(); i++) {
        vertexIdx.push_back(line[i]);
    }

    return vertexIdx.size() > 0 ? std::stoi(vertexIdx) : -1;
}

inline void MeshFile::readLine(std::string& line) {
    std::getline(m_file, line);
    const std::size_t idx = line.find_first_of('#');
    if (idx != line.npos) line.erase(idx);
}

Mesh MeshFile::convertToMesh() {

    Mesh out;

    for (int i = 0; i < m_faces.size(); i++) {
        std::vector<int>* vertexIndices = m_faces[i];
        if (vertexIndices->size() == 3) {
            Triangle3D tri = Triangle3D(m_vertices[vertexIndices->at(0)], m_vertices[vertexIndices->at(1)], m_vertices[vertexIndices->at(2)]);
            out.tris.push_back(tri);
        } else {
            std::cerr << "Error at face number: " << i << " " << "Number of vertices: " << vertexIndices->size() << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return out;
}