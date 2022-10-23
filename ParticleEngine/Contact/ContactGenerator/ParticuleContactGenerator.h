#ifndef PARTICULECONTACTGENERATOR
#define PARTICULECONTACTGENERATOR

#include "../ParticuleContact.h"

class ParticuleContactGenerator {

	public:
	virtual int addContact(ParticuleContact* particuleContact,unsigned int limit,unsigned int current) = 0;
};

#endif // !PARTICULECONTACTGENERATOR
