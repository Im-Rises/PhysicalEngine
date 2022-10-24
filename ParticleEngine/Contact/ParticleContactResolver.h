#ifndef PARTICULE_CONTACT_RESOLVER_H
#define PARTICULE_CONTACT_RESOLVER_H

#include "ParticleContact.h"
#include "ParticlesContactGeneratorRegistry.h"

class ParticleContactResolver {

private:
    unsigned int m_maxIterations;


public:

    explicit ParticleContactResolver(unsigned int maxIterations);


    void resolveContact(ParticleContact *particlesContacts, int size, float time,ParticleContactGeneratorRegistry registry);
};

#endif // !PARTICULE_CONTACT_RESOLVER_H
