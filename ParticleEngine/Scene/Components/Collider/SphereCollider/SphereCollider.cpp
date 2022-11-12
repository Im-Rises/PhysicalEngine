#include "SphereCollider.h"
SphereCollider::SphereCollider(GameObject* gameObject, float radius) : Collider(gameObject) {

    m_radius = radius;
}
