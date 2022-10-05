#include "Spring.h"

void Spring::addForce(Particule* particule, float duration) {
	float delta = otherIntegrable->distance(*particule);
	Vector3d F;
	if (delta > m_restLength) {
		Vector3d vec1 = particule->getPosition();
		Vector3d vec2 = otherIntegrable->getPosition();
		F = (vec1 - vec2).normalize()* (- m_k) * (delta - m_restLength);
	}
	Vector3d initialForce = particule->getNetForce();
	particule->setNetForce(initialForce + F);
}
