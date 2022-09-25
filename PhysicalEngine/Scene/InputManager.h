#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <GLFW/glfw3.h>

class InputManager {

private:
    static InputManager *instance;

    InputManager();

    bool leftClick = false;
    bool rightClick = false;

public:
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static InputManager *getInstance();

    ~InputManager();

    void update();
};

#endif //INPUTMANAGER_H
