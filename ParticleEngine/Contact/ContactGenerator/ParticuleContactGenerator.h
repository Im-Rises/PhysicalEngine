#ifndef PARTICULECONTACTGENERATOR
#define PARTICULECONTACTGENERATOR

#include "../ParticuleContact.h"

class ParticuleContactGenerator {

	virtual int addContact(ParticuleContact* particuleContact,unsigned int limit,unsigned int current) const = 0;
};

#endif // !PARTICULECONTACTGENERATOR
