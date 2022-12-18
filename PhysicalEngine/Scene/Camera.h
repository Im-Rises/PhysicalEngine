#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Utility/Vector3d.h"

class Camera {
public:
    const float fov = 90.0f; // In degrees

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float cameraMoveSpeed = 4.0f;
    float cameraSensitivity = 0.1f;

    float yaw = -90.0f;
    float pitch = 0.0f;

    bool constrainPitch = true;

    // Buffers for camera movement
    glm::vec3 cameraPosMovementBuffer = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 frontBuffer;

    // Scroll values
    float scrollOffset = 0.0f;
    float scrollSensitivity = 4.0f;


public:
    Camera();

    ~Camera();

    void moveForward();

    void moveBackward();

    void moveLeft();

    void moveRight();

    void processMouseMovement(float xOffset, float yOffset);

    glm::mat4 getViewMatrix() const;

    float getFov() const;

    void update(float deltaTime);

    void setScrollOffset(float offset);
};


#endif // CAMERA_H
