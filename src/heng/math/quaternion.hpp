/**********************************************************************************
 * Copyright (C) 2011 by Hugo Stefan Kaus Puhlmann                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          * 
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in     *
 * all copies or substantial portions of the Software.                            *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN      *
 * THE SOFTWARE.                                                                  *
 *********************************************************************************/

#ifndef HENG_MATH_QUATERNION_HPP
#define HENG_MATH_QUATERNION_HPP

#include "vector.hpp"

namespace heng
{
namespace math
{

template <unsigned int M, unsigned int N>
struct matrix;

struct Quaternion;

typedef matrix<4, 4> mat4;

Quaternion operator *(const Quaternion& q, const Quaternion& u);
Quaternion operator +(const Quaternion& q, const Quaternion& u);
Quaternion operator *(const Quaternion& q, float s);
Quaternion operator /(const Quaternion& q, float s);
Quaternion operator *(float s, const Quaternion& q);
Quaternion operator /(float s, const Quaternion& q);
Quaternion conjugate(const Quaternion& q);
Quaternion inverse(const Quaternion& q);
Quaternion unit(const Quaternion& q);
Quaternion multIdentity();
Quaternion addIdentity();
float norm(const Quaternion& q);
mat4 quaternionToMatrix(const Quaternion& q);

struct Quaternion
{
    Quaternion();
    Quaternion(float w, const vec3& v);
    Quaternion(const vec4& quat);
    Quaternion(const Quaternion& q);
    
    float w;
    vec3 v;
};

}
} //namespace heng

#endif
