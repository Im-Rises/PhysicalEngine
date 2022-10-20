#include "Gravity.h"

Gravity::Gravity() {
    m_gravity = Vector3d(0, -9.81, 0);
}

Gravity::Gravity(Vector3d g) {
    m_gravity = g;
}

Gravity::Gravity(const Gravity &grav) {
    m_gravity = grav.m_gravity;
}

void Gravity::addForce(Particle* particule, float duration) {
	Vector3d F = m_gravity * particule->getMass();
	Vector3d initialForce = particule->getNetForce();
	particule->setNetForce(initialForce + F);
}
