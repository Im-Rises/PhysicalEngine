#include "SphereCollider.h"

SphereCollider::SphereCollider(GameObject *gameObject, float radius) : Collider(gameObject) {
    m_radius = radius;
}

void SphereCollider::update(float time) {
}

void SphereCollider::drawGui() {
}

std::string SphereCollider::getName() const {
    return COMPONENT_TYPE;
}

float SphereCollider::getRadius() const {
    return m_radius;
}

void SphereCollider::setRadius(float radius) {
    this->m_radius = radius;
}

