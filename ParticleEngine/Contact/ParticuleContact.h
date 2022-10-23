#ifndef PARTICLE_CONTACT_H
#define PARTICLE_CONTACT_H

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"

class ParticuleContact {
private:
	Particle* m_particules[2];

	float m_collision_elasticity=0;

	float m_penetration=0;

	Vector3d m_contactNormal;

	void updateAttributes();
	
	void resolveSpeed();

	void resolveInterpenetration();




public:

	ParticuleContact();

	void setPenetration(float penetration);
	
	void setElasticity(float elasticity);

	void setContactNormal(Vector3d const contactNormal);

	Particle** GetParticules();

	void SetParticules(Particle* particules[2]);

	void resolve(float time);

	float CalculateSeparatingVelocity();


};




#endif // !PARTICLE_CONTACT_H
