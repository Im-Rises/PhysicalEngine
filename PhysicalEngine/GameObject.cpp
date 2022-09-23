#include "GameObject.h"

#include <glad/glad.h>

#include <utility>

GameObject::GameObject() : shader("shaders/shader.vert", "shaders/shader.frag") {
    //Cube
//    vertices = {
//            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//
//            -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//
//            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//
//            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//
//            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//
//            -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
//            -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
//    };

    vertices = {
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    };

    create();
}

GameObject::GameObject(std::vector<float> ver) : shader("shaders/shader.vert", "shaders/shader.frag") {
    vertices = std::move(ver);
    create();
}


void GameObject::create() {
    x = y = z = 0;
    width = height = depth = 1;
    rotationX = rotationY = rotationZ = 0;
    scaleX = scaleY = scaleZ = 1;
    //colorR = colorG = colorB = colorA = 1;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    shader.use();
}

GameObject::~GameObject() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void GameObject::update() {
//    for (auto &component : components) {
//        component->update();
//    }
}

void GameObject::draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
