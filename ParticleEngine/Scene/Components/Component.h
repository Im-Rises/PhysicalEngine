#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <map>

class GameObject;

class Component {
private:
    static constexpr const char *COMPONENT_TYPE = "Component";

protected:
    GameObject *m_gameObject;

public:
    static constexpr const char *componentsNamesList[3] = {"Rigidbody", "Particle", "Collider"};

public:
    explicit Component(GameObject *gameObject);

    virtual ~Component();

    virtual void update(float time) = 0;

    virtual void drawGui() = 0;

    virtual std::string getName() const = 0;

    static Component *createComponent(const std::string &name, GameObject *gameObject);

};


#endif //COMPONENT_H
