#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP


#include <SDL2/SDL.h>


class GameObject
{
protected:
    int _xCenterPos=0, _yCenterPos=0;
    float _rotation=0;
public:
    int GetXCenterPos();
    int GetYCenterPos();
    float GetRotation();
};

#endif