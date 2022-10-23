#include "ParticleRode.h"

ParticleRode::ParticleRode(Particle *particle1, Particle *particle2, float length) : ParticleLink(particle1,
                                                                                                  particle2) {
    m_length = length;
}

int ParticleRode::addContact(ParticleContact *particleContact, unsigned int limit, unsigned int current) {

    float distance = m_particles[0]->getPosition().distance(m_particles[1]->getPosition());
    if (distance == m_length) {
        return current;
    }
    Vector3d normalParticle = m_particles[0]->getPosition() - m_particles[1]->getPosition();
    particleContact[current].SetParticles(m_particles);
    if (distance > m_length) {
        particleContact->setContactNormal(Vector3d(0, 0, 0) - normalParticle);
        particleContact->setPenetration(distance - m_length);
    } else {
        particleContact->setContactNormal(normalParticle);
        particleContact->setPenetration(m_length - distance);
    }
    particleContact->setElasticity(0);
    return current + 1;
}
