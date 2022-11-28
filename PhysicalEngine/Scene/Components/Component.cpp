#include "Component.h"
#include "Collider/Collider.h"
#include "PhysicalComponent/Particle/Particle.h"
#include "PhysicalComponent/Rigidbody/Rigidbody.h"

#include <iostream>

const char* Component::componentsNamesList[] = { RIGIDBODY_COMPONENT, PARTICLE_COMPONENT, COLLIDER_COMPONENT };

Component::Component(GameObject* gameObject) {
    this->m_gameObject = gameObject;
}

Component::~Component() {
}

std::string Component::getName() const {
    return Component::COMPONENT_TYPE;
}

Component* Component::createComponent(const std::string& name, GameObject* gameObject) {
    int index = 0;

    for (auto& componentName : Component::componentsNamesList)
    {
        if (componentName == name)
        {
            switch (index)
            {
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
    std::cerr << "Component::createComponent: Unknown component name" << std::endl;
    return nullptr;
}
GameObject* Component::getGameObject() {
    return m_gameObject;
}

// Component *Component::createComponent(std::string name) {
//     return new Component(name, nullptr);
// }
