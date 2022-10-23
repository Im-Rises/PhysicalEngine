#include "ParticuleContactResolver.h"

ParticuleContactResolver::ParticuleContactResolver(unsigned int maxIterations) {
	m_maxIterations = maxIterations;
}

void ParticuleContactResolver::resolveContact(ParticuleContact* particulesContacts, int size, float time) {
	if (size > 0) {
		for (unsigned int i = 0; i <= m_maxIterations; i++) {
			float minSpeed = particulesContacts[0].CalculateSeparatingVelocity();
			ParticuleContact contactToResolve=particulesContacts[0];
			for (int j = 1; j < size; j++) {
				float particuleContactSpeed = particulesContacts[j].CalculateSeparatingVelocity();
				if (particuleContactSpeed < minSpeed) {
					minSpeed = particuleContactSpeed;
					contactToResolve = particulesContacts[j];
				}
			}
			if (minSpeed >= 0) {
				return;
			}
			else {
				contactToResolve.resolve(time);
			}
		}
	}
}
