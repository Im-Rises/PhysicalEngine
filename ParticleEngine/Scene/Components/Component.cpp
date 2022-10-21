#include "Component.h"
#include "PhysicalComponent/Rigidbody/Rigidbody.h"
#include "PhysicalComponent/Particle/Particle.h"
#include "Collider/Collider.h"

#include <iostream>

Component::Component(GameObject *gameObject) {
    this->m_gameObject = gameObject;
}

Component::~Component() {
}

std::string Component::getName() const {
    return Component::COMPONENT_TYPE;
}

Component *Component::createComponent(const std::string &name, GameObject *gameObject) {
    int index = 0;

    for (auto &componentName: Component::componentsNamesList) {
        if (componentName == name) {
            switch (index) {
                case 0: {
                    return new Rigidbody(gameObject);
                }
                case 1: {
                    return new Particle(gameObject);
                }
                case 2: {
                    return new Collider(gameObject);
                }
                default: {
                    std::cerr << "Component::createComponent: Unknown component name" << std::endl;
                    return nullptr;
                }
            }
        }
        index++;
    }
}

//Component *Component::createComponent(std::string name) {
//    return new Component(name, nullptr);
//}
