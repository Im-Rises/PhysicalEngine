#include "ParticuleRode.h"

int ParticuleRode::addContact(ParticuleContact* particuleContact, unsigned int limit, unsigned int current) {

	float distance = m_particules[0]->getPosition().distance(m_particules[1]->getPosition());
	if (distance == length) {
		return current;
	}
	Vector3d normalParticule = m_particules[0]->getPosition()-m_particules[1]->getPosition();
	particuleContact[current].SetParticules(m_particules);
	if (distance > length) {
		particuleContact->setContactNormal(Vector3d(0,0,0)-normalParticule);
		particuleContact->setPenetration(distance - length);
	}
	else {
		particuleContact->setContactNormal(normalParticule);
		particuleContact->setPenetration(length- distance);
	}
	particuleContact->setElasticity(0);
	return current + 1;
}
