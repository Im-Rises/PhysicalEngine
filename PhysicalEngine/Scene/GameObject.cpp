#include "GameObject.h"

#include "glad/glad.h"

#include "Components/Component.h"
#include "Components/Rigidbody/Rigidbody.h"

#include <utility>

GameObject::GameObject(Mesh mesh) : shader("../../../../shaders/shader.vert", "../../../../shaders/shader.frag") {
    name = "GameObject";
    mesh.getVerticesUseIndices();
    this->mesh = std::move(mesh);

    width = height = depth = 1;
    rotationX = rotationY = rotationZ = 0;
    scaleX = scaleY = scaleZ = 1;
    //colorR = colorG = colorB = colorA = 1;

    create();
}

void GameObject::create() {
    /*
     * Create the VAO, VBO and EBO here to prevent bug in the constructor (read the bug explanation in the link below)
     *
     * https://www.khronos.org/opengl/wiki/Common_Mistakes#The_Object_Oriented_Language_Problem
     */
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh.getPoints().size(), mesh.getPoints().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
//    glEnableVertexAttribArray(1);

    if (mesh.getVerticesUseIndices()) {
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh.getTriangles().size(),
                     mesh.getTriangles().data(),
                     GL_STATIC_DRAW);
    }

    shader.use();
}

GameObject::~GameObject() {
    for (auto &component: components) {
        delete component;
    }
    destroy();
}

void GameObject::destroy() {
    /*
    * Destroy the VAO, VBO and EBO here to prevent bug in the destructor (read the bug explanation in the link below)
    *
    * https://www.khronos.org/opengl/wiki/Common_Mistakes#The_Object_Oriented_Language_Problem
    */
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}


void GameObject::update() {
    for (auto &component: components) {
        component->update();
    }

    if (m_rigidBody != nullptr) {
        position = m_rigidBody->getPosition();
    }
}

void GameObject::draw(int display_w, int display_h, glm::mat4 view, float fov) {
    // Matrix calculations
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(fov / 2), static_cast<float>(display_w) / static_cast<float>(display_h),
                                  0.1f, 100.0f);

    //Shader use
    shader.use();
    shader.setMat4("model", glm::translate(model, glm::vec3(-position.getx(), -position.gety(), -position.getz())));
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    // Handle the VAO, VBO and EBO depending on the mesh type (with or without indices)
    if (mesh.getVerticesUseIndices()) {
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, (GLsizei) mesh.getTriangles().size(), GL_UNSIGNED_INT, 0);
    } else {
        glBindVertexArray(VBO);
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei) mesh.getPoints().size());
    }
}

std::string GameObject::getName() {
    return name;
}
