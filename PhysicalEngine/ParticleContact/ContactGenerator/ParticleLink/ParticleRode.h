#ifndef PARTICLERODE_H
#define PARTICLERODE_H

#include "ParticleLink.h"

class ParticleRode : public ParticleLink {

private:
    float m_length;

public:
    ParticleRode(Particle *particle1, Particle *particle2, float length);

    int addContact(ParticleContact *particleContact, unsigned int limit, unsigned int current) override;
};

#endif // !PARTICLELINK_H
