#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Utility/Vector3d.h"

class Camera {
public:
    const float fov = 90.0f;// In degrees

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 30.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float cameraMoveSpeed = 0.05f;
    float cameraSensitivity = 0.1f;

    float yaw = -90.0f;
    float pitch = 0.0f;

    bool constrainPitch = true;

public:
    Camera();

    ~Camera();

    void moveForward(float speed);

    void moveBackward(float speed);

    void moveLeft(float speed);

    void moveRight(float speed);

    void processMouseMovement(float xOffset, float yOffset);

    glm::mat4 getViewMatrix() const;

    float getFov() const;
};


#endif //CAMERA_H
