#include "InputManager.h"

#include <iostream>
#include "GLFW/glfw3.h"

#include "ParticleEngineLauncher.h"
#include "Scene/Scene.h"
#include "Vector3d/Vector3d.h"

//float InputManager::translationSpeed = 0.1f;
//float InputManager::rotationSpeed = 0.0001f;
//
//double InputManager::mouseLastPosX = 0.0;
//double InputManager::mouseLastPosY = 0.0;

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
			engine->game.applyGravity();
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

void InputManager::cursor_position_callback(GLFWwindow *window, double xPos, double yPos) {
//    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS) {
//        auto *engine = (ParticleEngineLauncher *) glfwGetWindowUserPointer(window);
//        engine->scene->rotateCamera(Vector3d(0, 1, 0), rotationSpeed * (xPos - mouseLastPosX));
//        engine->scene->rotateCamera(Vector3d(1, 0, 0), rotationSpeed * (yPos - mouseLastPosY));
//    } else {
//        mouseLastPosX = xPos;
//        mouseLastPosY = yPos;
//    }
}
