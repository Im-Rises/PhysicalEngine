#include "Axis.h"

#include "glad/glad.h"

const char *Axis::vShaderCode = "#version 330 core\n"
                                "layout (location = 0) in vec3 aPos;\n"
                                "\n"
                                //                                "uniform mat4 model;\n"
                                //                                "uniform mat4 view;\n"
                                //                                "uniform mat4 projection;\n"
                                "\n"
                                "void main()\n"
                                "{\n"
                                //                                "    gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
                                "    gl_Position = vec4(aPos, 1.0f);\n"
                                "}\0";

const char *Axis::fShaderCode = "#version 330 core\n"
                                "out vec4 FragColor;\n"
                                "\n"
                                "void main()\n"
                                "{\n"
                                "    FragColor = vec4(1.0f, 0.5f, 0.5f, 1.0f);\n"
                                "}\0";

Axis::Axis() : shader(vShaderCode, fShaderCode, true) {
    create();
}


void Axis::create() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    shader.use();
}

Axis::~Axis() {
    destroy();
}

void Axis::destroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Axis::draw(int display_w, int display_h, glm::mat4 view, float fov) {
    shader.use();
    glBindVertexArray(VBO);
    glDrawArrays(GL_LINE_STRIP, 0, 6);
}
