#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
protected:
    std::string name = "Component";

public:
    Component();

    ~Component();

    virtual void update() = 0;
};


#endif //COMPONENT_H
