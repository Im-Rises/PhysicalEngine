#include "ParticleContact.h"


void ParticleContact::updateAttributes() {
    //m_contactNormal = (m_particules[0]->getPosition() - m_particules[1]->getPosition()).normalize();
    //float distance = m_particules[0]->getPosition().distance(m_particules[1]->getPosition());
    //m_penetration = m_particulesCollider[0].getRadius() + m_particulesCollider[0].getRadius() - distance;
}

void ParticleContact::resolveSpeed() {
    Vector3d vrel;
    float k, m1, m2;
    m1 = m_particules[0]->getMass();
    m2 = m_particules[1]->getMass();
    vrel = m_particules[0]->getLinearSpeed() - m_particules[1]->getLinearSpeed();
    k = (m_collision_elasticity + 1) * (vrel.dot(m_contactNormal)) / ((1 / m1) + (1 / m2));
    m_particules[0]->setLinearSpeed(m_particules[0]->getLinearSpeed() - m_contactNormal * (k / m1));
    m_particules[1]->setLinearSpeed(m_particules[1]->getLinearSpeed() + m_contactNormal * (k / m2));
}

void ParticleContact::resolveInterpenetration() {
    if (m_penetration > 0) {
        float dp1, dp2, w1, w2;
        w1 = m_particules[0]->getMass();
        w2 = m_particules[1]->getMass();
        dp1 = (w2 / (w1 + w2)) * m_penetration;
        dp2 = -(w1 / (w1 + w2)) * m_penetration;
        Vector3d p1Pos, p2Pos;
        p1Pos = m_particules[0]->getPosition() + m_contactNormal * dp1;
        p2Pos = m_particules[1]->getPosition() + m_contactNormal * dp2;
        m_particules[0]->setPosition(p1Pos);
        m_particules[1]->setPosition(p2Pos);

    }
}

ParticleContact::ParticleContact() {
}


void ParticleContact::setPenetration(float penetration) {
    m_penetration = penetration;
}

void ParticleContact::setElasticity(float elasticity) {
    m_collision_elasticity = elasticity;
}

void ParticleContact::setContactNormal(Vector3d const normalContact) {
    m_contactNormal = normalContact.normalize();
}

Particle **ParticleContact::GetParticles() {
    return m_particules;
}

void ParticleContact::SetParticles(Particle *particles[2]) {
    m_particules[0] = particles[0];
    m_particules[1] = particles[1];
}

void ParticleContact::SetParticles(Particle *particle1, Particle *particle2) {
    m_particules[0] = particle1;
    m_particules[1] = particle2;
}

void ParticleContact::resolve(float time) {
    resolveInterpenetration();
    resolveSpeed();
}

float ParticleContact::CalculateSeparatingVelocity() {
    return (m_particules[0]->getLinearSpeed() - m_particules[1]->getLinearSpeed()).dot(m_contactNormal);
}
