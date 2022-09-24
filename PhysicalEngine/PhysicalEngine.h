#ifndef PHYSICALENGINE_H
#define PHYSICALENGINE_H

#include <vector>
#include "Scene/Scene.h"

#define PROJECT_NAME "Physical Engine 3D"

struct GLFWwindow;

class PhysicalEngine {
private:
    GLFWwindow *window;
    struct {
        float r, g, b, a;
    } backgroundColor;
    Scene *scene;


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
