#include "PhysicHandler.h"
#include <iostream>
#include "Components/PhysicalComponent/Particle/Particle.h"
#include "GameObject.h"

PhysicHandler::PhysicHandler() {

}

void PhysicHandler::update(GameObject *gameObject, float deltaTime) {
    Particle *particleComponent = nullptr;
    gameObject->getComponentByClass(particleComponent);
    if (particleComponent != nullptr) {
        move(gameObject, particleComponent, deltaTime);
    }
}

void PhysicHandler::move(GameObject *gameObject, Particle *particle, float deltaTime) {
    gameObject->transform.setPosition(gameObject->transform.getPosition() + particle->getLinearSpeed() * deltaTime);
}


//void PhysicHandler::update(float time) {
////    fixedDeltaTime += static_cast<float>(time);
////    timeToAdjustFrameRate += static_cast<float>(time);
////    if (timeToAdjustFrameRate > 1.0f / fixedUpdatePerSecond) {
//////        m_gameObject->->recalculateAll(fixedDeltaTime);
////        timeToAdjustFrameRate -= 1.0f / fixedUpdatePerSecond;
////        if (timeToAdjustFrameRate > 1) {
////            timeToAdjustFrameRate -= 1;
////        }
////        fixedDeltaTime = 0;
////    }
//
//}
