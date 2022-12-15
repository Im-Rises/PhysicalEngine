#include "RigidbodyPlaneCollider.h"
#include "../../../../../Utility/Matrix33.h"
#include "../../../../GameObject.h"
#include "../../../Transform/Transform.h"

RigidbodyPlaneCollider::RigidbodyPlaneCollider(GameObject* gameObject) : RigidbodyPrimitiveCollider(gameObject) {
}

void RigidbodyPlaneCollider::drawGui() {
}

std::string RigidbodyPlaneCollider::getName() const {
    return this->COMPONENT_TYPE;
}

RigidbodyPrimitiveColliderType RigidbodyPlaneCollider::getColliderType() const {
    return this->COLLIDER_TYPE;
}

Vector3d RigidbodyPlaneCollider::getNormalVector() const {
    Matrix33 rotationMatrix;
    rotationMatrix.setOrientation(m_gameObject->transform.rotation);
    return rotationMatrix * Vector3d(0, 1, 0);
}
void RigidbodyPlaneCollider::update(float time) {

}

//TODO IMPLEMENTER PLUS TARD
float RigidbodyPlaneCollider::getRadius() const {
    return 0.0f;
}
