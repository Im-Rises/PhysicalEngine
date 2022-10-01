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

    virtual void drawGui() = 0;

    std::string getName() const;
};


#endif //COMPONENT_H
