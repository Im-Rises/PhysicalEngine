#include "ParticleCollider.h"


ParticleCollider::ParticleCollider(Particle *particule, float radius) {
    m_radius = radius;
    m_particule = particule;
}

float ParticleCollider::getRadius() {
    return m_radius;
}

Particle *ParticleCollider::getParticule() {
    return m_particule;
}
