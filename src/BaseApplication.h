#pragma once

#include "ofMain.h"

class BaseApplication : public ofBaseApp
{
public:
    shared_ptr<ofAppBaseWindow> window;
    shared_ptr<ofBaseGLRenderer> gl;
};
