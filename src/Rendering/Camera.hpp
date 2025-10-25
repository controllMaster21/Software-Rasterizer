#include "../Math/Vectors.hpp"

#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera {
    public:
    vec3 pos;
    vec3 rot = vec3(0, 0, 1);

    Camera();
};

#endif