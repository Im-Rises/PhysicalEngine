#include "PhysicalEngineLauncher.h"

// OpenGL Loader
#include <glad/glad.h>

// Includes
#include "InputManager.h"
#include "Scene/Components/Component.h"
#include "Scene/GameObject.h"
#include "Scene/Scene.h"
#include "Utility/RollingBuffer.h"

// Dear ImGui
#include "Utility/imGuiUtility.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/implot.h"

#include <cstdio>

#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif

#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include <cstdlib>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

#ifdef __EMSCRIPTEN__
#include "imgui/libs/emscripten/emscripten_mainloop_stub.h"
#include <emscripten/html5.h>
#endif

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

PhysicalEngineLauncher::PhysicalEngineLauncher() {
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (glfwInit() == 0)
        exit(1);

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    const char* glsl_version = "#version 300 es";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // Required on Mac
#else
    const char *glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // 3.0+ only
#endif

    // Set display size
#ifdef __EMSCRIPTEN__
    emscripten_get_canvas_element_size("#canvas", &windowWidth, &windowHeight);
#endif

    // Create window with graphics context
    window = glfwCreateWindow(windowWidth, windowHeight, PROJECT_NAME, nullptr, nullptr);

    // Check if window was created
    if (window == nullptr)
        exit(1);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize GLFW callbacks
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, InputManager::key_callback);
    glfwSetScrollCallback(window, InputManager::scroll_callback);
    glfwSetCursorPosCallback(window, InputManager::cursor_position_callback);
    glfwSetMouseButtonCallback(window, InputManager::mouse_button_callback);

#ifndef __EMSCRIPTEN__
    // Center window
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    auto xPos = mode->width / 2 - windowWidth / 2;
    auto yPos = mode->height / 2 - windowHeight / 2;
    glfwSetWindowPos(window, xPos, yPos);
#endif

#ifdef __EMSCRIPTEN__
    // Initialize OpenGL loader
    if (gladLoadGLES2Loader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0)
        exit(1);
#else
    // Initialize OpenGL loader
    if (gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0)
        exit(1);
#endif

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

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
    //    scene = std::make_unique<Scene>(windowWidth, windowHeight);
    scene = new Scene(windowWidth, windowHeight);

    // Bind default frame buffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glEnable(GL_DEPTH_TEST); // Enable depth testing

//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Setup window for inputs
    InputManager::m_window = window;
}

PhysicalEngineLauncher::~PhysicalEngineLauncher() {
    delete scene;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    ImPlot::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}

