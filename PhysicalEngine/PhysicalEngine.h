#ifndef DEF_PHYSICALENGINE
#define DEF_PHYSICALENGINE

struct GLFWwindow;

#define PROJECT_NAME "Physical Engine 3D"

class PhysicalEngine {
private:
    GLFWwindow *window;
    unsigned int VAOs[2];
    unsigned int shaderProgramOrange, shaderProgramYellow;

public:
    PhysicalEngine();

    ~PhysicalEngine();

    void start();

private:
    void generateShaders();

};


#endif //DEF_PHYSICALENGINE
