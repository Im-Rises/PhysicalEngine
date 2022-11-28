#ifndef AXIS_H
#define AXIS_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "../Shader/Shader.h"

class Axis {
private:
    unsigned int VBO, VAO;
    Shader shader;
    float vertices[36] = {
            0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,// Line 1 (R)
            0.95f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,// Line 2 (G)
            0.0f, 0.95f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,// Line 3 (B)
            0.0f, -0.95f, 0.0f, 0.0f, 0.0f, 1.0f,
    };

    static const char *vShaderCode;

    static const char *fShaderCode;

public:
    Axis();

private:
    void create();

public:
    ~Axis();

private:
    void destroy();

public:
    void draw(int display_w, int display_h, glm::mat4 view, float fov);
};


#endif //AXIS_H
