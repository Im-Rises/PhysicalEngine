#include "Camera.h"

Camera::Camera() {
    viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Camera::~Camera() {

}

void Camera::update() {

}

void Camera::rotate() {
    viewMatrix = glm::rotate(viewMatrix, 0.1f, glm::vec3(1, 0, 0));
}

void Camera::translate() {
    viewMatrix = glm::translate(viewMatrix, glm::vec3(0, 0.1, 0));
}

glm::mat4 Camera::getViewMatrix() {
    return viewMatrix;
}
