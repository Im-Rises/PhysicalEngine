#ifndef DEF_PHYSICALENGINE
#define DEF_PHYSICALENGINE

struct GLFWwindow;

class PhysicalEngine {
private:
    GLFWwindow *window;
    bool show_demo_window = true;
    bool show_another_window = false;

public:
    PhysicalEngine();

    ~PhysicalEngine();

    void start();

private:
    void createTriangle();
};


#endif //DEF_PHYSICALENGINE
