#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Shader/Shader.h"
#include "../Utility/Vector3d.h"
#include <algorithm>
#include <map>
#include <vector>

#include "Components/Mesh/Mesh.h"
#include "Components/Transform/Transform.h"

class Scene;

class Component;

class GameObject {
private:
    static unsigned int idCounter;

private:
    // OpenGL variables
    unsigned int VBO, VAO, EBO;
    //    Shader shader;
    //    static unsigned int shaderCount;
    static Shader* defaultShader;


protected:
    //    // GameObject color
    //    glm::vec4 color = glm::vec4(1.0f, 0.5f, 0.5f, 1.0f);

    // Id
    unsigned int id;

    // Object name
    std::string gameObjectName;

    // Scene containing the object
    Scene* parentScene = nullptr;

    // Optional components
    std::vector<Component*> components;
    std::map<std::string, Component*> componentsMap;

public:
    // Base components
    Transform transform;
    Mesh* mesh = nullptr;

    // Engine other elements
    // std::vector<GameObject *> children;

public:
    explicit GameObject(Scene* scene);

    explicit GameObject(Scene* scene, Mesh* mesh);

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

    Scene* getScenePtr() const;

    glm::mat4 convertToGlmMat4(Matrix34& matrix) const;

public:
    const std::vector<Component*>& getComponents() const;

    void addComponent(Component* component);

    void addComponentByName(const std::string& name);

    template <typename T>
    void addComponentByClass(T*& comp) {
        comp = new T(this);
        if (comp != nullptr)
        {
            components.push_back(comp);
        }
    }

    Component* getComponentByName(const std::string& name) const;

    template <class T>
    void getComponentByClass(T*& comp) {
        for (auto& component : components)
        {
            if (dynamic_cast<T*>(component) != nullptr)
            {
                comp = dynamic_cast<T*>(component);
            }
        }
    }

    bool hasComponentByName(const std::string& name) const;

//    template <class T>
//    bool hasComponentByClass(T*& comp) {
//        return std::any_of(components.begin(), components.end(), [&](Component* component) {
//            if (dynamic_cast<T*>(component) != nullptr)
//            {
//                comp = dynamic_cast<T*>(component);
//                return true;
//            }
//        });
//    }

    template <class T>
    bool hasComponentByClass(T*& comp) {
        for (Component* component : components) {
            if (T* t = dynamic_cast<T*>(component)) {
                comp = t;
                return true;
            }
        }
        return false;
    }


    void deleteComponentByName(const std::string& name);

    template <class T>
    void deleteComponentByClass(T*& comp) {
        for (auto it = components.begin(); it != components.end(); ++it)
        {
            if (dynamic_cast<T*>(*it) != nullptr)
            {
                components.erase(it);
                delete *it;
                return;
            }
        }
    }

    Mesh* getMesh() const;
};


#endif // GAMEOBJECT_H
