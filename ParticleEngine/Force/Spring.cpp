#include "Spring.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"

//Spring::Spring() {
//	m_otherParticule = new Particle(0, 0, 0, 0);
//	m_k = 0;
//	m_restLength = 0;
//}

Spring::~Spring() {
}

Spring::Spring(Particle *otherParticle, float k, float restLength) {
    m_otherParticle = otherParticle;
    m_k = k;
    m_restLength = restLength;
}

Spring::Spring(const Spring &spring) {
    m_otherParticle = spring.m_otherParticle;
    m_k = spring.m_k;
    m_restLength = spring.m_restLength;
}

void Spring::addForce(Particle *particle, float duration) {
    float delta = m_otherParticle->distance(*particle);
    Vector3d F;
    if (delta > m_restLength) {
        Vector3d vec1 = particle->getPosition();
        Vector3d vec2 = m_otherParticle->getPosition();
        F = (vec1 - vec2).normalize() * (-m_k) * (delta - m_restLength);
    }
    Vector3d initialForce = particle->getNetForce();
    particle->setNetForce(initialForce + F);
}

void Spring::drawGui() {

}

std::string Spring::getName() const {
    return SPRING_FORCE;
}
