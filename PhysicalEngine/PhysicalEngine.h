#ifndef DEF_PHYSICALENGINE
#define DEF_PHYSICALENGINE

#include <vector>
#include "Scene.h"

#define PROJECT_NAME "Physical Engine 3D"

struct GLFWwindow;

class PhysicalEngine {
private:
    GLFWwindow *window;
    struct {
        float r, g, b, a;
    } backgroundColor;
    Scene scene;


public:
    PhysicalEngine();

    ~PhysicalEngine();

    void start();

private:
    void handleEvents();

    void updateGui();

    void updateGame();

    void updateScreen();
};


#endif //DEF_PHYSICALENGINE
