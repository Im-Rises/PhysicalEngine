#include "ParticleCable.h"

ParticleCable::ParticleCable(Particle *particule1, Particle *particule2, float max_length, float restitution)
        : ParticleLink(particule1, particule2) {
    m_maxLength = max_length;
    m_restitution = restitution;
}

int ParticleCable::addContact(ParticleContact *particuleContact, unsigned int limit, unsigned int current) {
    float distance = m_particules[0]->getPosition().distance(m_particules[1]->getPosition());
    Vector3d normalParticule = m_particules[0]->getPosition() - m_particules[1]->getPosition();
    if (distance <= m_maxLength) {
        return current;
    } else {
        particuleContact[current].SetParticles(m_particules);
        particuleContact[current].setContactNormal(Vector3d(0, 0, 0) - normalParticule);
        particuleContact[current].setPenetration(distance - m_maxLength);
        particuleContact[current].setElasticity(0);
        return current + 1;
    }

}
