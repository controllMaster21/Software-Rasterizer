#include "Vectors.hpp"

#include <cmath>
#include <iostream>

// Constructors
vec3::vec3() : x(0), y(0), z(0) {}
vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}
vec3::vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}
vec3::vec3(const float array[3]) : x(array[0]), y(array[1]), z(array[2]) {}

vec2::vec2() : x(0), y(0) {}
vec2::vec2(float x, float y) : x(x), y(y) {}
vec2::vec2(float xy) : x(xy), y(xy) {}

// Operators
vec3 operator +(vec3 v1, vec3 v2) {
    return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

vec3 operator -(vec3 v1, vec3 v2) {
    return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}
vec3 operator -(vec3 v) {
    return vec3(-v.x, -v.y, -v.z);
}

vec3 operator *(vec3 v1, vec3 v2) {
    return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}
vec3 operator *(vec3 v, float f) {
    return vec3(v.x * f, v.y * f, v.z * f);
}
vec3 operator *(float f, vec3 v) {
    return vec3(v.x * f, v.y * f, v.z * f);
}

vec3 operator /(vec3 v1, float d) {
    return vec3(v1.x / d, v1.y / d, v1.z / d);
}

vec3& operator +=(vec3& v1, vec3 v2) {
    v1 = v1 + v2;
    return v1;
}
vec3& operator -=(vec3& v1, vec3 v2) {
    v1 = v1 - v2;
    return v1;
}

std::ostream& operator <<(std::ostream& stream, const vec3 v) {
    stream << "\nx: " << v.x << "\ny: " << v.y << "\nz: " << v.z;
    return stream;
}

vec2 operator +(vec2 v1, vec2 v2) {
    return vec2(v1.x + v2.x, v1.y + v2.y);
}

vec2 operator -(vec2 v1, vec2 v2) {
    return vec2(v1.x - v2.x, v1.y - v2.y);
}
vec2 operator -(vec2 v) {
    return vec2(-v.x, -v.y);
}

vec2 operator *(vec2 v1, vec2 v2) {
    return vec2(v1.x * v2.x, v1.y * v2.y);
}
vec2 operator *(vec2 v, float f) {
    return vec2(v.x * f, v.y * f);
}
vec2 operator *(float f, vec2 v) {
    return vec2(v.x * f, v.y * f);
}

vec2 operator /(vec2 v, float d) {
    return vec2(v.x / d, v.y / d);
}

// Vector functions
float vec3::lenSqr() const {
    return x*x + y*y + z*z;
}

float vec3::len() const {
    return sqrt(lenSqr());
}

float vec3::dot(vec3 v1, vec3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vec3 vec3::cross(vec3 v1, vec3 v2) {
    return vec3(v1.y * v2.z, v1.z * v2.x, v1.x * v2.y);
}

vec3 vec3::normalized() const {
    return *this / len();
}


float vec2::lenSqr() const {
    return x*x + y*y;
}

float vec2::len() const {
    return sqrt(lenSqr());
}

vec2 vec2::normalized() const {
    return *this / len();
}

float vec2::dot(vec2 v1, vec2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}