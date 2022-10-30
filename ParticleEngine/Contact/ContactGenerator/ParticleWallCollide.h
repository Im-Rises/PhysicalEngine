#ifndef PARTICULE_WALL_COLLIDE_H
#define PARTICULE_WALL_COLLIDE_H

#include "ParticleContactGenerator.h"
#include "ParticleCollide.h"
#include "../WallCollider/WallCollider.h"
class ParticleWallCollide : ParticleContactGenerator {


	private:

		std::vector<ParticleCollider> m_particlesColliders;
		std::vector<WallCollider> m_WallColliders;

	public:

	void addParticuleCollider(ParticleCollider particleCollider);

	void addWallCollider(WallCollider WallCollider);
	int addContact(ParticleContact* particuleContact, unsigned int limit, unsigned int current);
};
#endif // !PARTICULE_WALL_COLLIDE_H
