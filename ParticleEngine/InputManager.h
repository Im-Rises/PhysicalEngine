#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

struct GLFWwindow;

class ParticleEngineLauncher;

class InputManager {

private:
//    static float translationSpeed;
    static float rotationSpeed;

    static double mouseLastPosX;
    static double mouseLastPosY;

public:
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

private:
    static void keyPressed(GLFWwindow *window, int key, ParticleEngineLauncher *engine);

    static void keyReleased(GLFWwindow *window, int key, ParticleEngineLauncher *engine);

    static void keyRepeated(GLFWwindow *window, int key, ParticleEngineLauncher *engine);


public:
    static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

private:
//    static void mouseButtonPressed(GLFWwindow *window, int button, ParticleEngineLauncher *engine);


};

#endif //INPUTMANAGER_H
