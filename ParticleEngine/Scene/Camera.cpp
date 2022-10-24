#include "Camera.h"

Camera::Camera() {
//    viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 30.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f));
}

Camera::~Camera() = default;



//void Camera::update() {
//
//}
//
//void Camera::setPosition(const Vector3d &vector3D) {
//    viewMatrix = glm::lookAt(glm::vec3(vector3D.getx(), vector3D.gety(), vector3D.getz()),
//                             glm::vec3(0.0f, 0.0f, 0.0f),
//                             glm::vec3(0.0f, 1.0f, 0.0f));
//}
//
//void Camera::translate(const Vector3d &vector3D) {
//    viewMatrix = glm::translate(viewMatrix, glm::vec3(vector3D.getx(), vector3D.gety(), vector3D.getz()));
//}
//
//void Camera::rotate(const Vector3d &vector3D, float angle) {
//    viewMatrix = glm::rotate(viewMatrix, angle, glm::vec3(vector3D.getx(), vector3D.gety(), vector3D.getz()));
//}
//
//glm::mat4 Camera::getViewMatrix() const {
//    return viewMatrix;
//}

float Camera::getFov() const {
    return fov;
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

