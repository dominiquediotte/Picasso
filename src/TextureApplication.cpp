#include "TextureApplication.h"

void TextureApplication::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);

    m_camera.setPosition(100.0f, 100.0f, 100.0f);
    m_camera.lookAt(m_cube);
}

void TextureApplication::update()
{
}

void TextureApplication::draw()
{
    gl->background(ofColor::orange);

    m_camera.begin();

    gl->pushMatrix();
    m_cube.draw();
    gl->popMatrix();

    m_camera.end();
}
