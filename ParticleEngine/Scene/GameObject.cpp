#include "GameObject.h"

#include "glad/glad.h"

#include "Components/Component.h"
#include "Components/PhysicalComponent/Particle/Particle.h"
#include "Components/PhysicalComponent/Particle/Particle.h"
#include "Components/PhysicalComponent/Particle/Particle.h"

#include <utility>

GameObject::GameObject(Mesh mesh) {
    gameObjectName = "GameObject";

    mesh.getVerticesUseIndices();
    this->mesh = std::move(mesh);

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
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh.getVertices().size(), mesh.getVertices().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
//    glEnableVertexAttribArray(1);

    if (mesh.getVerticesUseIndices()) {
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh.getIndices().size(),
                     mesh.getIndices().data(),
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


void GameObject::update(float deltaTime) {
    for (auto &component: components) {
        component->update(deltaTime);
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
    shader.setMat4("model",
                   glm::translate(model, glm::vec3(-transform.positionX, -transform.positionY, -transform.positionZ)));
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    // Handle the VAO, VBO and EBO depending on the mesh type (with or without indices)
    glBindVertexArray(VAO);
    if (mesh.getVerticesUseIndices()) {
        glDrawElements(GL_TRIANGLES, (GLsizei) mesh.getIndices().size(), GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei) mesh.getVertices().size());
    }
}

const std::vector<Component *> &GameObject::getComponents() const {
    return components;
}

void GameObject::addComponent(Component *component) {
    components.push_back(component);
}

void GameObject::addComponentByName(std::string name) {
    for (auto &componentName: Component::componentsNamesList) {
        if (componentName == name) {
            Component *component = Component::createComponent(name, this);
            if (component != nullptr && getComponentByName(name) == nullptr) {
                components.push_back(component);
            }
        }
    }
}

//void GameObject::removeComponent(Component *component) {
//    components.erase(std::remove(components.begin(), components.end(), component), components.end());
//}

void GameObject::drawTransformGui() {
    transform.drawGui();
}

void GameObject::drawMeshGui() {
    mesh.drawGui();
}

//float GameObject::getSpeed() const {
////    Component *particle = (getComponentByClass("Particle"));
////    if (particle != nullptr) {
////        return particle->getSpeed().m_x;
////    }
//    return 0;
//}

std::string GameObject::getName() const {
    return gameObjectName;
}


Component *GameObject::getComponentByName(const std::string &name) const {
    for (auto &component: components) {
        if (component->getName() == name) {
            return component;
        }
    }
    return nullptr;
}

void GameObject::deleteComponentByName(const std::string &name) {
    for (auto &component: components) {
        if (component->getName() == name) {
            components.erase(std::remove(components.begin(), components.end(), component), components.end());
            delete component;
            return;
        }
    }
}




