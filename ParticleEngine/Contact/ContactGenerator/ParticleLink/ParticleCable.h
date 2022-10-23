#ifndef PARTICLECABLE_H
#define PARTICLECABLE_H

#include "ParticleLink.h"

class ParticleCable : public ParticleLink {

private:
    float m_maxLength;
    float m_restitution;

public:

    ParticleCable(Particle *particle1, Particle *particle2, float max_length, float restitution);

    int addContact(ParticleContact *particleContact, unsigned int limit, unsigned int current) override;
};

#endif // !PARTICLECABLE
