#include "ParticuleContact.h"


void ParticuleContact::updateAttributes() {
	//m_contactNormal = (m_particules[0]->getPosition() - m_particules[1]->getPosition()).normalize();
	//float distance = m_particules[0]->getPosition().distance(m_particules[1]->getPosition());
	//m_penetration = m_particulesCollider[0].getRadius() + m_particulesCollider[0].getRadius() - distance;
}

void ParticuleContact::resolveSpeed() {
	Vector3d vrel;
	float k,m1,m2;
	m1 = m_particules[0]->getMass();
	m2 = m_particules[0]->getMass();
	vrel = m_particules[0]->getSpeed() - m_particules[1]->getSpeed();
	k = (m_collision_elasticity + 1) * (vrel.dot(m_contactNormal)) / ((1 / m1)+(1/m2));
	m_particules[0]->setSpeed(m_particules[0]->getSpeed() + m_contactNormal * (k / m1));
	m_particules[1]->setSpeed(m_particules[1]->getSpeed() - m_contactNormal * (k / m2));

}

void ParticuleContact::resolveInterpenetration() {
	if (m_penetration > 0) {
		float dp1, dp2, w1, w2;
		w1 = m_particules[0]->getMass();
		w2 = m_particules[0]->getMass();
		dp1 = (w2 / (w1 + w2)) * m_penetration;
		dp2 = -(w1 / (w1 + w2)) * m_penetration;
		Vector3d p1Pos,p2Pos;
		p1Pos = m_particules[0]->getPosition()+ m_contactNormal*dp1;
		p2Pos = m_particules[0]->getPosition() + m_contactNormal * dp2;

	}
}

ParticuleContact::ParticuleContact() {
}



void ParticuleContact::setPenetration(float penetration) {
	m_penetration = penetration;
}

void ParticuleContact::setElasticity(float elasticity) {
	m_collision_elasticity = elasticity;
}

void ParticuleContact::setContactNormal(Vector3d const contactNormal) {
	m_contactNormal = contactNormal;
}

Particle** ParticuleContact::GetParticules() {
	return m_particules;
}

void ParticuleContact::SetParticules(Particle* particules[2]) {
	m_particules[0] = particules[0];
	m_particules[1] = particules[1];
}

void ParticuleContact::resolve(float time) {
	resolveInterpenetration();
	resolveSpeed();
}

float ParticuleContact::CalculateSeparatingVelocity() {
	return (m_particules[0]->getSpeed() - m_particules[1]->getSpeed()).dot(m_contactNormal) ;
}
