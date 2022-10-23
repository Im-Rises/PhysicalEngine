#include "ColliderHandler.h"

#include "Scene.h"

ColliderHandler::ColliderHandler(Scene *scene) {
    this->scene = scene;
}

ColliderHandler::~ColliderHandler() {
}

void ColliderHandler::update(float deltaTime) {
    for (auto &gameObject: scene->getGameObjects()) {
//        if (gameObject->hasComponent<Rigidbody>()) {
//            Rigidbody *rigidbody = gameObject->getComponent<Rigidbody>();
//            if (rigidbody->hasCollider()) {
//                Collider *collider = rigidbody->getCollider();
//                collider->update(deltaTime);
//            }
//        }
    }
}
