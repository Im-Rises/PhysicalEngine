#include "PhysicHandler.h"
#include <iostream>
//#include "Components/PhysicalComponent/Particle/Particle.h"
#include "GameObject.h"
#include "Components/PhysicalComponent/PhysicalComponent.h"

PhysicHandler::PhysicHandler() {

}

void PhysicHandler::update(GameObject *gameObject, float deltaTime) {
    PhysicalComponent *physicalComponent = nullptr;
    gameObject->getComponentByClass(physicalComponent);
    if (physicalComponent != nullptr) {
        move(gameObject, physicalComponent, deltaTime);

        Rigidbody *rigidbody;
        if (gameObject->hasComponentByClass(rigidbody)) {
            angularMove(gameObject, rigidbody, deltaTime);
        }
    }
}

void PhysicHandler::move(GameObject *gameObject, PhysicalComponent *physicalComponent, float deltaTime) {
    gameObject->transform.setPosition(
            gameObject->transform.getPosition() + physicalComponent->getLinearSpeed() * deltaTime);
}

void PhysicHandler::angularMove(GameObject *gameObject, Rigidbody *rigidbody, float deltaTime) {
    gameObject->transform.setRotation(
            gameObject->transform.getRotation() + rigidbody->getAngularSpeed() * deltaTime);
//    std::cout << "angularMove" << gameObject->transform.getRotation() << std::endl;
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
