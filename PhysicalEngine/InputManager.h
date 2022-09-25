#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

struct GLFWwindow;

class InputManager {

private:
    static InputManager *instance;

//    InputManager();
//
//    ~InputManager();

    bool leftClick = false;
    bool rightClick = false;

public:
//    static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

private:
    static void keyPressed(GLFWwindow *window, int key);

    static void keyReleased(GLFWwindow *window, int key);

    static void keyRepeated(GLFWwindow *window, int key);


};

#endif //INPUTMANAGER_H
