#ifndef PARTICULELINK_H
#define PARTICULELINK_H

#include "../ParticuleContactGenerator.h"

class ParticuleLink : public ParticuleContactGenerator {
	
	private:
	Particule* particules[2];

	public:
	float currentLength() const;


	virtual void addContact(ParticuleContact* particuleContact, int size);



};
#endif // !ParticuleLink_H
