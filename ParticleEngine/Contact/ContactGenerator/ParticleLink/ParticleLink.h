#ifndef PARTICLELINK_H
#define PARTICLELINK_H

#include "../ParticleContactGenerator.h"

class ParticleLink : public ParticleContactGenerator {

protected:
    Particle *m_particules[2];

public:
    float currentLength() const;

    ParticleLink(Particle *particule1, Particle *particule2);

//    virtual int addContact(ParticuleContact *particuleContact, unsigned int limit, unsigned int current) = 0;


};

#endif // !ParticleLink_H
