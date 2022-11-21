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
    Quaternion rotation = gameObject->transform.getRotation();
    rotation.updateByAngularSpeed(rigidbody->getAngularSpeed(), deltaTime);
    gameObject->transform.setRotation(rotation);
}
