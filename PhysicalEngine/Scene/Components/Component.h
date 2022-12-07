#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
//#include <map>

#define RIGIDBODY_COMPONENT "Rigidbody"
#define PARTICLE_COMPONENT "Particle"
//#define COLLIDER_COMPONENT "Collider"

#define RIGIDBODY_PLANE_COLLIDER "RigidbodyPlaneColliderComponent"
#define RIGIDBODY_SPHERE_COLLIDER "RigidbodySphereColliderComponent"
#define RIGIDBODY_CUBOID_RECTANGLE_COLLIDER "RigidbodyCuboidRectangleColliderComponent"

class GameObject;

class Component {
public:
    static const char* componentsNamesList[3];

private:
    static constexpr const char* COMPONENT_TYPE = "Component";

protected:
    GameObject* m_gameObject;

public:
    explicit Component(GameObject* gameObject);

    virtual ~Component();

    virtual void update(float time) = 0;

    virtual void drawGui() = 0;

    virtual std::string getName() const = 0;

    GameObject* getGameObject();

    static Component* createComponent(const std::string& name, GameObject* gameObject);
};


#endif // COMPONENT_H
