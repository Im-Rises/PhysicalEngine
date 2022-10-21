#include "Buoyancy.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"

Buoyancy::Buoyancy() {
    m_maxDepth = 0;
    m_volume = 0;
    m_waterHeight = 0;
    m_liquidDensity = 0;
}

Buoyancy::Buoyancy(float maxDepth, float volume, float waterHeight, float liquidDensity) {
    m_maxDepth = maxDepth;
    m_volume = volume;
    m_waterHeight = waterHeight;
    m_liquidDensity = liquidDensity;
}

Buoyancy::Buoyancy(const Buoyancy &buoyancy) {
    m_maxDepth = buoyancy.m_maxDepth;
    m_volume = buoyancy.m_volume;
    m_waterHeight = buoyancy.m_waterHeight;
    m_liquidDensity = buoyancy.m_liquidDensity;
}

void Buoyancy::addForce(Particle *particle, float duration) {
    float d = (particle->getPosition().gety() - m_waterHeight - m_maxDepth) / 2 * m_maxDepth;
    float f;
    if (d <= 0) {
        f = 0;
    } else if (d >= 1) {
        f = m_volume * m_liquidDensity;
    } else {
        f = d * m_volume * m_liquidDensity;
    }
    float initialFriction = particle->getFriction();
    particle->setFriction(initialFriction + f);
}
