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

#include "quaternion.hpp"
#include "matrix.hpp"

namespace heng
{
namespace math
{

Quaternion operator *(const Quaternion& q, const Quaternion& u)
{
    vec3 a = q.v;
    vec3 b = u.v;
    
    float w = q.w * u.w - dot(a, b);
    vec3 r = cross(a, b);
    vec3 s = b * q.w;
    vec3 t = a * u.w;

    return Quaternion(w, r + s + t);
}

Quaternion operator +(const Quaternion& q, const Quaternion& u)
{
    return Quaternion(q.w + u.w, q.v + u.v); 
}

Quaternion operator *(const Quaternion& q, float s)
{
    return Quaternion(q.w*s, q.v*s);
}

Quaternion operator /(const Quaternion& q, float s)
{
    return Quaternion(q.w/s, q.v/s);
}

Quaternion operator *(float s, const Quaternion& q)
{
    return Quaternion(q.w*s, q.v*s);
}

Quaternion operator /(float s, const Quaternion& q)
{
    return Quaternion(q.w/s, q.v/s);
}

Quaternion conjugate(const Quaternion& q)
{
    return Quaternion(q.w, q.v * -1.f);
}

Quaternion inverse(const Quaternion& q)
{
    return conjugate(q)/norm(q);
}

Quaternion unit(const Quaternion& q)
{
   return q/norm(q); 
}

Quaternion multIdentity()
{
    return Quaternion(1.f, makeVec(0.f, 0.f, 0.f));
}

Quaternion addIdentity()
{
    return Quaternion(0.f, makeVec(0.f, 0.f, 0.f));
}

float norm(const Quaternion& q)
{
    return q.w * q.w + q.v[0]*q.v[0] + q.v[1]*q.v[1] + q.v[2]*q.v[2]; 
}

mat4 quaternionToMatrix(const Quaternion& q)
{
    float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
    mat4 m;
    
    x2 = q.v[0] + q.v[0];
    y2 = q.v[1] + q.v[1];
    z2 = q.v[2] + q.v[2];
    
    xx = q.v[0] * x2; 
    xy = q.v[0] * y2; 
    xz = q.v[0] * z2;
    yy = q.v[1] * y2; 
    yz = q.v[1] * z2; 
    zz = q.v[2] * z2;
    wx = q.w * x2; 
    wy = q.w * y2; 
    wz = q.w * z2;

    m(0,0) = 1.0f - (yy + zz); 
    m(1,0) = xy - wz;
    m(2,0) = xz + wy; 
    m(3,0) = 0.0f;

    m(0,1) = xy + wz; 
    m(1,1) = 1.f - (xx + zz);
    m(2,1) = yz - wx; 
    m(3,1) = 0.f;

    m(0,2) = xz - wy; 
    m(1,2) = yz + wx;
    m(2,2) = 1.f - (xx + yy); 
    m(3,2) = 0.f;

    m(0,3) = 0.f; 
    m(1,3) = 0.f;
    m(2,3) = 0.f; 
    m(3,3) = 1.f;

    return m;
}

Quaternion::Quaternion()
    : w(0.f), v(makeVec(0.f, 0.f, 0.f))
{
}

Quaternion::Quaternion(float w, const vec3& v)
    : w(w), v(v)
{
}

Quaternion::Quaternion(const vec4& quat)
    : w(quat[3]), v(makeVec(quat[0], quat[1], quat[2]))
{
}

Quaternion::Quaternion(const Quaternion& q)
    : w(q.w), v(q.v)
{
}

}//namespace math
}//namespace heng
