#pragma once

#include "BaseApplication.h"
#include "ofxAssimpModelLoader.h"

class TextureApplication : public BaseApplication
{
public:
    void setup();
    void update();
    void draw();
    void drawLocator();
    void drawModel();

private:
    ofEasyCam m_camera;
    ofBoxPrimitive m_cube;
    ofxAssimpModelLoader m_teapot;
    ofTexture m_texture;
    ofShader m_shader;
};
