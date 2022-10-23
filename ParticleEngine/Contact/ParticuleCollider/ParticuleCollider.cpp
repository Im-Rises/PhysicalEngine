#include "ParticuleCollider.h"



ParticuleCollider::ParticuleCollider(Particle* particule, float radius) {
	m_radius = radius;
	m_particule = particule;
}

float ParticuleCollider::getRadius() {
	return m_radius;
}

Particle* ParticuleCollider::getParticule() {
	return m_particule;
}
