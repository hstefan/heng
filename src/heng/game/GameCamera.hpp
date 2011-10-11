#ifndef HENG_GAME_GAME_CAMERA_HPP
#define HENG_GAME_GAME_CAMERA_HPP

#include "GameObject.hpp"
#include "../math/vector.hpp"
#include "../cg/Camera.hpp"

namespace heng
{
namespace game
{

class GameCamera : public GameObject
{
public:
    void onUpdate();
    math::mat4 getMatrix();    
private:
    cg::Camera cam;
};

} //namespace game
} //namespace heng

#endif

