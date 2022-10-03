#include "PhysicalEngine.h"

#pragma region Includes

// OpenGL Loader
#include <glad/glad.h>

// Includes
#include "Scene/Scene.h"
#include "Scene/GameObject.h"
#include "InputManager.h"
#include <chrono>

// Dear ImGui
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/implot.h"
#include "Scene/Components/Component.h"

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

    // Check if window was created
    if (window == NULL)
        exit(1);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize GLFW callbacks
    glfwSetCursorPosCallback(window, InputManager::cursor_position_callback);
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, InputManager::key_callback);

    // Center window
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    auto xPos = mode->width / 2 - windowWidth / 2;
    auto yPos = mode->height / 2 - windowHeight / 2;
    glfwSetWindowPos(window, xPos, yPos);

    // Initialize OpenGL loader
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

    // Setup background color
    backgroundColor[0] = 0.45f;
    backgroundColor[1] = 0.55f;
    backgroundColor[2] = 0.60f;
    backgroundColor[3] = 1.00f;

    // Setup scene
    scene = new Scene(windowWidth, windowHeight);

    // Bind default frame buffer
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
    auto start = std::chrono::steady_clock::now();

    game.start(scene);

    gameObject = scene->getPtrGameObjectByIndex(0);

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
            static bool my_tool_active = true;
            static bool showAboutPopup = false;
            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
                    if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_active = false; }
                    if (ImGui::MenuItem("Exit", "Alt+F4")) { glfwSetWindowShouldClose(window, true); }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("View")) {
                    if (ImGui::MenuItem("FullScreen", "F11")) { toggleFullScreen(); }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Help")) {

                    if (ImGui::MenuItem("About PhysicalEngine...")) {
                        showAboutPopup = true;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
            if (showAboutPopup)
                ImGui::OpenPopup("About PhysicalEngine##AboutPopup");
            if (ImGui::BeginPopupModal("About PhysicalEngine##AboutPopup", &showAboutPopup,
                                       ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize |
                                       ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse)) {
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), PROJECT_NAME);
                ImGui::Text("Version: %s", PROJECT_VERSION);
                ImGui::NewLine();
                ImGui::Text("Developed by: ");
                ImGui::Text("  - Quentin MOREL");
                ImGui::Text("  - Clémence CLAVEL");
                ImGui::Text("  - Gabriel REBOUL");
                ImGui::NewLine();
                ImGui::Text("Github: %s", PROJECT_GITHUB);
                ImGui::NewLine();
                if (ImGui::Button("Close")) {
                    ImGui::CloseCurrentPopup();
                    showAboutPopup = false;
                }
                ImGui::EndPopup();
            }
        }
        {
            ImGui::Begin("Window info");
            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                        ImGui::GetIO().Framerate);
            ImGui::Text("Window width: %d", windowWidth);
            ImGui::Text("Window height: %d", windowHeight);
            ImGui::End();
        }
        {
            ImGui::Begin("Hierarchy");
            for (int i = 0; i < scene->getGameObjects().size(); i++) {
                std::string label = gameObject == scene->getPtrGameObjectByIndex(i) ? "Selected" : "Select";
                label += "##HierarchyGameObject" + std::to_string(i);
                if (ImGui::Button(label.c_str())) {
                    this->gameObject = scene->getPtrGameObjectByIndex(i);
                }
                ImGui::SameLine();
                ImGui::Text("%s", scene->getPtrGameObjectByIndex(i)->getName().c_str());
            }
            ImGui::End();
        }
        {
            ImGui::Begin("View tools");
            ImGui::Text("Background color");
            ImGui::ColorPicker4("Background color", (float *) backgroundColor);
            ImGui::Checkbox("Mesh: Fill/Line", scene->getPtrWireFrameState());
            ImGui::Checkbox("Show axis", scene->getPtrShowAxis());
            ImGui::End();
        }
        {
            ImGui::Begin("Console");
            ImGui::InputTextMultiline("##console", consoleBuffer, IM_ARRAYSIZE(consoleBuffer),
                                      ImVec2(-1.0f, ImGui::GetTextLineHeight() * 11),
                                      ImGuiInputTextFlags_AllowTabInput);
            ImGui::Button("Enter");
            ImGui::SameLine();
            ImGui::Button("Clear");
            ImGui::End();
        }
        {
            ImGui::Begin("Speed graph viewer");
            if (ImPlot::BeginPlot("GameObject speed") && gameObject != nullptr) {
//                ImPlot::PlotLine("Speed", gameObject->getSpeedHistory().data(), gameObject->getSpeedHistory().size());
            }
            ImPlot::EndPlot();
            ImGui::End();
        }
        {
            ImGui::Begin("Inspector");
            if (gameObject != nullptr) {
                ImGui::Text("Name: %s", gameObject->getName().c_str());
                if (ImGui::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen)) {
                    gameObject->drawTransformGui();
                }
                if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen)) {
                    gameObject->drawMeshGui();
                }
                for (Component *component: gameObject->getComponents()) {
                    if (ImGui::CollapsingHeader(component->getName().c_str(), ImGuiTreeNodeFlags_DefaultOpen)) {
                        component->drawGui();
                    }
                }
            }
            ImGui::End();
        }
        {
            ImGui::Begin("Project files");

            ImGui::End();
        }
        {
            ImGui::Begin("Game settings");
            ImGui::Text("Particle speed:");
            ImGui::InputFloat("##PhysicalEngineParticleSpeed", game.getPtrSpeed(), 0.1f, 1.0f, "%.1f");
            ImGui::End();
        }
        {
            ImGui::Begin("Scene View");
            {
                ImGui::BeginChild("GameRender");
                ImVec2 windowSize = ImGui::GetWindowSize();
                ImGui::Image((ImTextureID) scene->getFrameBufferId(), windowSize, ImVec2(0, 1), ImVec2(1, 0));
                ImGui::EndChild();
            }
            ImGui::End();
        }
    }
    ImGui::Render();
}


void PhysicalEngine::updateGame(std::chrono::steady_clock::time_point &start) {
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - start).count();
//    if (deltaTime > 1000 / PHYSICAL_UPDATE_PER_SECOND) {
    start = std::chrono::steady_clock::now();
    scene->updateGameObjects((float) deltaTime / 1000.0f);
//    }
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
    glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

void PhysicalEngine::updateViewport(int width, int height) {
    glViewport(0, 0, width, height);
    scene->updateViewport(width, height);
    if (!isFullScreen) {
        windowWidth = width;
        windowHeight = height;
    }
}


void PhysicalEngine::toggleFullScreen() {
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if (isFullScreen) {
        auto xPos = mode->width / 2 - windowWidth / 2;
        auto yPos = mode->height / 2 - windowHeight / 2;
        glfwSetWindowMonitor(window, NULL, xPos, yPos, windowWidth, windowHeight, 0);
        isFullScreen = false;
    } else {
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        isFullScreen = true;
    }
}

#pragma endregion
