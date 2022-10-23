#ifndef PARTICULE_COLLIDER_H
#define PARTICULE_COLLIDER_H

#include "../../Scene/Components/Particule/Particule.h"

class ParticuleCollider {
	
	


	private:
	float m_radius;
	Particule* m_particule;

	public:
	
	ParticuleCollider(Particule* particule, float radius);
	
	#pragma region Getter setter

	float getRadius();

	Particule* getParticule();

	#pragma endregion
};

#endif // !PARTICULE_COLLIDER_H