void PhysicalEngineLauncher::start() {
    auto start = std::chrono::steady_clock::now();

    // Create game (generate game objects into the scene)
    //    game.start(scene.get());
    game.start(scene);

    // Game loop
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (glfwWindowShouldClose(window) == 0)
#endif
    {
        // Inputs
        handleEvents();
        handleGui();

        // Update game mechanics
        updateGame(start);

        // Refresh screen
        updateScreen();
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif
}

void PhysicalEngineLauncher::handleEvents() {
    glfwPollEvents();
}

void PhysicalEngineLauncher::handleGui() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    if (!isFullScreen) {

#ifdef __EMSCRIPTEN__
        static bool startPosition = true;
#endif

        /*------------------ImGui windows------------------*/
        {
            static bool my_tool_active = true;
            static bool showAboutPopup = false;
            if (ImGui::BeginMainMenuBar()) {
#ifndef __EMSCRIPTEN__
                if (ImGui::BeginMenu("File")) {
                    //                    if (ImGui::MenuItem("Open..", "Ctrl+O"))
                    //                    { /* Do stuff */
                    //                    }
                    //                    if (ImGui::MenuItem("Save", "Ctrl+S"))
                    //                    { /* Do stuff */
                    //                    }
                    if (ImGui::MenuItem("Close", "Ctrl+W")) { my_tool_active = false; }
                    if (ImGui::MenuItem("Exit", "Alt+F4")) { glfwSetWindowShouldClose(window, true); }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("View")) {
                    if (ImGui::MenuItem("FullScreen", "F11")) { toggleFullScreen(); }
                    ImGui::EndMenu();
                }
#endif
                if (ImGui::BeginMenu("Help")) {
                    if (ImGui::MenuItem("About " PROJECT_NAME "...")) {
                        showAboutPopup = true;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
            if (showAboutPopup)
                ImGui::OpenPopup("About " PROJECT_NAME "##AboutPopup");
            if (ImGui::BeginPopupModal("About " PROJECT_NAME "##AboutPopup", &showAboutPopup,
                                       ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize |
                                       ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse)) {
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), PROJECT_NAME);
                ImGui::Text("Version: %s", PROJECT_VERSION);
                ImGui::NewLine();
                ImGui::Text("Developed by: ");
                ImGui::Text("%s", PROJECT_AUTHOR);
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
#ifdef __EMSCRIPTEN__
            if (startPosition) {
                ImGui::SetNextWindowPos(ImVec2(2 + 0, 2 + 20));
                ImGui::SetNextWindowSize(ImVec2(200, 100));
            }
#endif
            ImGui::Begin("Window info");
            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                        ImGui::GetIO().Framerate);
            ImGui::Text("Window width: %d", windowWidth);
            ImGui::Text("Window height: %d", windowHeight);
            ImGui::End();
        }
        {
#ifdef __EMSCRIPTEN__
            if (startPosition) {
                ImGui::SetNextWindowPos(ImVec2(2 + 0, 2 + 20 + 100 + 2));
                ImGui::SetNextWindowSize(ImVec2(200, windowHeight/2));
            }
#endif
            ImGui::Begin("Hierarchy");
            for (int i = 0; i < scene->getGameObjects().size(); i++) {
                ImGui::Selectable((scene->getPtrGameObjectByIndex(i)->getName()).c_str(),
                                  gameObject == scene->getPtrGameObjectByIndex(i));
                if (ImGui::IsItemClicked()) {
                    this->gameObject = scene->getPtrGameObjectByIndex(i);
                }
            }

            ImGui::NewLine();
            if (ImGuiUtility::ButtonCenteredOnLine("Create GameObject", 0.5f)) {
                ImGui::OpenPopup("Create GameObject##CreateGameObjectPopup");
            }
            if (ImGui::BeginPopup("Create GameObject##CreateGameObjectPopup")) {
                for (auto &gameObjType: Mesh::meshNamesList) {
                    if (ImGui::MenuItem(gameObjType)) {
                        // Create and select game object in hierarchy
                        gameObject = scene->createGameObject(gameObjType);
                    }
                }
                ImGui::EndPopup();
            }

            if (ImGuiUtility::ButtonCenteredOnLine("Delete selected GameObject", 0.5f)) {
                scene->deleteGameObject(gameObject);
                gameObject = nullptr;
            }

            ImGui::End();
        }
        {
#ifdef __EMSCRIPTEN__
            if (startPosition) {
                ImGui::SetNextWindowPos(ImVec2(2 + 0, 2 + 20 + 100 + 2 + windowHeight/2 + 2));
                ImGui::SetNextWindowSize(ImVec2(200, windowHeight - 20 - 100 - 2 - windowHeight/2 - 2 -2));
            }
#endif
            ImGui::Begin("View tools");
            ImGui::Text("Background color");
            ImGui::ColorPicker4("Background color", backgroundColor.data());
#ifndef __EMSCRIPTEN__
            ImGui::Checkbox("Mesh: Fill/Line", scene->getPtrWireFrameState());
#endif
//            ImGui::Checkbox("Show axis", scene->getPtrShowAxis());
            ImGui::End();
        }
        {
            //            ImGui::Begin("Console");
            //            ImGuiInputTextFlags inputTextFlags =
            //                    ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CtrlEnterForNewLine;
            //            ImGui::Text("Input:");
            //            if (ImGui::InputTextMultiline("##console", consoleBuffer.data(), consoleBuffer.size(),
            //                                          ImVec2(-1.0f, ImGui::GetTextLineHeight() * 11),
            //                                          inputTextFlags)) {
            //                system(consoleBuffer.data());
            //                consoleBuffer.fill('\0');
            //            }
            //            if (ImGui::Button("Enter")) {
            //                system(consoleBuffer.data());
            //                consoleBuffer.fill('\0');
            //            }
            //            ImGui::SameLine();
            //            if (ImGui::Button("Clear")) {
            //                consoleBuffer.fill('\0');
            //            }
            //            ImGui::End();
        }
        {
#ifdef __EMSCRIPTEN__
            if (startPosition) {
                ImGui::SetNextWindowPos(ImVec2(windowWidth - 200 - 2, 2 + 20));
                ImGui::SetNextWindowSize(ImVec2(200, windowHeight - 20 - 2 - 2));
            }
#endif
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
                ImGui::NewLine();
                if (ImGuiUtility::ButtonCenteredOnLine("Add component", 0.5f)) {
                    ImGui::OpenPopup("Add component##AddComponentPopup");
                }
                if (ImGui::BeginPopup("Add component##AddComponentPopup")) {
                    for (auto &componentName: Component::componentsNamesList) {
                        if (ImGui::MenuItem(componentName)) {
                            gameObject->addComponentByName(componentName);
                        }
                    }
                    ImGui::EndPopup();
                }
                ImGui::NewLine();
                if (ImGuiUtility::ButtonCenteredOnLine("Delete component", 0.5f)) {
                    ImGui::OpenPopup("Delete component##DeleteComponentPopup");
                }
                if (ImGui::BeginPopup("Delete component##DeleteComponentPopup")) {
                    for (auto &component: gameObject->getComponents()) {
                        if (ImGui::MenuItem(component->getName().c_str())) {
                            gameObject->deleteComponentByName(component->getName());
                        }
                    }
                    ImGui::EndPopup();
                }
            }
            ImGui::End();
        }
        {
#ifdef __EMSCRIPTEN__
            if (startPosition) {
                //center at the bottom
//                ImGui::SetNextWindowPos(ImVec2(windowWidth/2 - 300/2, windowHeight - 210));
                ImGui::SetNextWindowPos(ImVec2(200 + 2 + 2, windowHeight - 210));
                ImGui::SetNextWindowSize(ImVec2(300, 210));
//                // set to minimize
//                ImGui::SetNextWindowCollapsed(true);
            }
#endif
            ImGui::Begin("Speed graph viewer");
            {
                static RollingBuffer rdata1, rdata2, rdata3;
                static float t = 0;
                t += ImGui::GetIO().DeltaTime;

                PhysicalComponent *pPhysicalComponent = nullptr;
                if (gameObject != nullptr) {
                    gameObject->getComponentByClass(pPhysicalComponent);
                }
                if (pPhysicalComponent != nullptr) {
                    Vector3d speed = pPhysicalComponent->getLinearSpeed();
                    rdata1.AddPoint(t, speed.x);
                    rdata2.AddPoint(t, speed.y);
                    rdata3.AddPoint(t, speed.z);
                } else {
                    rdata1.AddPoint(t, 0);
                    rdata2.AddPoint(t, 0);
                    rdata3.AddPoint(t, 0);
                }

                static float history = 10.0f;
                static ImPlotAxisFlags flags = ImPlotAxisFlags_NoTickLabels;

                if (ImPlot::BeginPlot("GameObject Speed##Rolling", ImVec2(-1, 150))) {
                    ImPlot::SetupAxes(nullptr, nullptr, flags, flags);
                    ImPlot::SetupAxisLimits(ImAxis_X1, 0, history, ImGuiCond_Always);
                    ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 1);
                    ImPlot::PlotLine("Speed X##ImPlotSpeedX", &rdata1.Data[0].x, &rdata1.Data[0].y, rdata1.Data.size(),
                                     0, 0,
                                     2 * sizeof(float));
                    ImPlot::PlotLine("Speed Y##ImPlotSpeedY", &rdata2.Data[0].x, &rdata2.Data[0].y, rdata2.Data.size(),
                                     0, 0,
                                     2 * sizeof(float));
                    ImPlot::PlotLine("Speed Z##ImPlotSpeedZ", &rdata3.Data[0].x, &rdata3.Data[0].y, rdata3.Data.size(),
                                     0, 0,
                                     2 * sizeof(float));
                    ImPlot::EndPlot();
                }
                ImGui::SliderFloat("History", &history, 1, 30, "%.1f s");
                rdata1.Span = history;
            }
            ImGui::End();
        }
        {
            //            ImGui::Begin("Project files");
            //
            //            ImGui::End();
        }
        {
            //            ImGui::Begin("Game settings");
            //            ImGui::Text("Particle speed:");
            //            ImGui::InputFloat("##PhysicalEngineParticleSpeed", game.getPtrSpeed(), 0.1f, 1.0f, "%.1f");
            //            ImGui::End();
        }
        {
#ifndef __EMSCRIPTEN__
            ImGui::Begin("Scene View", nullptr, ImGuiWindowFlags_NoCollapse);
            {
                ImGui::BeginChild("GameRender");
                ImVec2 windowSize = ImGui::GetWindowSize();
                ImGui::Image((ImTextureID) scene->getFrameBufferId(), windowSize, ImVec2(0, 1), ImVec2(1, 0));
                ImGui::EndChild();
            }
            ImGui::End();
#endif
        }
#ifdef __EMSCRIPTEN__
        startPosition = false;
#endif
    }
    ImGui::Render();
}

