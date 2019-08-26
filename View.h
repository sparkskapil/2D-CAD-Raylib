#pragma once
#include "raylib.h"

class View
{
protected:
    Camera2D camera;
public:
    virtual void Setup();
    virtual void Draw();
    virtual ~View();
};