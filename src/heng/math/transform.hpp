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

#ifndef HENG_MATH_TRANSFORM_HPP
#define HENG_MATH_TRANSFORM_HPP

namespace heng
{
namespace math
{

template <unsigned int M, unsigned int N>
struct matrix;

typedef matrix<4,4> mat4;
typedef matrix<3,1> vec3;

mat4 yawRotationMatrix(float angle);
mat4 pitchRotationMatrix(float angle);
mat4 rollRotationMatrix(float angle);
mat4 translationMatrix(float tx, float ty, float tz);
mat4 scaleMatrix(float sx, float sy, float sz);
mat4 identityMatrix();
mat4 orthogonalProj();
mat4 perspecProj(float d);
mat4 rotation(const vec3& v, float angle);
mat4 rotation(float x, float y, float z, float angle);

} //namespace math
} //namespace heng
#endif
