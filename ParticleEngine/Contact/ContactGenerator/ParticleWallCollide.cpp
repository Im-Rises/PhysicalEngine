#include "ParticleWallCollide.h"

void ParticleWallCollide::addParticuleCollider(ParticleCollider particleCollider) {
	m_particlesColliders.push_back(particleCollider);
}

void ParticleWallCollide::addWallCollider(WallCollider WallCollider) {
	m_WallColliders.push_back(WallCollider);
}

int ParticleWallCollide::addContact(ParticleContact* particuleContact, unsigned int limit, unsigned int current) {

	for (int wallIndice = 0; wallIndice < m_WallColliders.size(); wallIndice++) {
		for (int particleIndice = wallIndice + 1; particleIndice < m_particlesColliders.size(); particleIndice++) {
			if (current < limit) {
				ParticleCollider colPart = m_particlesColliders[particleIndice];
				WallCollider wallCollider = m_WallColliders[wallIndice];
				Particle* particle0 = m_particlesColliders[particleIndice].getParticle();
				float radius = m_particlesColliders[wallIndice].getRadius();
				if (wallCollider.isInsideWithOfset(particle0->getPosition(), radius)) {

					Vector3d maxPoint = wallCollider.getMaxDiagonalPoint() + Vector3d(radius, radius, radius);
					Vector3d minPoint = wallCollider.getMinDiagonalPoint() + Vector3d(radius, radius, radius);

				

					current += 1;
				}
			}
			else {
				return current;
			}
		}
	}
	return current;
}
