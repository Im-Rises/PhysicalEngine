#ifndef PARTICLE_ENGINE_H
#define PARTICLE_ENGINE_H

#define PROJECT_NAME "Physical Engine 3D"

#define PROJECT_AUTHOR "  - Quentin MOREL\n  - Clémence CLAVEL\n  - Gabriel REBOUL"

#define VERSION_MAJOR "1"
#define VERSION_MINOR "5"
#define VERSION_PATCH "0"

#define PROJECT_VERSION VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH

#define PROJECT_GITHUB "https://github.com/Im-Rises/PhysicalEngine"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define CONSOLE_BUFFER_SIZE 1024

#include "Game.h"
#include "Scene/Scene.h"
#include <array>
#include <chrono>

class InputManager;

class GameObject;

struct GLFWwindow;

class PhysicalEngineLauncher {
    friend class InputManager;

private:
    // Window, Scene and Game objects
    GLFWwindow* window = nullptr;
    Scene* scene;
    Game game;

    // Window variables
    bool isFullScreen = false;
    std::array<float, 4> backgroundColor = {};
    int windowWidth = WINDOW_WIDTH, windowHeight = WINDOW_HEIGHT;

    // Selected GameObject in the scene
    GameObject* gameObject = nullptr;

    // Widgets terminal variables
    std::array<char, CONSOLE_BUFFER_SIZE> consoleBuffer = {};

public:
    PhysicalEngineLauncher();

    ~PhysicalEngineLauncher();

    void start();

private:
    void handleEvents();

    void handleGui();

    void updateGame(std::chrono::steady_clock::time_point& start);

    void updateScreen();

private:
    void clearScreen();

    void updateViewport(int width, int height);

    void toggleFullScreen();

    bool isMinimized() const;

    // private:
    //     void focusCameraOnGameObject();
};


#endif // PARTICLE_ENGINE_H
