#ifndef DEF_PHYSICALENGINE
#define DEF_PHYSICALENGINE

struct GLFWwindow;

#define PROJECT_NAME "Physical Engine 3D"

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

//    void generateSphereVertices(int stackCount, int sectorCount, float radius);
};


#endif //DEF_PHYSICALENGINE
