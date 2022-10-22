#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Utility/Vector3d.h"

class Camera {
private:
    glm::mat4 viewMatrix;
    const float fov = 90.0f;// In degrees

public:
    Camera();

    ~Camera();

    void update();

    void translate(const Vector3d &vector3D);

    void rotate(const Vector3d &vector3D, float angle);

    glm::mat4 getViewMatrix() const;

    float getFov() const;
};


#endif //CAMERA_H
