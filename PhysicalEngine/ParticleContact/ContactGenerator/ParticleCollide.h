#ifndef PARTICLECOLLIDE_H
#define PARTICLECOLLIDE_H

#include "ParticleContactGenerator.h"

#include "../ParticleCollider/ParticleCollider.h"

#include <vector>

class ParticleCollide : public ParticleContactGenerator {

private:

    std::vector<ParticleCollider> m_colliders;

    float elasticity;

public:
    explicit ParticleCollide(float elast);

    void addCollider(ParticleCollider particleCollider);

    int addContact(ParticleContact *particleContact, unsigned int limit, unsigned int current) override;


};

#endif // !PARTICLECOLLIDE_H