#ifndef PARTICULECONTACTGENERATOR
#define PARTICULECONTACTGENERATOR

#include "../ParticleContact.h"

class ParticleContactGenerator {

public:
    virtual int addContact(ParticleContact *particleContact, unsigned int limit, unsigned int current) = 0;

    virtual ~ParticleContactGenerator() = default;
};


#endif // !PARTICULECONTACTGENERATOR
