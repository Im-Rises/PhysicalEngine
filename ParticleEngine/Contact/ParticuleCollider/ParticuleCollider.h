#ifndef PARTICULE_COLLIDER_H
#define PARTICULE_COLLIDER_H

#include "../../Scene/Components/Particule/Particule.h"

class ParticuleCollider : Component {
	
	


	private:
	float m_radius;

	public: 
		Particule* m_particule;

	public:
	
	void drawGui();
	void update(float time);
	ParticuleCollider(Particule* particule, float radius);
	
	#pragma region Getter setter

	float getRadius();

	#pragma endregion
};

#endif // !PARTICULE_COLLIDER_H
