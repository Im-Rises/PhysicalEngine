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

    float cameraSpeed = 0.05f;

public:
    Camera();

    ~Camera();

    glm::mat4 getViewMatrix() const;

//    void update();

//    void setPosition(const Vector3d &vector3D);
//
//    void translate(const Vector3d &vector3D);
//
//    void rotate(const Vector3d &vector3D, float angle);
//
//    glm::mat4 getViewMatrix() const;

    float getFov() const;
};


#endif //CAMERA_H
