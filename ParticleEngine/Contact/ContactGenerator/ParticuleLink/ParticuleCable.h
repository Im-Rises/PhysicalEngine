#ifndef PARTICULECABLE_H
#define PARTICULECABLE_H

#include "ParticuleLink.h"

class ParticuleCable : public ParticuleLink {
	
	private:
	float m_maxLength;
	float m_restitution;

	public:

	ParticuleCable(Particle* particule1, Particle* particule2,float max_length,float restitution);

	int addContact(ParticuleContact* particuleContact, unsigned int limit, unsigned int current) ;
};

#endif // !PARTICULECABLE
