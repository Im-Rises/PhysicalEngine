#include "AnchoredSpring.h"

void AnchoredSpring::addForce(Particule* particule, float duration) {
	Vector3d pos = particule->getPosition();
	float delta = pos.distance(*m_anchor);
	Vector3d F;
	if (delta > m_restLength) {
		 F = (pos - *m_anchor).normalize() * (-m_k) * (delta - m_restLength);
	}
	Vector3d initialForce = particule->getNetForce();
	particule->setNetForce(initialForce + F);
}
