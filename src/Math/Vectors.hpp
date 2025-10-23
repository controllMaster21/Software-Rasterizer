#include <ostream>

#ifndef VECTORS_HPP
#define VECTORS_HPP

// 3 dimensional vector
class vec3 {
    public:
    float x;
    float y;
    float z;

    vec3();
    vec3(float xyz);
    vec3(float x, float y, float z);
    vec3(const float array[3]);

    float lenSqr() const;
    float len() const;

    vec3 normalized() const;

    static float dot(vec3 v1, vec3 v2);
    static vec3 cross(vec3 v1, vec3 v2);
};

// Operator overloads

vec3 operator +(const vec3 v1, const vec3 v2);

vec3 operator -(const vec3 v1, const vec3 v2);

vec3 operator *(const vec3 v1, const vec3 v2);
vec3 operator *(const vec3 v1, const float f);
vec3 operator *(const float f, const vec3 v1);

vec3 operator /(const vec3 v1, const float d);


vec3& operator +=(vec3& v1, const vec3 v2);

vec3& operator -=(vec3& v1, const vec3 v2);

vec3& operator *=(vec3& v1, const vec3 v2);
vec3& operator *=(vec3& v1, const float f);

vec3& operator /=(vec3& v1, const float d);

std::ostream& operator <<(std::ostream& stream, const vec3 v);

// 2 dimensional vector
class vec2 {
    public:
    float x;
    float y;

    vec2();
    vec2(float xy);
    vec2(float x, float y);

    float lenSqr() const;
    float len() const;

    vec2 normalized() const;

    static float dot(vec2 v1, vec2 v2);
};

// Operator overloads

vec2 operator +(const vec2 v1, const vec2 v2);

vec2 operator -(const vec2 v1, const vec2 v2);

vec2 operator *(const vec2 v1, const vec2 v2);
vec2 operator *(const vec2 v1, const float f);
vec2 operator *(const float f, const vec2 v1);

vec2 operator /(const vec2 v1, const float d);


vec2& operator +=(vec2& v1, const vec2 v2);

vec2& operator -=(vec2& v1, const vec2 v2);

vec2& operator *=(vec2& v1, const vec2 v2);
vec2& operator *=(vec2& v1, const float f);

vec2& operator /=(vec2& v1, const float d);

std::ostream& operator <<(std::ostream& stream, const vec2 v);

#endif