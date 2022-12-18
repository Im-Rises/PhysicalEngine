#include "ParticleContactResolver.h"

ParticleContactResolver::ParticleContactResolver(unsigned int maxIterations) {
    m_maxIterations = maxIterations;
}

void ParticleContactResolver::resolveContact(ParticleContact *particlesContacts, int size, float time) {
    if (size > 0) {
        for (unsigned int i = 0; i <= m_maxIterations; i++) {
            float minSpeed = particlesContacts[0].CalculateSeparatingVelocity();
            ParticleContact contactToResolve = particlesContacts[0];
            for (int j = 1; j < size; j++) {
                float particuleContactSpeed = particlesContacts[j].CalculateSeparatingVelocity();
                if (particuleContactSpeed < minSpeed) {
                    minSpeed = particuleContactSpeed;
                    contactToResolve = particlesContacts[j];
                }
            }
            if (minSpeed >= 0) {
                return;
            } else {
                contactToResolve.resolve(time);
            }
        }
    }
}
