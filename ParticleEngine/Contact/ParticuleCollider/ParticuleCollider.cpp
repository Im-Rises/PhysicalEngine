#include "ParticuleCollider.h"

void ParticuleCollider::drawGui() {
}

void ParticuleCollider::update(float time) {
}

ParticuleCollider::ParticuleCollider(Particule* particule, float radius) {
	m_radius = radius;
	m_particule = particule;
}

float ParticuleCollider::getRadius() {
	return m_radius;
}
