#include "Triangle.hpp"

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