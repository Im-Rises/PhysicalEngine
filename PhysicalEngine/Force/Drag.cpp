#include "Drag.h"

Drag::Drag() {
	m_k1 = 0;
	m_k2 = 0;
}

Drag::Drag(float k1, float k2) {
	m_k1 = k1;
	m_k2 = k2;
}

Drag::Drag(const Drag& drag) {
	m_k1 = drag.m_k1;
	m_k2 = drag.m_k2;
}

void Drag::addForce(Particule* particule, float duration) {
	Vector3d vit = particule->getSpeed();
	Vector3d F = vit.normalize()* (-1) * (m_k1 * vit.norm() + m_k2 * vit.norm() * vit.norm());
	Vector3d initialForce = particule->getNetForce();
	particule->setNetForce(initialForce + F);
}
