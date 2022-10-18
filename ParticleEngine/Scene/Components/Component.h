#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <map>

class GameObject;

class Component {
private:
    std::string name;
protected:
    GameObject *gameObject;

public:
    static constexpr const char *componentsNamesList[3] = {"Rigidbody", "Particle", "Collider"};

public:
    Component(std::string name, GameObject *gameObject);

    ~Component();

    virtual void update(float time) = 0;

    virtual void drawGui() = 0;

    std::string getName() const;

    static Component *createComponent(const std::string &name, GameObject *gameObject);

};


#endif //COMPONENT_H
