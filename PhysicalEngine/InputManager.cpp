#include "InputManager.h"

#include <iostream>
#include "GLFW/glfw3.h"

#include "PhysicalEngine.h"
#include "Scene/Scene.h"
#include "Vector3d/Vector3d.h"

float InputManager::translationSpeed = 0.1f;
float InputManager::rotationSpeed = 0.0001f;

double InputManager::mouseLastPosX = 0.0;
double InputManager::mouseLastPosY = 0.0;

void InputManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto *engine = (PhysicalEngine *) glfwGetWindowUserPointer(window);

    switch (action) {
        case GLFW_PRESS: {
            keyPressed(window, key, engine);
            break;
        }
        case GLFW_RELEASE: {
            keyReleased(window, key, engine);
            break;
        }
        case GLFW_REPEAT: {
            keyRepeated(window, key, engine);
            break;
        }
        default: {
            std::cout << "Unknown keyboard action" << std::endl;
            break;
        }
    }
}

void InputManager::keyPressed(GLFWwindow *window, int key, PhysicalEngine *engine) {
    switch (key) {
        case GLFW_KEY_ESCAPE: {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        }
		case GLFW_KEY_RIGHT: {
			engine->m_game.goRight();
		}
		case GLFW_KEY_LEFT: {
			engine->m_game.goLeft();
		}
		case GLFW_KEY_UP: {
			engine->m_game.goUp();
		}
		case GLFW_KEY_DOWN: {
			engine->m_game.goDown();
		}
    }
}

void InputManager::keyReleased(GLFWwindow *window, int key, PhysicalEngine *engine) {
//    std::cout << "Key released" << std::endl;
}

void InputManager::keyRepeated(GLFWwindow *window, int key, PhysicalEngine *engine) {
    switch (key) {
        case GLFW_KEY_UP: {
            engine->scene->translateCamera(Vector3d(0, 0, translationSpeed));
            break;
        }
        case GLFW_KEY_DOWN: {
            engine->scene->translateCamera(Vector3d(0, 0, -translationSpeed));
            break;
        }
        case GLFW_KEY_LEFT: {
            engine->scene->translateCamera(Vector3d(+translationSpeed, 0, 0));
            break;
        }
        case GLFW_KEY_RIGHT: {
            engine->scene->translateCamera(Vector3d(-translationSpeed, 0, 0));
            break;
        }
    }
}

void InputManager::cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS) {
        auto *engine = (PhysicalEngine *) glfwGetWindowUserPointer(window);
        engine->scene->rotateCamera(Vector3d(0, 1, 0), rotationSpeed * (xpos - mouseLastPosX));
        engine->scene->rotateCamera(Vector3d(1, 0, 0), rotationSpeed * (ypos - mouseLastPosY));
    } else {
        mouseLastPosX = xpos;
        mouseLastPosY = ypos;
    }
}
