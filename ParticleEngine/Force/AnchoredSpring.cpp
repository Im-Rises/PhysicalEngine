#include "AnchoredSpring.h"

AnchoredSpring::AnchoredSpring() {
    m_anchor = new Vector3d(0, 0, 0);
    m_k = 0;
    m_restLength = 0;
}

AnchoredSpring::~AnchoredSpring() {
    // delete m_anchor
}

AnchoredSpring::AnchoredSpring(Vector3d *anchor, float k, float restLength) {
    m_anchor = anchor;
    m_k = k;
    m_restLength = restLength;
}

AnchoredSpring::AnchoredSpring(const AnchoredSpring &aSpring) {
    m_anchor = aSpring.m_anchor;
    m_k = aSpring.m_k;
    m_restLength = aSpring.m_restLength;
}

void AnchoredSpring::addForce(Particle *particule, float duration) {
    Vector3d pos = particule->getPosition();
    float delta = pos.distance(*m_anchor);
    Vector3d F;
    if (delta > m_restLength) {
        F = (pos - *m_anchor).normalize() * (-m_k) * (delta - m_restLength);
    }
    Vector3d initialForce = particule->getNetForce();
    particule->setNetForce(initialForce + F);
}
