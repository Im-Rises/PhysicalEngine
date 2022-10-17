#include "Spring.h"

Spring::Spring() {
	m_otherParticule = new Particule(0, 0, 0, 0);
	m_k = 0;
	m_restLength = 0;
}

Spring::~Spring() {
}

Spring::Spring(Particule* otherParticule, float k, float restLength) {
	m_otherParticule = otherParticule;
	m_k = k;
	m_restLength = restLength;
}

Spring::Spring(const Spring& spring) {
	m_otherParticule = spring.m_otherParticule;
	m_k = spring.m_k;
	m_restLength = spring.m_restLength;
}

void Spring::addForce(Particule* particule, float duration) {
	float delta = m_otherParticule->distance(*particule);
	Vector3d F;
	if (delta > m_restLength) {
		Vector3d vec1 = particule->getPosition();
		Vector3d vec2 = m_otherParticule->getPosition();
		F = (vec1 - vec2).normalize()* (- m_k) * (delta - m_restLength);
	}
	Vector3d initialForce = particule->getNetForce();
	particule->setNetForce(initialForce + F);
}
