#include "Vectors.hpp"

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle3D {
    public:
    vec3 p0;
    vec3 p1;
    vec3 p2;

    Triangle3D(vec3 p0, vec3 p1, vec3 p2);
};

class Triangle2D {
    public:
    vec2 p0;
    vec2 p1;
    vec2 p2;

    Triangle2D(vec2 p0, vec2 p1, vec2 p2);

    bool pointInside(vec2 p) const;

    float sign() const;
    static float sign(vec2 p0, vec2 p1, vec2 p2);
};

#endif