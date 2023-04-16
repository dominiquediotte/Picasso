#include "TextureApplication.h"

void TextureApplication::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofDisableArbTex();

    m_teapot.loadModel("teapot.obj");
    m_teapot.disableMaterials();
    m_teapot.setRotation(0, 180, 1, 0, 0);
    m_teapot.setScale(0.5, 0.5, 0.5);

    m_camera.setPosition(250, 250, 250);
    m_camera.lookAt(m_teapot.getPosition());

    ofLoadImage(m_texture, "concrete.jpg");
    m_texture.enableMipmap();
    m_texture.setTextureWrap(GL_REPEAT, GL_REPEAT);

    m_shader.load("teapot");
}

void TextureApplication::update()
{
}

void TextureApplication::draw()
{
    gl->background(ofColor::orange);
    
    ofEnableDepthTest();
    ofEnableLighting();

    m_camera.begin();

    drawLocator();

    drawModel();

    m_camera.end();

    ofDisableLighting();
    ofDisableDepthTest();
}

void TextureApplication::drawLocator()
{
    gl->pushMatrix();
    gl->pushStyle();
    gl->setColor(ofColor::red);
    gl->drawArrow(ofVec3f(0, 0, 0), ofVec3f(100, 0, 0), 5);
    gl->setColor(ofColor::green);
    gl->drawArrow(ofVec3f(0, 0, 0), ofVec3f(0, 100, 0), 5);
    gl->setColor(ofColor::blue);
    gl->drawArrow(ofVec3f(0, 0, 0), ofVec3f(0, 0, 100), 5);
    gl->popStyle();
    gl->popMatrix();
}

void TextureApplication::drawModel()
{
    gl->pushMatrix();
    m_texture.bind();
    m_shader.begin();
    m_teapot.draw(OF_MESH_FILL);
    m_shader.end();
    m_texture.unbind();
    gl->popMatrix();
}
