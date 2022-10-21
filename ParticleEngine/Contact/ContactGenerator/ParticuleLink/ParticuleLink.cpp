#include "ParticuleLink.h"

float ParticuleLink::currentLength() const {
	m_particules[0]->getPosition().distance(m_particules[1]->getPosition());
}
