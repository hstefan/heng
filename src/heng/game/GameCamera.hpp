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


#ifndef HENG_GAME_GAME_CAMERA_HPP
#define HENG_GAME_GAME_CAMERA_HPP

#include "GameObject.hpp"
#include "../math/vector.hpp"
#include "../cg/Camera.hpp"

namespace heng
{
namespace game
{

namespace detail
{
struct mouse_pos
{
    unsigned int x;
    unsigned int y;
};
}

class GameCamera : public GameObject
{
public:
    void onUpdate();
    math::mat4 getMatrix();

    static const char MOVE_FORWARD = 'W';  
    static const char MOVE_BACKWARD = 'S'; 
    static const char MOVE_LEFTWARD = 'A';     
    static const char MOVE_RIGHTWARD = 'D';
    
private:
    cg::Camera cam;
    detail::mouse_pos last_pos;
};

} //namespace game
} //namespace heng

#endif

