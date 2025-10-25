#include "Vectors.hpp"
#include "translation.hpp"

#include <iostream>

vec3 rotate(vec3 v, float x, float y, float z) {
    const float rotX[3][3] = {
        {1,      0,       0},
        {0, cos(x), -sin(x)},
        {0, sin(x),  cos(x)}
    };
    const mat3x3 rotXMat = mat3x3(rotX);

    const float rotY[3][3] = {
        { cos(y), 0, sin(y)},
        {      0, 1,      0},
        {-sin(y), 0, cos(y)}
    };
    const mat3x3 rotYMat = mat3x3(rotY);

    const float rotZ[3][3] = {
        { cos(z), sin(z), 0},
        {-sin(z), cos(z), 0},
        {      0,      0, 1}
    };
    const mat3x3 rotZMat = mat3x3(rotZ);

    return rotZMat * rotYMat * rotXMat * v;
}

Triangle3D rotate(Triangle3D tri, float x, float y, float z) {
    tri.p0 = rotate(tri.p0, x, y, z);
    tri.p1 = rotate(tri.p1, x, y, z);
    tri.p2 = rotate(tri.p2, x, y, z);
    return tri;
}