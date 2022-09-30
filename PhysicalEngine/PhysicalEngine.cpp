#include "PhysicalEngine.h"

#pragma region Includes

// OpenGL Loader
#include <glad/glad.h>

// Includes
#include "Scene/Scene.h"
#include "InputManager.h"
#include <chrono>

// Dear ImGui
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"

#include <stdio.h>

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif

#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include <cstdlib>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#pragma endregion

#pragma region Callback functions

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

#pragma endregion

#pragma region Constructor and Destructor

PhysicalEngine::PhysicalEngine() {
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        exit(1);

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    window = glfwCreateWindow(windowWidth, windowHeight, PROJECT_NAME, NULL, NULL);
    if (window == NULL)
        exit(1);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    glfwSetCursorPosCallback(window, InputManager::cursor_position_callback);
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, InputManager::key_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        exit(1);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    ImPlot::CreateContext();

    backgroundColor = {
            0.45f, 0.55f, 0.60f, 1.00f
    };

    scene = new Scene(windowWidth, windowHeight);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

PhysicalEngine::~PhysicalEngine() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    ImPlot::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

#pragma endregion

#pragma region Game Loop methods

void PhysicalEngine::start() {
    auto start = std::chrono::high_resolution_clock::now();

    m_game.start(scene);

    //Game loop
    while (!glfwWindowShouldClose(window)) {

        //Inputs
        handleEvents();
        handleGui();

        //Update game mechanics
        updateGame(start);

        //Refresh screen
        updateScreen();
    }
}

void PhysicalEngine::handleEvents() {
    glfwPollEvents();
}

void PhysicalEngine::handleGui() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    if (!isFullScreen) {
        /*------------------ImGui windows------------------*/
        {
            ImGui::Begin("Framerate");
            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                        ImGui::GetIO().Framerate);
            ImGui::End();
        }

        {
            ImGui::Begin("Hierarchy");
            for (int i = 0; i < scene->getNbGameObjects(); i++)
                ImGui::Text("%s", scene->getGameObjectName(i).c_str());
            ImGui::End();
        }

        {
            ImGui::Begin("View tools");
            ImGui::Checkbox("Mesh: Fill/Line", scene->getWireFrameStatePtr());
            ImGui::End();
        }
        {
            ImGui::Begin("Speed handler");
            ImGui::InputFloat("Speed", &gameSpeed, 0.1f, 1.0f, "%0.2f", ImGuiInputTextFlags_AllowTabInput);
            m_game.setSpeed(gameSpeed);
            ImGui::End();
        }
        {
            ImGui::Begin("Speed graph viewer");
            if (ImPlot::BeginPlot("GameObject speed")) {
//            ImPlot::PlotBars("My Bar Plot", bar_data, 11);
//            ImPlot::PlotLine("My Line Plot", x_data, y_data, 1000);
                ImPlot::EndPlot();
            }
            ImGui::End();
        }

        {
            ImGui::Begin("Inspector");

            ImGui::End();
        }

        {
            ImGui::Begin("Project files");

            ImGui::End();
        }

        {
            ImGui::Begin("Scene View");
            {
                ImGui::BeginChild("GameRender");
                ImVec2 wsize = ImGui::GetWindowSize();
                ImGui::Image((ImTextureID) scene->getFrameBufferId(), wsize, ImVec2(0, 1), ImVec2(1, 0));
                ImGui::EndChild();
            }
            ImGui::End();
        }
    }
    ImGui::Render();
}


void PhysicalEngine::updateGame(std::chrono::steady_clock::time_point &start) {
    auto end = std::chrono::high_resolution_clock::now();
    double doubleDeltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    doubleDeltaTime *= 0.000000001;
    auto deltaTime = static_cast<float>(doubleDeltaTime);
    start = std::chrono::high_resolution_clock::now();
    scene->updatePhysics(deltaTime);
    scene->update();
}

void PhysicalEngine::updateScreen() {
    // Update viewport
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    updateViewport(display_w, display_h);

    // Clear screen
    clearScreen();

    // Draw scene
    if (!isFullScreen) {
        glBindFramebuffer(GL_FRAMEBUFFER, scene->getFrameBufferId());
        clearScreen();
    }
    scene->draw(display_w, display_h);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Swap buffers
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
}

void PhysicalEngine::clearScreen() {
    glClearColor(backgroundColor.r, backgroundColor.g,
                 backgroundColor.b,
                 backgroundColor.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void PhysicalEngine::updateViewport(int width, int height) {
    glViewport(0, 0, width, height);
    scene->updateViewport(width, height);
}


void PhysicalEngine::toogleFullScreen() {
    if (isFullScreen) {
        glfwSetWindowMonitor(window, NULL, 0, 0, windowWidth, windowHeight, 0);
        isFullScreen = false;
    } else {
        GLFWmonitor *monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode *mode = glfwGetVideoMode(monitor);
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        isFullScreen = true;
    }

//    if (fullScreen) {
//        glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, windowWidth, windowHeight, GLFW_DONT_CARE);
//    } else {
//        glfwSetWindowMonitor(window, NULL, 0, 0, windowWidth, windowHeight, GLFW_DONT_CARE);
//    }
}

#pragma endregion