void PhysicalEngineLauncher::updateGame(std::chrono::steady_clock::time_point &start) {
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - start)
            .count();
    start = std::chrono::steady_clock::now();
    scene->update((float) deltaTime / 1000.0f);
    //    scene->update(1000.0f / ImGui::GetIO().Framerate);
}

void PhysicalEngineLauncher::updateScreen() {
    // Update viewport
    int display_w, display_h;
#ifdef __EMSCRIPTEN__
    emscripten_get_canvas_element_size("#canvas", &display_w, &display_h);
#else
    glfwGetFramebufferSize(window, &display_w, &display_h);
#endif
    updateViewport(display_w, display_h);

    // If window is minimized, don't draw anything (to avoid draw in a 0x0 window)
    if (!isMinimized()) {

        // Clear Main Screen
        clearScreen();

#ifndef __EMSCRIPTEN__
        // If not in fullscreen, clear the opengl window
        if (!isFullScreen) {
            glBindFramebuffer(GL_FRAMEBUFFER, scene->getFrameBufferId());
            clearScreen();
        }
#endif

        // Draw game
        scene->draw(display_w, display_h);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
    // Swap buffers
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
}

void PhysicalEngineLauncher::clearScreen() {
    glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!
}

void PhysicalEngineLauncher::updateViewport(int width, int height) {
    glViewport(0, 0, width, height);
    scene->updateViewport(width, height);
    if (!isFullScreen) {
        windowWidth = width;
        windowHeight = height;
    }
}


void PhysicalEngineLauncher::toggleFullScreen() {
#ifndef __EMSCRIPTEN__
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if (isFullScreen) {
        auto xPos = mode->width / 2 - windowWidth / 2;
        auto yPos = mode->height / 2 - windowHeight / 2;
        glfwSetWindowMonitor(window, nullptr, xPos, yPos, windowWidth, windowHeight, 0);
        isFullScreen = false;
    } else {
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        isFullScreen = true;
    }
#endif
}

bool PhysicalEngineLauncher::isMinimized() const {
    return (windowWidth == 0 || windowHeight == 0);
}

// void PhysicalEngineLauncher::focusCameraOnGameObject() {
//     if (gameObject != nullptr)
//         scene->setCameraPosition(gameObject->transform.getPosition());
// }
