#ifndef PARTICLE_ENGINE_H
#define PARTICLE_ENGINE_H

#define PROJECT_NAME "Particle Engine 3D"

#define VERSION_MAJOR "0"
#define VERSION_MINOR "2"
#define VERSION_PATCH "1"

#define PROJECT_VERSION VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH

#define PROJECT_GITHUB "https://github.com/Im-Rises/ParticleEngineLauncher"

#include <chrono>
#include "Game.h"

//Shallow declarations
class Scene;

class InputManager;

class GameObject;

struct GLFWwindow;

//Class declaration
class ParticleEngineLauncher {
    friend class InputManager;

private:
    // Window, Scene and Game objects
    GLFWwindow *window;
    Scene *scene;
    Game game;

    // Window variables
    bool isFullScreen = false;
    float backgroundColor[4] = {};
    int windowWidth = 1580, windowHeight = 720;

    // Variables for the game loop
    const int PHYSICAL_UPDATE_PER_SECOND = 50;
    GameObject *gameObject = nullptr;

    // Widgets variables
    char consoleBuffer[1024] = {};

public:
    ParticleEngineLauncher();

    ~ParticleEngineLauncher();

    void start();

private:
    void handleEvents();

    void handleGui();

    void updateGame(std::chrono::steady_clock::time_point &start);

    void updateScreen();

private:
    void clearScreen();

    void updateViewport(int width, int height);

    void toggleFullScreen();

    bool isMinimized() const;

    static bool ButtonCenteredOnLine(const char *label, float alignment = 0.5f);

};


#endif //PARTICLE_ENGINE_H
