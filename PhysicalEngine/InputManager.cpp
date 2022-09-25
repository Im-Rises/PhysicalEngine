#include "InputManager.h"

#include "PhysicalEngine.h"
#include "GLFW/glfw3.h"
#include "Vector3d/Vector3d.h"

#include "Scene/Scene.h"
#include <iostream>

void InputManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto *engine = (PhysicalEngine *) glfwGetWindowUserPointer(window);

    switch (action) {
        case GLFW_PRESS: {
            keyPressed(window, key);
            engine->scene->translateCamera(Vector3D(1, 1, 1));
            break;
        }
        case GLFW_RELEASE: {
            keyReleased(window, key);
            break;
        }
        case GLFW_REPEAT: {
            keyRepeated(window, key);
            break;
        }
        default: {
            std::cout << "Unknown keyboard action" << std::endl;
            break;
        }
    }
}

void InputManager::keyPressed(GLFWwindow *window, int key) {
    switch (key) {
        case GLFW_KEY_ESCAPE: {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        }
        case GLFW_KEY_UP: {
            break;
        }
        case GLFW_KEY_DOWN: {
            break;
        }
        case GLFW_KEY_LEFT: {
            break;
        }
        case GLFW_KEY_RIGHT: {
            break;
        }

    }
}

void InputManager::keyReleased(GLFWwindow *window, int key) {

}

void InputManager::keyRepeated(GLFWwindow *window, int key) {

}
