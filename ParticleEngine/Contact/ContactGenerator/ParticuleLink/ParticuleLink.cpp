#include "ParticuleLink.h"

float ParticuleLink::currentLength() const {
	return m_particules[0]->getPosition().distance(m_particules[1]->getPosition());
	
}

ParticuleLink::ParticuleLink(Particule* particule1, Particule* particule2) {
	m_particules[0] = particule1;
	m_particules[1] = particule2;
}
