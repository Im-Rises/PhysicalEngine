#include "ParticleCollider.h"


ParticleCollider::ParticleCollider(Particle* particle, float radius) {
    m_radius = radius;
    m_particle = particle;
}

float ParticleCollider::getRadius() const {
    return m_radius;
}

Particle* ParticleCollider::getParticle() {
    return m_particle;
}
