#ifndef DEF_CAMERA
#define DEF_CAMERA

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
    glm::mat4 viewMatrix;
    double fov = glm::radians(90.0);

public:
    Camera();

    ~Camera();

    void update();

    void rotate();

    void translate();

    glm::mat4 getViewMatrix();
};


#endif //DEF_CAMERA
