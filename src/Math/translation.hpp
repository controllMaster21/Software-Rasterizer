#include "Vectors.hpp"
#include "Matrices.hpp"
#include "Triangle.hpp"

#include <cmath>

#ifndef TRANSLATION_HPP
#define TRANSLATION_HPP


vec3 rotate(vec3 v, float x, float y, float z);
Triangle3D rotate(Triangle3D tri, float x, float y, float z);

#endif