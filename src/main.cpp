#include "ofMain.h"

#include "Application.h"

int main()
{
    ofGLFWWindowSettings settings{};
    settings.setGLVersion(3, 3);

    auto window = ofCreateWindow(settings);

    auto app = make_shared<Application>();
    app->window = window;
    app->gl = dynamic_pointer_cast<ofBaseGLRenderer>(window->renderer());

    ofRunApp(window, app);
    return ofRunMainLoop();
}
