#ifndef PARTICULE_COLLIDER_H
#define PARTICULE_COLLIDER_H

#include "../../Scene/Components/Particule/Particule.h"

class ParticuleCollider {
	
	


	private:
	float m_radius;

	public: 
		Particule* m_particule;

	public:
	
	ParticuleCollider(Particule* particule, float radius);
	
	#pragma region Getter setter

	float getRadius();

	#pragma endregion
};

#endif // !PARTICULE_COLLIDER_H
