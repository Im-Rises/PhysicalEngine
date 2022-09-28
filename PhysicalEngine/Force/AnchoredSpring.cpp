#include "AnchoredSpring.h"

void AnchoredSpring::updateForce(Particule* particule, float duration) {
	Vector3d pos = particule->getPosition();
	float delta = pos.distance(*m_anchor);
	Vector3d F;
	if (delta > m_restLength) {
		 F = (pos - *m_anchor).normalize() * (-m_k) * (delta - m_restLength);
	}
}
