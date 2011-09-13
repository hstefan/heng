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

#ifndef HENG_GL_PROGRAM_HPP
#define HENG_GL_PROGRAM_HPP

#include <GL3/gl3.h>
#include "Encapsulation.hpp"
#include "Shader.hpp"

namespace heng
{
namespace gl
{

class Program : public Encapsulation
{
public:
   Program();
   ~Program();

   void use() const;
   void link() const;
   void attachShader(const Shader& shader) const;
};

inline Program::Program()
   : Encapsulation(glCreateProgram())
{
}

inline Program::~Program()
{
   glDeleteProgram(id);
}

inline void Program::use() const
{
   glUseProgram(id);
}

inline void Program::link() const
{
   glLinkProgram(id);
}

inline void Program::attachShader(const Shader& shader) const 
{
   glAttachShader(id, shader);
}

}
}

#endif