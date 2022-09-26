#ifndef PHYSICALENGINE_H
#define PHYSICALENGINE_H

#define PROJECT_NAME "Physical Engine 3D"

#include <memory>

//Shallow declarations
class Scene;

class InputManager;

struct GLFWwindow;

//Class declaration
class PhysicalEngine {
    friend class InputManager;

private:
    GLFWwindow *window;

    std::unique_ptr<Scene> scene;

    struct {
        float r, g, b, a;
    } backgroundColor;


public:
    PhysicalEngine();

    ~PhysicalEngine();

    void start();

private:
    void handleEvents();

    void handleGui();

    void updateGame();

    void updateScreen();
};


#endif //PHYSICALENGINE_H
