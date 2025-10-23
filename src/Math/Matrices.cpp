#include "Matrices.hpp"

mat3x3::mat3x3() {}
mat3x3::mat3x3(const float src[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            values[i][j] = src[i][j];
        }
    }
}

vec3 operator *(const vec3 v, const mat3x3 m) {
    vec3(vec3::dot(m.col(0), v), vec3::dot(m.col(1), v), vec3::dot(m.col(2), v));
}
vec3 operator *(const mat3x3 m, const vec3 v) {
    vec3(vec3::dot(m.row(0), v), vec3::dot(m.row(1), v), vec3::dot(m.row(2), v));
}
mat3x3 operator *(const mat3x3 m1, const mat3x3 m2) {
    mat3x3 m;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; i++) {
            m.values[i][j] = vec3::dot(m1.row(i), m2.col(j));
        }
    }
}

vec3 mat3x3::row(int idx) const {
    return vec3(values[idx]);
}

vec3 mat3x3::col(int idx) const {
    return vec3(values[0][idx], values[1][idx], values[2][idx]);
}