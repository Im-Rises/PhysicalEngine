#include "Spring.h"

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"

//Spring::Spring() {
//	m_otherParticule = new Particle(0, 0, 0, 0);
//	m_k = 0;
//	m_restLength = 0;
//}

Spring::~Spring() {
}

Spring::Spring(Particle *otherParticule, float k, float restLength) {
    m_otherParticle = otherParticule;
    m_k = k;
    m_restLength = restLength;
}

Spring::Spring(const Spring &spring) {
    m_otherParticle = spring.m_otherParticle;
    m_k = spring.m_k;
    m_restLength = spring.m_restLength;
}

void Spring::addForce(Particle *particule, float duration) {
    float delta = m_otherParticle->distance(*particule);
    Vector3d F;
    if (delta > m_restLength) {
        Vector3d vec1 = particule->getPosition();
        Vector3d vec2 = m_otherParticle->getPosition();
        F = (vec1 - vec2).normalize() * (-m_k) * (delta - m_restLength);
    }
    Vector3d initialForce = particule->getNetForce();
    particule->setNetForce(initialForce + F);
}

void Spring::drawGui() {

}

std::string Spring::getName() const {
    return SPRING_FORCE;
}
