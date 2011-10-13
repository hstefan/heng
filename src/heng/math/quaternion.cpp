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
