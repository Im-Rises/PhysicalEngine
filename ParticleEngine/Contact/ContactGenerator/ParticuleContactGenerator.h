#ifndef PARTICULECONTACTGENERATOR
#define PARTICULECONTACTGENERATOR

#include "../ParticuleContact.h"

class ParticuleContactGenerator {

	virtual void addContact(ParticuleContact* particuleContact, int size) const = 0;
};

#endif // !PARTICULECONTACTGENERATOR
