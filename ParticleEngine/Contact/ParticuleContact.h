#ifndef PARTICLE_CONTACT_H
#define PARTICLE_CONTACT_H

#include "../Scene/Components/Particule/Particule.h"
#include "ParticuleCollider/ParticuleCollider.h"

class ParticuleContact {
private:
	ParticuleCollider m_particulesCollider[2];

	float m_collision_elasticity;

	float m_penetration;

	Vector3d m_contactNormal;

	void updateAttributes();
	
	void resolveSpeed();

	void resolveInterpenetration();




public:

	ParticuleContact(ParticuleCollider particule1,ParticuleCollider particule2,float elasticity);

	void resolve(float time);

	float CalculateSeparatingVelocity();


};




#endif // !PARTICLE_CONTACT_H
