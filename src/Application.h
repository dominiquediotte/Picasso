#pragma once

#include "BaseApplication.h"

#include "ofxGui.h"
#include "TextureApplication.h"

class Application : public BaseApplication
{
public:
    void setup();
    void update();
    void draw();

    void keyReleased(int key);
    void textureApplicationButtonPressed();

private:
    ofxPanel gui;
    ofxButton textureApplicationButton;

    bool m_hidden;
};
