#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

struct GLFWwindow;

class ParticleEngineLauncher;

class InputManager {

private:
//    static float translationSpeed;
    static float rotationSpeed;

    static bool mouseRightButtonPressed;
    static bool mouseLeftButtonPressed;

    static float mouseLastPosX;
    static float mouseLastPosY;
    static float mouseDirection; // Use Vector3 ?

    static float movementSpeed;

public:
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

private:
    static void keyPressed(GLFWwindow *window, int key, ParticleEngineLauncher *engine);

    static void keyReleased(GLFWwindow *window, int key, ParticleEngineLauncher *engine);

    static void keyRepeated(GLFWwindow *window, int key, ParticleEngineLauncher *engine);

public:
    static void scroll_callback(GLFWwindow *window, double xOffset, double yOffset);

    static void cursor_position_callback(GLFWwindow *window, double xPos, double yPos);

    static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);


};

#endif //INPUTMANAGER_H
