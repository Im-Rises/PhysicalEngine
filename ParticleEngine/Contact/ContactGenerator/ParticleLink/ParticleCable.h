#ifndef PARTICLECABLE_H
#define PARTICLECABLE_H

#include "ParticleLink.h"

class ParticleCable : public ParticleLink {

private:
    float m_maxLength;
    float m_restitution;

public:

    ParticleCable(Particle *particule1, Particle *particule2, float max_length, float restitution);

    int addContact(ParticleContact *particuleContact, unsigned int limit, unsigned int current) override;
};

#endif // !PARTICLECABLE
