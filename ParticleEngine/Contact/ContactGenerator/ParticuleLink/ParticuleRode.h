#ifndef PARTICULERODE_H
#define PARTICULERODE_H

#include "ParticuleLink.h"

class ParticuleRode : public ParticuleLink{

	float length;


	void addContact(ParticuleContact* particuleContact, int size);
};
#endif // !PARTICULELINK_H
