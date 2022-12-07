#include "RigidbodyPlaneCollider.h"

RigidbodyPlaneCollider::RigidbodyPlaneCollider(GameObject* gameObject) : RigidbodyPrimitiveCollider(gameObject) {
}

void RigidbodyPlaneCollider::drawGui() {
}

std::string RigidbodyPlaneCollider::getName() const {
    return this->COMPONENT_TYPE;
}
