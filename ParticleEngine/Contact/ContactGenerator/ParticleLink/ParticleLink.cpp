#include "ParticleLink.h"

float ParticleLink::currentLength() const {
    return m_particles[0]->getPosition().distance(m_particles[1]->getPosition());

}

ParticleLink::ParticleLink(Particle *particle1, Particle *particle2) {
    m_particles[0] = particle1;
    m_particles[1] = particle2;
}
