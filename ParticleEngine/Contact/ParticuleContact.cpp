#include "ParticuleContact.h"

void ParticuleContact::updateAttributes() {
	m_contactNormal = (m_particulesCollider[0].m_particule->getPosition() - m_particulesCollider[0].m_particule->getPosition()).normalize();
	float distance = m_particulesCollider[0].m_particule->getPosition().distance(m_particulesCollider[0].m_particule->getPosition());
	m_penetration = m_particulesCollider[0].getRadius() + m_particulesCollider[0].getRadius() - distance;
}

void ParticuleContact::resolveSpeed() {
	Vector3d vrel;
	float k,m1,m2;
	m1 = m_particulesCollider[0].m_particule->getMass();
	m2 = m_particulesCollider[0].m_particule->getMass();
	vrel = m_particulesCollider[0].m_particule->getSpeed() - m_particulesCollider[0].m_particule->getSpeed();
	k = (m_collision_elasticity + 1) * (vrel.dot(m_contactNormal)) / ((1 / m1)+(1/m2));
	m_particulesCollider[0].m_particule->setSpeed(m_particulesCollider[0].m_particule->getSpeed() + m_contactNormal * (k / m1));
	m_particulesCollider[0].m_particule->setSpeed(m_particulesCollider[0].m_particule->getSpeed() - m_contactNormal * (k / m2));

}

void ParticuleContact::resolveInterpenetration() {
	if (m_penetration > 0) {
		float dp1, dp2, w1, w2;
		w1 = m_particulesCollider[0].m_particule->getMass();
		w2 = m_particulesCollider[0].m_particule->getMass();
		dp1 = (w2 / (w1 + w2)) * m_penetration;
		dp2 = -(w1 / (w1 + w2)) * m_penetration;
		Vector3d p1Pos,p2Pos;
		p1Pos = m_particulesCollider[0].m_particule->getPosition()+ m_contactNormal*dp1;
		p2Pos = m_particulesCollider[0].m_particule->getPosition() + m_contactNormal * dp2;

	}
}

ParticuleContact::ParticuleContact(ParticuleCollider particule1, ParticuleCollider particule2,float elasticity) {
	m_particulesCollider[0] = particule1;
	m_particulesCollider[1] = particule2;
	updateAttributes();
	m_collision_elasticity = elasticity;
}

void ParticuleContact::resolve(float time) {
	resolveInterpenetration();
	resolveSpeed();
}

float ParticuleContact::CalculateSeparatingVelocity() {
	return (m_particulesCollider[0].m_particule->getSpeed() - m_particulesCollider[0].m_particule->getSpeed()).dot(m_contactNormal) ;
}
