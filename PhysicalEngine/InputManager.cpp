#include "InputManager.h"

#include "GLFW/glfw3.h"
#include <iostream>

#include "PhysicalEngineLauncher.h"
#include "Scene/Scene.h"
#include "Utility/Vector3d.h"

bool InputManager::mouseRightButtonPressed = false;
bool InputManager::mouseLeftButtonPressed = false;

float InputManager::mouseLastPosX = 0.0;
float InputManager::mouseLastPosY = 0.0;

GLFWwindow *InputManager::m_window = nullptr;

void InputManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto *engine = (PhysicalEngineLauncher *) glfwGetWindowUserPointer(window);

    switch (action) {
        case GLFW_PRESS: {
            keyPressed(window, key, engine);
            break;
        }
            //    case GLFW_RELEASE: {
            //        keyReleased(window, key, engine);
            //        break;
            //    }
            //    case GLFW_REPEAT: {
            //        keyRepeated(window, key, engine);
            //        break;
            //    }
            //    default: {
            //        std::cout << "Unknown keyboard action" << std::endl;
            //        break;
            //    }
    }
}

void InputManager::keyPressed(GLFWwindow *window, int key, PhysicalEngineLauncher *engine) {
    Camera *camera = engine->scene->getCameraPtr();
    switch (key) {
        case GLFW_KEY_ESCAPE: {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        }
            //    case GLFW_KEY_UP: {
            //        camera->moveForward();
            //        break;
            //    }
            //    case GLFW_KEY_DOWN: {
            //        camera->moveBackward();
            //        break;
            //    }
            //    case GLFW_KEY_LEFT: {
            //        camera->moveLeft();
            //        break;
            //    }
            //    case GLFW_KEY_RIGHT: {
            //        camera->moveRight();
            //        break;
            //    }
            //    case GLFW_KEY_RIGHT: {
            //        engine->game.goRight();
            //        break;
            //    }
            //    case GLFW_KEY_LEFT: {
            //        engine->game.goLeft();
            //        break;
            //    }
            //    case GLFW_KEY_UP: {
            //        engine->game.goUp();
            //        break;
            //    }
            //    case GLFW_KEY_DOWN: {
            //        engine->game.goDown();
            //        break;
            //    }
            //    case GLFW_KEY_F: {
            //        engine->focusCameraOnGameObject();
            //        break;
            //    }
        case GLFW_KEY_F11: {
            engine->toggleFullScreen();
            break;
        }
        default: {
            break;
        }
    }
}

// void InputManager::keyReleased(GLFWwindow* window, int key, PhysicalEngineLauncher* engine) {
// }
//
// void InputManager::keyRepeated(GLFWwindow* window, int key, PhysicalEngineLauncher* engine) {
//     //    // measure number of function calls per second
//     //    static int counter = 0;
//     //    static double lastTime = glfwGetTime();
//     //    double currentTime = glfwGetTime();
//     //    counter++;
//     //    if (currentTime - lastTime >= 1.0)
//     //    { // If last prinf() was more than 1 sec ago
//     //        // printf and reset timer
//     //        printf("%d", counter);
//     //        counter = 0;
//     //        lastTime += 1.0;
//     //    }
//
//     Camera* camera = engine->scene->getCameraPtr();
//     switch (key)
//     {
//     case GLFW_KEY_UP: {
//         camera->moveForward();
//         break;
//     }
//     case GLFW_KEY_DOWN: {
//         camera->moveBackward();
//         break;
//     }
//     case GLFW_KEY_LEFT: {
//         camera->moveLeft();
//         break;
//     }
//     case GLFW_KEY_RIGHT: {
//         camera->moveRight();
//         break;
//     }
//     default: {
//         break;
//     }
//     }
// }

void InputManager::scroll_callback(GLFWwindow *window, double xOffset, double yOffset) {
//    auto* engine = (PhysicalEngineLauncher*)glfwGetWindowUserPointer(window);
//    Camera* camera = engine->scene->getCameraPtr();
//    camera->setScrollOffset(yOffset);
}

void InputManager::cursor_position_callback(GLFWwindow *window, double xPos, double yPos) {
    if (mouseRightButtonPressed) {
        auto *engine = (PhysicalEngineLauncher *) glfwGetWindowUserPointer(window);
        Camera *camera = engine->scene->getCameraPtr();
        float xOffset = static_cast<float>(xPos) - mouseLastPosX;
        float yOffset = mouseLastPosY - static_cast<float>(yPos);
        camera->processMouseMovement(xOffset, yOffset);
    }
    mouseLastPosX = static_cast<float>(xPos);
    mouseLastPosY = static_cast<float>(yPos);
}

void InputManager::mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    mouseRightButtonPressed = (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS);
    mouseLeftButtonPressed = (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS);
}

bool InputManager::isForwardKeyPressed() {
    return glfwGetKey(m_window, GLFW_KEY_UP) == GLFW_PRESS || glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS;
}

bool InputManager::isBackwardKeyPressed() {
    return glfwGetKey(m_window, GLFW_KEY_DOWN) == GLFW_PRESS || glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS;
}

bool InputManager::isLeftKeyPressed() {
    return glfwGetKey(m_window, GLFW_KEY_LEFT) == GLFW_PRESS || glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS;
}

bool InputManager::isRightKeyPressed() {
    return glfwGetKey(m_window, GLFW_KEY_RIGHT) == GLFW_PRESS || glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS;
}

bool InputManager::isUpKeyPressed() {
    return glfwGetKey(m_window, GLFW_KEY_PAGE_UP) == GLFW_PRESS;
}

bool InputManager::isDownKeyPressed() {
    return glfwGetKey(m_window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS;
}
