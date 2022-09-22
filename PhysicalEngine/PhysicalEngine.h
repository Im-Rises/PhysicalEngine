#ifndef DEF_PHYSICALENGINE
#define DEF_PHYSICALENGINE

#include <vector>

#define PROJECT_NAME "Physical Engine 3D"

struct GLFWwindow;

class PhysicalEngine {
private:
    GLFWwindow *window;
    struct {
        float r, g, b, a;
    } backgroundColor;


public:
    PhysicalEngine();

    ~PhysicalEngine();

    void start();

private:
    void handleEvents();

    void updateGui();

    void updateScene();

    void refreshScreen();
};


#endif //DEF_PHYSICALENGINE
