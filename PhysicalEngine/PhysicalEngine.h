#ifndef DEF_PHYSICALENGINE
#define DEF_PHYSICALENGINE

struct GLFWwindow;

#define PROJECT_NAME "Physical Engine 3D"

class PhysicalEngine {
private:
    GLFWwindow *window;

public:
    PhysicalEngine();

    ~PhysicalEngine();

    void start();

};


#endif //DEF_PHYSICALENGINE
