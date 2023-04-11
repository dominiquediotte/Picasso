#pragma once

#include "BaseApplication.h"

class TextureApplication : public BaseApplication
{
public:
    void setup();
    void update();
    void draw();

private:
    ofEasyCam m_camera;
    ofBoxPrimitive m_cube;
};
