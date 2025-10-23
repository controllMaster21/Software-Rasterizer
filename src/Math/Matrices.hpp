#include "Vectors.hpp"

#ifndef MATRICES_HPP
#define MATRICES_HPP

class mat3x3 {
    public:
    float values[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    mat3x3();
    mat3x3(const float values[3][3]);

    vec3 row(int idx) const;
    vec3 col(int idx) const;
};

vec3 operator *(const vec3 v, const mat3x3 m);
vec3 operator *(const mat3x3 m, const vec3 v);
mat3x3 operator *(const mat3x3 m1, const mat3x3 m2);

#endif