#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <map>
#include "../Shader/Shader.h"
#include "../Utility/Vector3d.h"

#include "Components/Mesh/Mesh.h"
#include "Components/Transform/Transform.h"

class Component;

class GameObject {
private:
    // Object name
    std::string gameObjectName;

    // Optional components
    std::vector<Component *> components;
//    std::map<std::string, Component *> components;

    // OpenGL elements
    unsigned int VBO, VAO, EBO;
    Shader shader;

    // Engine other elements
    // std::vector<GameObject *> children;

public:
    // Base components
    Transform transform;
    Mesh mesh;
//    std::unique_ptr<Mesh> mesh;

    explicit GameObject(Mesh mesh);

private:
    void create();

public:
    ~GameObject();

private:
    void destroy();

public:
    void update(float deltaTime);

    void draw(int display_w, int display_h, glm::mat4 view, float fov);

public:
    void drawTransformGui();

    void drawMeshGui();

public:
    std::string getName() const;

public:
    const std::vector<Component *> &getComponents() const;

    void addComponent(Component *component);

    void addComponentByName(const std::string &name);

    template<typename T>
    void addComponentByClass(T *&c) {
        c = new T(this);
        if (c != nullptr) {
            components.push_back(c);
        }
    }

    Component *getComponentByName(const std::string &name) const;

    template<class T>
    void getComponentByClass(T *&c) {
        for (auto &component: components) {
            if (dynamic_cast<T *>(component) != nullptr) {
                c = dynamic_cast<T *>(component);
            }
        }
    }

    void deleteComponentByName(const std::string &name);

    template<class T>
    void deleteComponentByClass(T *&c) {
        for (auto it = components.begin(); it != components.end(); ++it) {
            if (dynamic_cast<T *>(*it) != nullptr) {
                components.erase(it);
                delete *it;
                return;
            }
        }
    }
};


#endif //GAMEOBJECT_H
