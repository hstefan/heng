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

#ifndef HENG_GL_SHADER_HPP
#define HENG_GL_SHADER_HPP

#include "Encapsulation.hpp"
#include <fstream>
#include <vector>

namespace heng
{
namespace gl
{

class Shader : public Encapsulation
{
public:
   Shader(GLenum type);
   ~Shader();

   void compile() const;
   void setSource(const GLchar* code) const;
   void setSource(std::ifstream& source) const;
};

inline Shader::Shader(GLenum type)
   : Encapsulation(glCreateShader(type))
{
}

inline Shader::~Shader()
{
   glDeleteShader(id);
}

inline void Shader::compile() const
{
   glCompileShader(id);
}

inline void Shader::setSource(const GLchar* code) const
{
   glShaderSource(id, 1, &code, 0);
}

inline void Shader::setSource(std::ifstream& source)
{
   std::vector<char> str;

   f.seekg(0, std::ios::end);
   str.reserve((unsigned int)f.tellg() + 1);
   f.seekg(0);

   str.assign(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());
   str.push_back('\0');

   setSource(&str[0]);
}

} //namespace gl
} //namespace hstefan


#endif