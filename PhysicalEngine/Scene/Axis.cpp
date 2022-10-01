#include "Axis.h"

#include "glad/glad.h"

Axis::Axis() {
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
}

Axis::~Axis() {
    destroy();
}

void Axis::destroy() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Axis::draw(int display_w, int display_h, glm::mat4 view, float fov) {
    glBindVertexArray(VBO);
    glDrawArrays(GL_LINE_STRIP, 0, 6);
}
