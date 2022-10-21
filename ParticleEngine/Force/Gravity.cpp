#include "Gravity.h"

Gravity::Gravity(const Vector3d &g) {
    m_gravity = g;
}

Gravity::Gravity(const Gravity &grav) {
    m_gravity = grav.m_gravity;
}

void Gravity::addForce(Particle *particle, float duration) {
    Vector3d F = m_gravity * particle->getMass();
    Vector3d initialForce = particle->getNetForce();
    particle->setNetForce(initialForce + F);
}
