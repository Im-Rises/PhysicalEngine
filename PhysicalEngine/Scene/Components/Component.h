#ifndef COMPONENT_H
#define COMPONENT_H


class Component {
private:

public:
    Component();

    ~Component();

    virtual void update() = 0;
};


#endif //COMPONENT_H
