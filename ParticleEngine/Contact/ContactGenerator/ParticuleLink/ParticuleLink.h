#ifndef PARTICULELINK_H
#define PARTICULELINK_H

#include "../ParticuleContactGenerator.h"

class ParticuleLink : public ParticuleContactGenerator {
	
	protected:
	Particle* m_particules[2];

	public:
	float currentLength() const;

	ParticuleLink(Particle* particule1, Particle* particule2);

	virtual int addContact(ParticuleContact* particuleContact, unsigned int limit, unsigned int current)  = 0;



};
#endif // !ParticuleLink_H
