#include "Component.h"
// #include "Collider/Collider.h"
#include "Collider/ParticleCollider/ParticleCollider.h"
#include "Collider/RigidbodyCollider/RigidbodyCuboidRectangleCollider/RigidbodyCuboidRectangleCollider.h"
#include "Collider/RigidbodyCollider/RigidbodyPlaneCollider/RigidbodyPlaneCollider.h"
#include "Collider/RigidbodyCollider/RigidbodySphereCollider/RigidbodySphereCollider.h"
#include "PhysicalComponent/Particle/Particle.h"
#include "PhysicalComponent/Rigidbody/Rigidbody.h"

#include <iostream>

const char* Component::componentsNamesList[] = { RIGIDBODY_COMPONENT, PARTICLE_COMPONENT, RIGIDBODY_PLANE_COLLIDER, RIGIDBODY_SPHERE_COLLIDER, RIGIDBODY_CUBOID_RECTANGLE_COLLIDER, PARTICLE_COLLIDER_COMPONENT };
// const char* Component::componentsNamesList[] = { RIGIDBODY_COMPONENT, PARTICLE_COMPONENT, COLLIDER_COMPONENT };

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
            //            case 2: {
            //                return new Collider(gameObject);
            //            }
            case 2: {
                return new RigidbodyPlaneCollider(gameObject);
            }
            case 3: {
                return new RigidbodySphereCollider(gameObject, 1.0f);
            }
            case 4: {
                return new RigidbodyCuboidRectangleCollider(gameObject, 1.0f, 1.0f, 1.0f);
            }
            case 5: {
                return new ParticleCollider(gameObject, 1.0f);
            }
            default: {
                std::cerr << "Component::createComponent: Unknown component name" << std::endl;
                return nullptr;
            }
            }
        }
        index++;
    }
    //    std::cerr << "Component::createComponent: Unknown component name" << std::endl;
    //    return nullptr;
}
GameObject* Component::getGameObject() {
    return m_gameObject;
}

// Component *Component::createComponent(std::string name) {
//     return new Component(name, nullptr);
// }
