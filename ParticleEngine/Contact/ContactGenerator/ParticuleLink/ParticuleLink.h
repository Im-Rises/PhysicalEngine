#ifndef PARTICULELINK_H
#define PARTICULELINK_H

#include "../ParticuleContactGenerator.h"

class ParticuleLink : public ParticuleContactGenerator {
	
	protected:
	Particule* m_particules[2];

	public:
	float currentLength() const;

	ParticuleLink(Particule* particule1, Particule* particule2);

	virtual int addContact(ParticuleContact* particuleContact, unsigned int limit, unsigned int current)  = 0;



};
#endif // !ParticuleLink_H
