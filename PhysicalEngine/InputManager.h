#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

struct GLFWwindow;

class PhysicalEngineLauncher;

class InputManager {

private:
    static bool mouseRightButtonPressed;
    static bool mouseLeftButtonPressed;

    static float mouseLastPosX;
    static float mouseLastPosY;

public:
    static GLFWwindow* m_window;
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
    static void keyPressed(GLFWwindow* window, int key, PhysicalEngineLauncher* engine);

    static void keyReleased(GLFWwindow* window, int key, PhysicalEngineLauncher* engine);

    static void keyRepeated(GLFWwindow* window, int key, PhysicalEngineLauncher* engine);

public:
    static void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

    static void cursor_position_callback(GLFWwindow* window, double xPos, double yPos);

    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

public:
    static bool isForwardKeyPressed();
    static bool isBackwardKeyPressed();
    static bool isLeftKeyPressed();
    static bool isRightKeyPressed();
    static bool isUpKeyPressed();
    static bool isDownKeyPressed();
};

#endif // INPUT_MANAGER_H
