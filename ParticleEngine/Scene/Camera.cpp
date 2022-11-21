#include "Camera.h"

Camera::Camera() {
}

Camera::~Camera() = default;

void Camera::moveForward(float speed) {
    cameraPos += cameraMoveSpeed * cameraFront;
}

void Camera::moveBackward(float speed) {

    cameraPos -= cameraMoveSpeed * cameraFront;
}

void Camera::moveLeft(float speed) {

    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraMoveSpeed;
}

void Camera::moveRight(float speed) {

    cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraMoveSpeed;
}

void Camera::processMouseMovement(float xOffset, float yOffset) {
    xOffset *= cameraSensitivity;
    yOffset *= cameraSensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (constrainPitch) {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

float Camera::getFov() const {
    return fov;
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}
