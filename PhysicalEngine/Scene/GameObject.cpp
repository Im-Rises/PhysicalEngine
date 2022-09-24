#include "GameObject.h"

#include "glad/glad.h"

#include <utility>

GameObject::GameObject(Mesh mesh, bool indiced) : shader("shaders/shader.vert", "shaders/shader.frag") {
    this->mesh = std::move(mesh);
    create();
}

void GameObject::create() {
    width = height = depth = 1;
    rotationX = rotationY = rotationZ = 0;
    scaleX = scaleY = scaleZ = 1;
    //colorR = colorG = colorB = colorA = 1;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh.getPoints().size(), mesh.getPoints().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh.getTriangles().size(), mesh.getTriangles().data(),
                 GL_STATIC_DRAW);

    shader.use();

    name = "GameObject";
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

void GameObject::draw(int display_w, int display_h, glm::mat4 view) {
    shader.use();
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    model = glm::rotate(model, (float) 1, glm::vec3(0.5f, 1.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), (float) display_w / (float) display_h, 0.1f, 100.0f);
    shader.setMat4("model", model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);
/*    glBindVertexArray(VAO);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, 36);*/

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, mesh.getTriangles().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

std::string GameObject::getName() {
    return name;
}
