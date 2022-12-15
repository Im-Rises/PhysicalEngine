#include "RigidbodyPrimitiveCollider.h"

RigidbodyPrimitiveCollider::RigidbodyPrimitiveCollider(GameObject* gameObject) : Component(gameObject) {
}

Vector3d RigidbodyPrimitiveCollider::getCenter() {
    return m_gameObject->transform.getPosition();
}
