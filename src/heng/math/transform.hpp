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

#include "vector.hpp"
#include "matrix.hpp"
#include <cmath>

namespace heng
{
namespace math
{

inline mat3d rotMat2dh(float angle)
{ 
   mat3d m = {{
      (float)std::cos(angle), (float)-std::sin(angle), 0.f,
      (float)std::sin(angle), (float)std::cos(angle) , 0.f,
      0.f              , 0.f,                1.f
   }};

   return m;
}

inline mat3d scaleMat2dh(float sx, float sy)
{ 
   mat3d m = {{
      sx, 0.f , 0.f,
      0.f , sy, 0.f,
      0.f , 0.f , 1.f
   }};

   return m;
}

inline mat3d transMat2dh(float tx, float ty)
{
   mat3d m = {{
      1.f, 0.f, tx,
      0.f, 1.f, ty,
      0.f, 0.f, 1.f
   }};

   return m;
}

inline mat4d yawRotationMatrix(float angle)
{
   mat4d m = {
      {
         (float)cos(angle) ,   0.f   , (float)sin(angle) ,    0.f,
              0.f          ,   1.f   ,       0.f         ,    0.f,
         (float)-sin(angle),   0.f   , (float)cos(angle) ,    0.f,
              0.f          ,   0.f   ,       0.f         ,    1.f

      }
   };
   return m;
}
inline mat4d pitchRotationMatrix(float angle)
{
   mat4d m = {
      {
            1.f       ,       0.f             ,          0.f           ,    0.f,
            0.f       ,   (float)cos(angle)   ,   (float)sin(angle)    ,    0.f,
            0.f       ,   (float)-sin(angle)  ,   (float)cos(angle)    ,    0.f,
            0.f       ,       0.f             ,          0.f           ,    1.f
      }
   };
   return m;
}

inline mat4d rollRotationMatrix(float angle)
{
   mat4d m = {
      {
            (float)cos(angle)   ,   (float)sin(angle)   ,   0.f  ,    0.f,
            (float)-sin(angle)  ,   (float)cos(angle)   ,   0.f  ,    0.f,
                  0.f           ,          0.f          ,   1.f  ,    0.f,
                  0.f           ,          0.f          ,   0.f  ,    1.f
      }
   };
   return m;
}

inline mat4d translationMatrix(float tx, float ty, float tz)
{
   mat4d m = {
      {
         1.f, 0.f, 0.f, tx,
         0.f, 1.f, 0.f, ty,
         0.f, 0.f, 1.f, tz,
         0.f, 0.f, 0.f, 1.f
      }
   };
   return m;
}

inline mat4d scaleMatrix(float sx, float sy, float sz)
{
   mat4d m  = {
      {
            sx, 0.f  , 0.f , 0.f,
            0.f , sy , 0.f , 0.f,
            0,f , 0.f  , sz, 0.f,
            0.f , 0.f  , 0.f , 1.f
      }
   };
   return m;
}

inline mat4d identityMatrix()
{
   return scaleMatrix(1.f, 1.f, 1.f);
}

inline mat4d orthogonalProj()
{
   mat4d m = {{
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 1
   }};
   return m;
}

inline mat4d perspecProj(float d)
{
   mat4d m = {{
      1.f, 0.f, 0.f, 0.f,
      0.f, 1.f, 0.f, 0.f,
      0.f, 0.f, 0.f, 0.f,
      0.f, 0.f,  d , 1.f
   }};
   return m;
}

} //namespace math
} //namespace heng
#endif
