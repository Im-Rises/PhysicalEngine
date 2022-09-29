#ifndef PHYSICALENGINE_H
#define PHYSICALENGINE_H

#define PROJECT_NAME "Physical Engine 3D"

#include <memory>
#include <chrono>
#include "Game.h"

//Shallow declarations
class Scene;

class InputManager;

struct GLFWwindow;

//Class declaration
class PhysicalEngine {
    friend class InputManager;

private:
    GLFWwindow *window;
    float speed = 0.5f;
    Scene *scene;
    Game m_game;

    struct {
        float r, g, b, a;
    } backgroundColor;
    bool fullWindowView = false;

public:
    PhysicalEngine();

    ~PhysicalEngine();

    void start();

private:
    void handleEvents();

    void handleGui();

    void updateGame(std::chrono::steady_clock::time_point &start);

    void updateScreen();
};


#endif //PHYSICALENGINE_H
