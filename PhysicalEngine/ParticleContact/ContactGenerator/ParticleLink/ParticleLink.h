#ifndef PARTICLELINK_H
#define PARTICLELINK_H

#include "../ParticleContactGenerator.h"

class ParticleLink : public ParticleContactGenerator {

protected:
    Particle *m_particles[2];

public:
    float currentLength() const;

    ParticleLink(Particle *particle1, Particle *particle2);

//    virtual int addContact(ParticleContact *particleContact, unsigned int limit, unsigned int current) = 0;


};

#endif // !ParticleLink_H
