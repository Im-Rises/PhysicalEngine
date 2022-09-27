#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Shader/Shader.h"
#include "Mesh/Mesh.h"
#include "../Vector3d/Vector3d.h"

class Integrable;

class Component;

class GameObject {
private:
    std::string name;

    bool wireFrame = false;

    Vector3d position;
    float width, height, depth;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;
    float colorR, colorG, colorB, colorA;
    Integrable *m_rigidBody = nullptr;
    Mesh mesh;
    unsigned int VBO, VAO, EBO;
    Shader shader;

    std::vector<Component *> components;

    // std::vector<GameObject *> children;

public:
    GameObject(Mesh mesh);

private:
    void create();


public:
    ~GameObject();

private:
    void destroy();

public:
    void update();

    void draw(int display_w, int display_h, glm::mat4 view);

    void AddRigidbody(Integrable *integrable) {
        m_rigidBody = integrable;
    }

    Integrable *getRigidBody() { return m_rigidBody; }

    bool hasRigidbody() {
        return m_rigidBody != nullptr;
    }

    std::string getName();
};


#endif //GAMEOBJECT_H
