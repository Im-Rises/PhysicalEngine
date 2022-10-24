#include "ParticleCable.h"

ParticleCable::ParticleCable(Particle *particle1, Particle *particle2, float max_length, float restitution)
        : ParticleLink(particle1, particle2) {
    m_maxLength = max_length;
    m_restitution = restitution;
}

int ParticleCable::addContact(ParticleContact *particleContact, unsigned int limit, unsigned int current) {
    float distance = m_particles[0]->getPosition().distance(m_particles[1]->getPosition());
    Vector3d normalParticle = m_particles[0]->getPosition() - m_particles[1]->getPosition();
    if (distance <= m_maxLength) {
        return current;
    } else {
        particleContact[current].SetParticles(m_particles);
        particleContact[current].setContactNormal(Vector3d(0, 0, 0) - normalParticle);
        particleContact[current].setPenetration(distance - m_maxLength);
        particleContact[current].setElasticity(0);
        return current + 1;
    }

}
