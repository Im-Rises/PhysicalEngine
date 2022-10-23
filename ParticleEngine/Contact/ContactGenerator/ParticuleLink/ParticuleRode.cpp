#include "ParticuleRode.h"

ParticuleRode::ParticuleRode(Particle* particule1, Particle* particule2, float length) : ParticuleLink(particule1,particule2) {
	m_length=length;
}

int ParticuleRode::addContact(ParticuleContact* particuleContact, unsigned int limit, unsigned int current){

	float distance = m_particules[0]->getPosition().distance(m_particules[1]->getPosition());
	if (distance == m_length) {
		return current;
	}
	Vector3d normalParticule = m_particules[0]->getPosition()-m_particules[1]->getPosition();
	particuleContact[current].SetParticules(m_particules);
	if (distance > m_length) {
		particuleContact->setContactNormal(Vector3d(0,0,0)-normalParticule);
		particuleContact->setPenetration(distance - m_length);
	}
	else {
		particuleContact->setContactNormal(normalParticule);
		particuleContact->setPenetration(m_length- distance);
	}
	particuleContact->setElasticity(0);
	return current + 1;
}
