#include "Gravity.h"

void Gravity::addForce(Particule* particule, float duration) {
	Vector3d F = m_gravity*particule->getMass();
	Vector3d initialForce = particule->getNetForce();
	particule->setNetForce(initialForce + F);
}
