#include "Camera.h"

#include "../InputManager.h"

Camera::Camera() {
}

Camera::~Camera() = default;

void Camera::moveForward() {
    cameraPosMovementBuffer += cameraMoveSpeed * cameraFront;
}

void Camera::moveBackward() {
    cameraPosMovementBuffer -= cameraMoveSpeed * cameraFront;
}

void Camera::moveLeft() {
    cameraPosMovementBuffer -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraMoveSpeed;
}

void Camera::moveRight() {
    cameraPosMovementBuffer += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraMoveSpeed;
}

void Camera::processMouseMovement(float xOffset, float yOffset) {
    xOffset *= cameraSensitivity;
    yOffset *= cameraSensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (constrainPitch)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }


    frontBuffer.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    frontBuffer.y = sin(glm::radians(pitch));
    frontBuffer.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
}

float Camera::getFov() const {
    return fov;
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}


void Camera::update(float deltaTime) {
    if (InputManager::isForwardKeyPressed())
    {
        moveForward();
    }
    if (InputManager::isBackwardKeyPressed())
    {
        moveBackward();
    }
    if (InputManager::isLeftKeyPressed())
    {
        moveLeft();
    }
    if (InputManager::isRightKeyPressed())
    {
        moveRight();
    }
    if (InputManager::isUpKeyPressed())
    {
        cameraPosMovementBuffer += cameraMoveSpeed * cameraUp;
    }
    if (InputManager::isDownKeyPressed())
    {
        cameraPosMovementBuffer -= cameraMoveSpeed * cameraUp;
    }

    cameraPosMovementBuffer += scrollOffset * cameraMoveSpeed * cameraUp;

    // Update camera position and rotation
    cameraPos += cameraPosMovementBuffer * deltaTime;
    if (frontBuffer != glm::vec3(0.0f, 0.0f, 0.0f))
    {
        cameraFront = glm::normalize(frontBuffer);
    }
    // Reset camera buffers
    cameraPosMovementBuffer = glm::vec3(0.0f, 0.0f, 0.0f);
    frontBuffer = glm::vec3(0.0f, 0.0f, 0.0f);
    scrollOffset = 0.0f;
}

void Camera::setScrollOffset(float offset) {
    scrollOffset = offset * scrollSensitivity;
}
