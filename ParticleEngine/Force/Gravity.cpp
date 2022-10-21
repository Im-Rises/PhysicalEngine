#include "Gravity.h"

Gravity::Gravity() {
    m_gravity = Vector3d(0.0f, -9.81f, 0.0f);
}

Gravity::Gravity(Vector3d g) {
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
