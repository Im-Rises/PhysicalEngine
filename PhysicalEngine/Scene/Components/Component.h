#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class GameObject;

class Component {
private:
    std::string name;
protected:
    GameObject *gameObject;

public:
    Component(std::string name, GameObject *gameObject);

    ~Component();

    virtual void update() = 0;

    virtual void drawGui() = 0;

    std::string getName() const;
};


#endif //COMPONENT_H
