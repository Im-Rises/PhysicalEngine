#include "ParticleLink.h"

float ParticleLink::currentLength() const {
    return m_particules[0]->getPosition().distance(m_particules[1]->getPosition());

}

ParticleLink::ParticleLink(Particle *particule1, Particle *particule2) {
    m_particules[0] = particule1;
    m_particules[1] = particule2;
}
