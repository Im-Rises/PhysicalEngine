#ifndef PARTICULECONTACTGENERATOR
#define PARTICULECONTACTGENERATOR

#include "../ParticleContact.h"

class ParticleContactGenerator {

public:
    virtual int addContact(ParticleContact *particuleContact, unsigned int limit, unsigned int current) = 0;
};

#endif // !PARTICULECONTACTGENERATOR
