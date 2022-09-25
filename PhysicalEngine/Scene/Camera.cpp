#include "Camera.h"

Camera::Camera() {
    viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

Camera::~Camera() {

}

void Camera::update() {

}

void Camera::translate(Vector3d vector3D) {
    viewMatrix = glm::translate(viewMatrix, glm::vec3(vector3D.getx(), vector3D.gety(), vector3D.getz()));
}

void Camera::rotate(Vector3d vector3D, float angle) {
//    viewMatrix = glm::rotate(viewMatrix, 0.1f, glm::vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, angle, glm::vec3(vector3D.getx(), vector3D.gety(), vector3D.getz()));
}

glm::mat4 Camera::getViewMatrix() {
    return viewMatrix;
}
