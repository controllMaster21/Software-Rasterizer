#include "Mesh.hpp"
#include "Camera.hpp"

#include <vector>

#ifndef SCENE_HPP
#define SCENE_HPP

class Scene {
    public:
    Camera cam;
    std::vector<Mesh> meshes;

    Scene();

    std::vector<Mesh> getTransformed() {
        std::vector<Mesh> buffer = meshes;
        for (Mesh& mesh : buffer) {
            mesh = mesh.getTransformed(cam);
        }
        return buffer;
    }
};

#endif
