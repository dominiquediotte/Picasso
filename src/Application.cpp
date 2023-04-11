#include "Application.h"

void Application::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);

    textureApplicationButton.addListener(this, &Application::textureApplicationButtonPressed);

    gui.setup("Menu");
    gui.add(textureApplicationButton.setup("Texture demo"));

    m_hidden = false;
}

void Application::update()
{
}

void Application::draw()
{
    gl->background(ofColor::blue);

    if (!m_hidden)
    {
        gui.draw();
    }
}

void Application::keyReleased(int key)
{
    if (key == 'h')
    {
        m_hidden = !m_hidden;
    }
}

void Application::textureApplicationButtonPressed()
{
    ofGLFWWindowSettings settings{};
    settings.setGLVersion(3, 3);
    settings.shareContextWith = this->window;

    auto window = ofCreateWindow(settings);

    auto app = make_shared<TextureApplication>();
    app->window = window;
    app->gl = dynamic_pointer_cast<ofBaseGLRenderer>(window->renderer());

    ofRunApp(window, app);
}
