#ifndef PARTICULERODE_H
#define PARTICULERODE_H

#include "ParticuleLink.h"

class ParticuleRode : public ParticuleLink{

	float length;


	int addContact(ParticuleContact* particuleContact,unsigned int limit,unsigned int current);
};
#endif // !PARTICULELINK_H
