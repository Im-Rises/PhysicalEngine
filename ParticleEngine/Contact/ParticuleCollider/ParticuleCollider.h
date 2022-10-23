#ifndef PARTICULE_COLLIDER_H
#define PARTICULE_COLLIDER_H

#include "../../Scene/Components/PhysicalComponent/Particle/Particle.h"

class ParticuleCollider {
	
	


	private:
	float m_radius;
	Particle* m_particule;

	public:
	
	ParticuleCollider(Particle* particule, float radius);
	
	#pragma region Getter setter

	float getRadius();

	Particle* getParticule();

	#pragma endregion
};

#endif // !PARTICULE_COLLIDER_H
