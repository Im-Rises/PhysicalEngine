#include "InputManager.h"

#include <iostream>
#include "GLFW/glfw3.h"

#include "ParticleEngineLauncher.h"
#include "Scene/Scene.h"
#include "Utility/Vector3d.h"

bool InputManager::mouseRightButtonPressed = false;
bool InputManager::mouseLeftButtonPressed = false;

float InputManager::mouseLastPosX = 0.0;
float InputManager::mouseLastPosY = 0.0;

float InputManager::movementSpeed = 0.2f;

//float InputManager::translationSpeed = 0.1f;
//float InputManager::rotationSpeed = 0.0001f;

void InputManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto *engine = (ParticleEngineLauncher *) glfwGetWindowUserPointer(window);

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

void InputManager::keyPressed(GLFWwindow *window, int key, ParticleEngineLauncher *engine) {
    switch (key) {
        case GLFW_KEY_ESCAPE: {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        }
        case GLFW_KEY_RIGHT: {
            engine->game.goRight();
            break;
        }
        case GLFW_KEY_LEFT: {
            engine->game.goLeft();
            break;
        }
        case GLFW_KEY_UP: {
            engine->game.goUp();
            break;
        }
        case GLFW_KEY_DOWN : {
            engine->game.goDown();
            break;
        }
        case GLFW_KEY_F: {
//			engine->game.applyGravity();
            //engine->game.applySpring();
            break;
        }
        case GLFW_KEY_F11: {
            engine->toggleFullScreen();
            break;
        }
        default: {
            break;
        }
    }
}

void InputManager::keyReleased(GLFWwindow *window, int key, ParticleEngineLauncher *engine) {

}

void InputManager::keyRepeated(GLFWwindow *window, int key, ParticleEngineLauncher *engine) {
    //switch (key) {
    //    case GLFW_KEY_UP: {
    //        engine->scene->translateCamera(Vector3d(0, 0, translationSpeed));
    //        break;
    //    }
    //    case GLFW_KEY_DOWN: {
    //        engine->scene->translateCamera(Vector3d(0, 0, -translationSpeed));
    //        break;
    //    }
    //    case GLFW_KEY_LEFT: {
    //        engine->scene->translateCamera(Vector3d(+translationSpeed, 0, 0));
    //        break;
    //    }
    //    case GLFW_KEY_RIGHT: {
    //        engine->scene->translateCamera(Vector3d(-translationSpeed, 0, 0));
    //        break;
    //    }
    //}
}

void InputManager::scroll_callback(GLFWwindow *window, double xOffset, double yOffset) {
    auto *engine = (ParticleEngineLauncher *) glfwGetWindowUserPointer(window);
    engine->scene->translateCamera(Vector3d(0, 0, movementSpeed * (float) yOffset));
}

void InputManager::cursor_position_callback(GLFWwindow *window, double xPos, double yPos) {
    auto *engine = (ParticleEngineLauncher *) glfwGetWindowUserPointer(window);
    if (mouseRightButtonPressed) {
        engine->scene->translateCamera(
                {movementSpeed * (mouseLastPosX - (float) xPos), movementSpeed * ((float) yPos - mouseLastPosY), 0});
    }

    mouseLastPosX = static_cast<float>(xPos);
    mouseLastPosY = static_cast<float>(yPos);

//    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS) {
//        auto *engine = (ParticleEngineLauncher *) glfwGetWindowUserPointer(window);
//        engine->scene->rotateCamera(Vector3d(0, 1, 0), rotationSpeed * (xPos - mouseLastPosX));
//        engine->scene->rotateCamera(Vector3d(1, 0, 0), rotationSpeed * (yPos - mouseLastPosY));
//    } else {
//        mouseLastPosX = xPos;
//        mouseLastPosY = yPos;
//    }
}

void InputManager::mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    mouseRightButtonPressed = (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS);
    mouseLeftButtonPressed = (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS);
}
