#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Shader/Shader.h"
#include "Mesh/Mesh.h"
#include "../Vector3d/Vector3d.h"
#include "Transform.h"

class Rigidbody;

class Component;

class GameObject {
private:
    std::string name;

    // Base components
    Transform transform;
    Mesh mesh;

    // Optional components
    Rigidbody *m_rigidBody = nullptr;
    std::vector<Component *> components;

    // OpenGL elements
    unsigned int VBO, VAO, EBO;
    Shader shader;


    // Engine other elements
    // std::vector<GameObject *> children;

public:
    GameObject(Mesh mesh, Transform transform);

private:
    void create();


public:
    ~GameObject();

private:
    void destroy();

public:
    void update();

    void draw(int display_w, int display_h, glm::mat4 view, float fov);

    void AddRigidbody(Rigidbody *integrable) {
        m_rigidBody = integrable;
    }

    Rigidbody *getRigidBody() { return m_rigidBody; }

    bool hasRigidbody() {
        return m_rigidBody != nullptr;
    }

    std::string getName();

    Vector3d *getPtrPosition();
};


#endif //GAMEOBJECT_H
