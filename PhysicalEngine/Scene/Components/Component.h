#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
// #include <map>

#define RIGIDBODY_COMPONENT "Rigidbody"
#define PARTICLE_COMPONENT "Particle"
// #define COLLIDER_COMPONENT "Collider"

#define RIGIDBODY_PLANE_COLLIDER "Rigidbody_Plane_Collider"
#define RIGIDBODY_SPHERE_COLLIDER "Rigidbody_Sphere_Collider"
#define RIGIDBODY_CUBOID_RECTANGLE_COLLIDER "Rigidbody_CuboidRectangle_Collider"

class GameObject;

class Component {
public:
    static const char *componentsNamesList[6];

private:
    static constexpr const char *COMPONENT_TYPE = "Component";

protected:
    GameObject *m_gameObject;

public:
    explicit Component(GameObject *gameObject);

    virtual ~Component();

    virtual void update(float time) = 0;

    virtual void drawGui() = 0;

    [[nodiscard]] virtual auto getName() const -> std::string = 0;

    auto getGameObject() -> GameObject *;

    static auto createComponent(const std::string &name, GameObject *gameObject) -> Component *;
};


#endif // COMPONENT_H
