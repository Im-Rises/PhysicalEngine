#include "PhysicalComponent.h"

#include "../../GameObject.h"

float PhysicalComponent::distance(const PhysicalComponent &p) {
    return (m_gameObject->transform.getPosition() - p.m_gameObject->transform.getPosition()).norm();
}

Vector3d PhysicalComponent::getPosition() const {
    return m_gameObject->transform.getPosition();
}

const Vector3d &PhysicalComponent::getNetForce() const {
    return m_forceAccum;
}

void PhysicalComponent::setNetForce(const Vector3d &force) {
    m_forceAccum = force;
}

float PhysicalComponent::getMass() const {
    return m_mass;
}

Vector3d PhysicalComponent::getLinearSpeed() const {
    return linearSpeed;
}

void PhysicalComponent::setPosition(const Vector3d &position) {
    m_gameObject->transform.setPosition(position);
}

void PhysicalComponent::setLinearSpeed(const Vector3d &linearSpeed) {
    PhysicalComponent::linearSpeed = linearSpeed;

}

