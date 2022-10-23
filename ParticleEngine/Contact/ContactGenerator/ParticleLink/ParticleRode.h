#ifndef PARTICLERODE_H
#define PARTICLERODE_H

#include "ParticleLink.h"

class ParticleRode : public ParticleLink {

private:
    float m_length;

public:

    ParticleRode(Particle *particule1, Particle *particule2, float length);

    int addContact(ParticleContact *particuleContact, unsigned int limit, unsigned int current) override;
};

#endif // !PARTICLELINK_H
