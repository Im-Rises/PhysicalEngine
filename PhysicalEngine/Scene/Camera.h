#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Vector3d/Vector3d.h"

class Camera {
private:
    glm::mat4 viewMatrix;
    double fov = 90.0f;// In degrees

public:
    Camera();

    ~Camera();

    void update();

    void translate(Vector3d vector3D);

    void rotate(Vector3d vector3D, float angle);

    glm::mat4 getViewMatrix();

    float getFov();
};


#endif //CAMERA_H
