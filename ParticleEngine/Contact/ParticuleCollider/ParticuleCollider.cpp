#include "ParticuleCollider.h"



ParticuleCollider::ParticuleCollider(Particule* particule, float radius) {
	m_radius = radius;
	m_particule = particule;
}

float ParticuleCollider::getRadius() {
	return m_radius;
}

Particule* ParticuleCollider::getParticule() {
	return m_particule;
}
