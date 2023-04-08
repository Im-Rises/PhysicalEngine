#include "GameObject.h"

#include "glad/glad.h"

#include "../Utility/Matrix34.h"
#include "Components/Component.h"
#include "Components/PhysicalComponent/Particle/Particle.h"

unsigned int GameObject::idCounter = 0;

Shader *GameObject::defaultShader = nullptr;

GameObject::GameObject(Scene *scene) {
    if (defaultShader == nullptr) {
        defaultShader = new Shader();
    }
    // defaultShader = new Shader();

    id = idCounter++;
    parentScene = scene;
    gameObjectName = "GameObject";
}


GameObject::GameObject(Scene *scene, Mesh *mesh) : GameObject(scene) {
    mesh->getVerticesUseIndices();
    this->mesh = mesh;
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh->getVertices().size(), mesh->getVertices().data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    //    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    //    glEnableVertexAttribArray(0);
    //    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    //    glEnableVertexAttribArray(1);

    if (mesh->getVerticesUseIndices()) {
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh->getIndices().size(),
                     mesh->getIndices().data(),
                     GL_STATIC_DRAW);
    }

    defaultShader->use();
}

GameObject::~GameObject() {
    if (defaultShader != nullptr) {
        delete defaultShader;
        defaultShader = nullptr;
    }
    delete mesh;
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
    auto matrix = transform.getMatrix();
    // auto m3 = matrix.extractMatrix33();
    // m3.inverseMat();
    // Matrix34 m4=matrix.matrix34FromRotationTranslation(m3, Vector3d(matrix(0, 3), matrix(1, 3), matrix(2, 3)));

    glm::mat4 model = convertToGlmMat4(matrix);
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(fov / 2), static_cast<float>(display_w) / static_cast<float>(display_h),
                                  0.1f, 100.0f);

    // Shader use
    defaultShader->use();
    defaultShader->setMat4("model", model);
    defaultShader->setMat4("view", view);
    defaultShader->setMat4("projection", projection);
    //    defaultShader->setVec4("color", color);
    defaultShader->setVec4("color", mesh->getColor());

    // Handle the VAO, VBO and EBO depending on the mesh type (with or without indices)
    glBindVertexArray(VAO);
    if (mesh->getVerticesUseIndices()) {
        glDrawElements(GL_TRIANGLES, (GLsizei) mesh->getIndices().size(), GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei) mesh->getVertices().size());
    }
}

const std::vector<Component *> &GameObject::getComponents() const {
    return components;
}

void GameObject::addComponent(Component *component) {
    components.push_back(component);
}

void GameObject::addComponentByName(const std::string &name) {
    for (auto &componentName: Component::componentsNamesList) {
        if (componentName == name) {
            Component *component = Component::createComponent(name, this);
            if (component != nullptr && getComponentByName(name) == nullptr) {
                components.push_back(component);
            } else if (component != nullptr) {
                delete component;
            }
        }
    }
}

// void GameObject::removeComponent(Component *component) {
//     components.erase(std::remove(components.begin(), components.end(), component), components.end());
// }

void GameObject::drawTransformGui() {
    transform.drawGui();
}

void GameObject::drawMeshGui() {
    mesh->drawGui();
}

std::string GameObject::getName() const {
    return gameObjectName + " " + std::to_string(id);
}

Scene *GameObject::getScenePtr() const {
    return parentScene;
}

glm::mat4 GameObject::convertToGlmMat4(Matrix34 &matrix) const {
    // remplire colonne par colonne
    return glm::mat4(matrix(0, 0), matrix(1, 0), matrix(2, 0), 0,
                     matrix(0, 1), matrix(1, 1), matrix(2, 1), 0,
                     matrix(0, 2), matrix(1, 2), matrix(2, 2), 0,
                     matrix(0, 3), matrix(1, 3), matrix(2, 3), 1);
}


Component *GameObject::getComponentByName(const std::string &name) const {
    for (auto &component: components) {
        if (component->getName() == name) {
            return component;
        }
    }
    return nullptr;
}

bool GameObject::hasComponentByName(const std::string &name) const {
    return std::any_of(components.begin(), components.end(), [&name](Component *component) {
        return component->getName() == name;
    });
}

void GameObject::deleteComponentByName(const std::string &name) {
    for (auto it = components.begin(); it != components.end(); ++it) {
        if ((*it)->getName() == name) {
            delete *it;//TODO: check if it's ok
            components.erase(it);
            return;
        }
    }
}

Mesh *GameObject::getMesh() const {
    return mesh;
}
