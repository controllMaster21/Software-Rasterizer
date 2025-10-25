#include "Vectors.hpp"
#include "Bounds.hpp"

#include <SDL2/SDL_rect.h>

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle2D;

class Triangle3D {
    public:
    vec3 p0;
    vec3 p1;
    vec3 p2;

    Triangle3D(vec3 p0, vec3 p1, vec3 p2);

    Triangle2D to2D();
};

Triangle3D operator +(vec3 v, Triangle3D tri);
Triangle3D operator +(Triangle3D tri, vec3 v);

Triangle3D operator -(vec3 v, Triangle3D tri);
Triangle3D operator -(Triangle3D tri, vec3 v);

Triangle3D& operator +=(Triangle3D& tri, vec3 v);
Triangle3D& operator -=(Triangle3D& tri, vec3 v);

class Triangle2D {
    public:
    vec2 p0;
    vec2 p1;
    vec2 p2;

    Triangle2D(vec2 p0, vec2 p1, vec2 p2);

    bool pointInside(vec2 p) const;
    const Bounds getBounds() const;

    float sign() const;
    static float sign(vec2 p0, vec2 p1, vec2 p2);
};

#endif