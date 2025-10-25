#include "Triangle.hpp"
#include "Bounds.hpp"

#include <bits/stdc++.h>

Triangle3D::Triangle3D(vec3 p0, vec3 p1, vec3 p2) : p0(p0), p1(p1), p2(p2) {}

Triangle2D Triangle3D::to2D() {
    const float zoom = 100;
    return Triangle2D(vec2(p0.x, p0.y) * zoom / p0.z, vec2(p1.x, p1.y) * zoom / p1.z, vec2(p2.x, p2.y) * zoom / p2.z);
}

Triangle3D operator +(vec3 v, Triangle3D tri) {
    tri.p0 += v;
    tri.p1 += v;
    tri.p2 += v;
    return tri;
}
Triangle3D operator +(Triangle3D tri, vec3 v) {
    tri.p0 += v;
    tri.p1 += v;
    tri.p2 += v;
    return tri;
}

Triangle3D operator -(vec3 v, Triangle3D tri) {
    tri.p0 -= v;
    tri.p1 -= v;
    tri.p2 -= v;
    return tri;
}
Triangle3D operator -(Triangle3D tri, vec3 v) {
    tri.p0 -= v;
    tri.p1 -= v;
    tri.p2 -= v;
    return tri;
}

Triangle3D& operator +=(Triangle3D& tri, vec3 v) {
    tri = tri + v;
    return tri;
}
Triangle3D& operator -=(Triangle3D& tri, vec3 v) {
    tri = tri - v;
    return tri;
}

Triangle2D::Triangle2D(vec2 p0, vec2 p1, vec2 p2) : p0(p0), p1(p1), p2(p2) {}

float Triangle2D::sign() const {
    return (p0.x - p2.x) * (p1.y - p2.y) - (p1.x - p2.x) * (p0.y - p2.y);
}

float Triangle2D::sign(vec2 p0, vec2 p1, vec2 p2) {
    return (p0.x - p2.x) * (p1.y - p2.y) - (p1.x - p2.x) * (p0.y - p2.y);
}

bool Triangle2D::pointInside(vec2 p) const {
    bool has_neg, has_pos;

    const float d0 = sign(p, p0, p1);
    const float d1 = sign(p, p1, p2);
    const float d2 = sign(p, p2, p0);

    has_neg = (d0 < 0) || (d1 < 0) || (d2 < 0);
    has_pos = (d0 > 0) || (d1 > 0) || (d2 > 0);

    return !(has_neg && has_pos);
}

const Bounds Triangle2D::getBounds() const {
    const float minX = std::min({p0.x, p1.x, p2.x});
    const float maxX = std::max({p0.x, p1.x, p2.x});

    const float minY = std::min({p0.y, p1.y, p2.y});
    const float maxY = std::max({p0.y, p1.y, p2.y});

    return {minX, minY, maxX, maxY};
}